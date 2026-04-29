#include "room.h"
#include <iostream>

Room::Room(std::string id, std::string name, std::string description)
	: id(id), name(name), description(description) {}

void Room::printDescription() {
	std::cout << "\033[36m" << name << "\033[0m" << "\n" << "\033[33m" << wordWrap(description) << "\033[0m" << "\n\n";
}