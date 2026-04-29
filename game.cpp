#include "game.h"
#include "room.h"
#include "types.h"
#include <iostream>

Game::Game() : player(nullptr) {
    std::cout << "Historia: The Pharaoh's Burden\nCopyright (c) 2026 Jennifer M. All rights reserved.\nVersion 0.1 (Pre-Alpha)\n\n";

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

    player.currentRoom = desert;
}

void Game::run() {
	player.currentRoom->printDescription();

	std::string input;

	while (true) {
		std::getline(std::cin, input);
        std::cout << "\n";
		handleInput(input);
	}
}

void Game::handleInput(std::string input) {
    Direction dir = parseDirection(input);
    if (dir == Direction::None) {
        std::cout << "\033[33m" << "I don't understand that.\n\n" << "\033[0m";
        return;
    }
    auto& exits = player.currentRoom->exits;
    if (exits.count(dir)) {
        player.currentRoom = exits[dir];
        player.currentRoom->printDescription();
    }
    else {
        std::cout << "\033[33m" << "You can't go that way.\n\n" << "\033[0m";
    }
}