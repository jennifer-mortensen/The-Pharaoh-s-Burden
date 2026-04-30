/**
 * @file game.h
 * @brief Defines the Game class, the top-level controller for the game loop.
 */

#pragma once
#include <map>
#include <string>
#include "player.h"

// ============================================================
// Classes
// ============================================================

/**
 * @brief Top-level game controller responsible for managing state,
 *        rooms, and the main game loop.
 */
class Game
{
public:
    Player player;                       ///< The player object tracking current state.
    std::map<std::string, Room*> rooms;  ///< All rooms in the game, keyed by room id.

    /**
     * @brief Constructs the Game, initializes rooms and player starting position.
     */
    Game();

    /**
     * @brief Starts and runs the main game loop.
     */
    void run();

    /**
     * @brief Parses and handles a single line of player input.
     * @param input Raw input string from the player.
     */
    void handleInput(std::string input);
private:
    /**
     * @brief Prints the game title, copyright, and version information to the console.
     */
    void printHeader();
    /**
     * @brief Instantiates all rooms and connects their exits.
     * @return Pointer to the starting room.
     */
    Room* generateRooms();
};