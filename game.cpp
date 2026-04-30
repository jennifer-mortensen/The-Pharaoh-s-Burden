#include <iostream>
#include "game.h"
#include "room.h"
#include "theme.h"
#include "types.h"
#include "utils.h"

// ============================================================
// Constants
// ============================================================
namespace
{
    const std::string GAME_TITLE     = "Historia: The Pharaoh's Burden";
    const std::string GAME_COPYRIGHT = "Copyright (c) 2026 Jennifer M.";
    const std::string GAME_VERSION   = "v0.1 (Pre-Alpha)";
}

// ============================================================
// Constructors
// ============================================================
Game::Game() : player(nullptr) 
{
    std::cout << ansi::COLOR_RESET;
    print_header();
    player.current_room = generate_rooms();
}

// ============================================================
// Public Methods
// ============================================================
void Game::run()
{
	player.current_room->print_description();

	std::string input;

	while (true)
    {
        std::cout << theme::COLOR_PLAYER_INPUT << "> ";
		std::getline(std::cin, input);
        std::cout << ansi::COLOR_RESET << "\n";
		handle_input(input);
	}
}

void Game::handle_input(std::string input)
{
    Direction dir = parse_direction(input);
    if (dir == Direction::None)
    {
        std::cout << style_text("I don't understand that.", theme::COLOR_PARSER_ERROR, theme::STYLE_PARSER_ERROR) << "\n\n";
        return;
    }
    auto& exits = player.current_room->exits;
    if (exits.count(dir))
    {
        player.current_room = exits[dir];
        player.current_room->print_description();
    }
    else
    {
        std::cout << style_text("You can't go that way.", theme::COLOR_PARSER_REPLY, theme::STYLE_PARSER_REPLY) << "\n\n";
    }
}

// ============================================================
// Private Methods
// ============================================================
void Game::print_header()
{
    std::cout << style_text(GAME_TITLE, theme::COLOR_TITLE, theme::STYLE_TITLE) << "\n"
        << style_text(GAME_COPYRIGHT, theme::COLOR_SUBTITLE, theme::STYLE_SUBTITLE)
        << "\n" << style_text(GAME_VERSION, theme::COLOR_SUBTITLE, theme::STYLE_SUBTITLE) << "\n\n";
}

Room* Game::generate_rooms()
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