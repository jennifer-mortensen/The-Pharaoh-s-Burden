/**
 * @file player.h
 * @brief Defines the Player class representing the player's state in the game world.
 */

#pragma once
#include "room.h"

// ============================================================
// Classes
// ============================================================

/**
 * @brief Represents the player, tracking their current position in the game world.
 */
class Player
{
public:
    Room* current_room; ///< Pointer to the room the player is currently in.

    /**
     * @brief Constructs a Player starting in the given room.
     * @param startingRoom Pointer to the room the player begins in.
     */
    Player(Room* starting_room);
};