#pragma once
#include "player.h"
#include <map>
#include <string>

class Game {
public:
	Player player;
	std::map<std::string, Room*> rooms;
	
	Game();
	void run();
	void handleInput(std::string input);
};