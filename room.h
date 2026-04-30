/**
 * @file room.h
 * @brief Defines the Room class representing a single location in the game world.
 */

#pragma once
#include <map>
#include <string>
#include "types.h"

// ============================================================
// Classes
// ============================================================

/**
 * @brief Represents a single navigable location in the game world.
 * @details Each room has a unique identifier, a display name, a description,
 *          and a map of exits linking it to adjacent rooms.
 */
class Room
{
public:
    std::string id;                   ///< Unique identifier for this room.
    std::string name;                 ///< Display name shown to the player.
    std::string description;          ///< Full description printed when the room is entered.
    std::map<Direction, Room*> exits; ///< Map of available exits to adjacent rooms.

    /**
     * @brief Constructs a Room with the given id, name, and description.
     * @param id Unique identifier for this room.
     * @param name Display name shown to the player.
     * @param description Full description printed when the room is entered.
     */
    Room(std::string id, std::string name, std::string description);

    /**
     * @brief Prints the room's name and description to the console.
     */
    void print_description();
};