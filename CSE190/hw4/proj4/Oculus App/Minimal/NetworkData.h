#pragma once
#include <string.h>
#include "misc.h"

#define MAX_PACKET_SIZE 1000000

enum PacketTypes {

	INIT_CONNECTION,

	ACTION_EVENT,

	PLAYER1_DATA,

	PLAYER2_DATA,

	WIN,

	LOSE,

	START

};

struct Packet {

	unsigned int packet_type;
	
	Player1_Data player1_data;
	Player2_Data player2_data;

	void serialize(char * data) {
		memcpy(data, this, sizeof(Packet));
	}

	void deserialize(char * data) {
		memcpy(this, data, sizeof(Packet));
	}
};