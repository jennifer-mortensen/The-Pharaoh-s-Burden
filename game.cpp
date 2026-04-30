#include <iostream>
#include "game.h"
#include "room.h"
#include "types.h"
#include "utils.h"

// ============================================================
// Constructors
// ============================================================
Game::Game() : player(nullptr) 
{
    std::cout << COLOR_RESET;
    printHeader();
    player.currentRoom = generateRooms();
}

// ============================================================
// Public Methods
// ============================================================
void Game::run()
{
	player.currentRoom->printDescription();

	std::string input;

	while (true)
    {
        std::cout << COLOR_PLAYER_INPUT << "> ";
		std::getline(std::cin, input);
        std::cout << COLOR_RESET << "\n";
		handleInput(input);
	}
}

void Game::handleInput(std::string input)
{
    Direction dir = parseDirection(input);
    if (dir == Direction::None)
    {
        std::cout << styleText("I don't understand that.", COLOR_PARSER_ERROR, STYLE_PARSER_ERROR) << "\n\n";
        return;
    }
    auto& exits = player.currentRoom->exits;
    if (exits.count(dir))
    {
        player.currentRoom = exits[dir];
        player.currentRoom->printDescription();
    }
    else
    {
        std::cout << styleText("You can't go that way.", COLOR_PARSER_REPLY, STYLE_PARSER_REPLY) << "\n\n";
    }
}

// ============================================================
// Private Methods
// ============================================================
void Game::printHeader()
{
    std::cout << styleText("Historia: The Pharaoh's Burden", COLOR_TITLE, STYLE_TITLE) << "\n"
        << styleText("Copyright (c) 2026 Jennifer M. All rights reserved.", COLOR_SUBTITLE, STYLE_SUBTITLE)
        << "\n" << styleText("Version 0.1 (Pre-Alpha)", COLOR_SUBTITLE, STYLE_SUBTITLE) << "\n\n";
}

Room* Game::generateRooms()
{
    Room* desert = new Room("desert", "The Desert", "You are standing in a vast desert. The sun beats down mercilessly. You see something remarkably queer to the north. A pyramid lies south.");
    Room* pyramid = new Room("pyramid", "Pyramid Entrance", "You stand before the entrance to an ancient pyramid. The stone is worn smooth by centuries of sand. A vast desert lies to the north.");
    Room* queer = new Room("queer", "Day's Room", "Day stands gayly before you. What is he even doing here? Quickly, escape to the south!");

    desert->exits[Direction::North] = queer;
    desert->exits[Direction::South] = pyramid;
    pyramid->exits[Direction::North] = desert;
    queer->exits[Direction::South] = desert;

    rooms["desert"] = desert;
    rooms["pyramid"] = pyramid;
    rooms["queer"] = queer;

    return desert;
}