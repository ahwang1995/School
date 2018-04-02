#include "StdAfx.h"
#include "ServerGame.h"

unsigned int ServerGame::client_id; 
ServerGame::ServerGame(void)
{
    // id's to assign clients for our table
    client_id = 0;

    // set up the server network to listen 
    network = new ServerNetwork(); 

	printf("packet size: %d\n", sizeof(Packet));
}

ServerGame::~ServerGame(void)
{
}

void ServerGame::update(Player1_Data data)
{
    // get new clients
   if(network->acceptNewClient(client_id))
   {
        printf("client %d has been connected to the server\n",client_id);

        client_id++;
   }

   receiveFromClients(data);
}

void ServerGame::receiveFromClients(Player1_Data data)
{

    Packet packet;

    // go through all clients
    std::map<unsigned int, SOCKET>::iterator iter;

    for(iter = network->sessions.begin(); iter != network->sessions.end(); iter++)
    {
        int data_length = network->receiveData(iter->first, network_data);

        if (data_length <= 0) 
        {
            //no data recieved
            continue;
        }

        int i = 0;
        while (i < (unsigned int)data_length) 
        {
            packet.deserialize(&(network_data[i]));
            i += sizeof(Packet);

            switch (packet.packet_type) {

                case INIT_CONNECTION:

                    printf("server received init packet from client\n");

					player2_connected = true;

					sendPlayer1Data(data);

                    break;

				case PLAYER2_DATA:

					player2_data = packet.player2_data;

					sendPlayer1Data(data);

					break;
				case WIN:
					win = true;
					break;

				case LOSE:
					lose = true;
					break;

                default:

                    printf("error in packet types\n");

                    break;
            }
        }
    }
}


void ServerGame::sendActionPackets()
{
    // send action packet
    const unsigned int packet_size = sizeof(Packet);
    char packet_data[packet_size];

    Packet packet;
    packet.packet_type = ACTION_EVENT;

    packet.serialize(packet_data);

    network->sendToAll(packet_data,packet_size);
}

void ServerGame::sendPlayer1Data(Player1_Data data)
{
	// send action packet
	const unsigned int packet_size = sizeof(Packet);
	char packet_data[packet_size];

	Packet packet;
	packet.packet_type = PLAYER1_DATA;

	packet.player1_data = data;

	packet.serialize(packet_data);

	network->sendToAll(packet_data, packet_size);
}


void ServerGame::sendStart()
{
	// send action packet
	const unsigned int packet_size = sizeof(Packet);
	char packet_data[packet_size];
	Packet packet;
	packet.packet_type = START;

	packet.serialize(packet_data);

	network->sendToAll(packet_data, packet_size);
}
