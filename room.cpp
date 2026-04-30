#include <iostream>
#include "room.h"
#include "theme.h"
#include "utils.h"

// ============================================================
// Constructors
// ============================================================
Room::Room(std::string id, std::string name, std::string description)
	: id(id), name(name), description(description) {}

// ============================================================
// Public Methods
// ============================================================
void Room::print_description()
{
	std::cout << style_text(name, theme::COLOR_ROOM_NAME) << "\n" << style_text(description, theme::COLOR_ROOM_DESCRIPTION) << "\n\n";
}