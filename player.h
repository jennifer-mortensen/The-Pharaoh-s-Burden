#pragma once
#include "room.h"

class Player {
public:
	Room* currentRoom;

	Player(Room* startingRoom);
};