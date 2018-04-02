#pragma once
#include <winsock2.h>
#include <Windows.h>
#include "ClientNetwork.h"
#include "NetworkData.h"
#include "misc.h"

class ClientGame
{
public:
	ClientGame(void);
	~ClientGame(void);

	ClientNetwork* network;

	void sendActionPackets();

    char network_data[MAX_PACKET_SIZE];

    void update(Player2_Data data);

	void sendPlayer2Data(Player2_Data data);
	void ClientGame::sendGameOver(bool WL);
	// Information from server game
	Player1_Data player1_data;

	bool start = false;
};

