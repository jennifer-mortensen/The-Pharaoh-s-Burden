#pragma once
#include "types.h"
#include <map>
#include <string>

class Room {
public:
	std::string id;
	std::string name;
	std::string description;
	std::map <Direction, Room*> exits;

	Room(std::string id, std::string name, std::string description);
	void printDescription();
};