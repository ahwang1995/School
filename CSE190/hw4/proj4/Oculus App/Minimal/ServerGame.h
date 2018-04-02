#pragma once
#include "ServerNetwork.h"
#include "NetworkData.h"
#include "misc.h"

class ServerGame
{

public:

    ServerGame(void);
    ~ServerGame(void);

    void update(Player1_Data data);

	void receiveFromClients(Player1_Data data);

	void sendActionPackets();

	void sendPlayer1Data(Player1_Data data);

	// Information from server game
	Player2_Data player2_data;

	bool player2_connected = false;
	bool win = false;
	bool lose = false;

	void sendStart();

private:

   // IDs for the clients connecting for table in ServerNetwork 
    static unsigned int client_id;

   // The ServerNetwork object 
    ServerNetwork* network;

	// data buffer
   char network_data[MAX_PACKET_SIZE];
};