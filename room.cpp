#include <iostream>
#include "room.h"
#include "utils.h"

// ============================================================
// Constructors
// ============================================================
Room::Room(std::string id, std::string name, std::string description)
	: id(id), name(name), description(description) {}

// ============================================================
// Public Methods
// ============================================================
void Room::printDescription()
{
	std::cout << styleText(name, COLOR_ROOM_NAME) << "\n" << styleText(description, COLOR_ROOM_DESCRIPTION) << "\n\n";
}