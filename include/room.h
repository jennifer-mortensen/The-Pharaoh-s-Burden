/**
 * @file room.h
 * @brief Defines the Room class representing a single location in the game world.
 */

#pragma once
#include <map>
#include <string>
#include "exit.h"
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
    std::string id;                                ///< Unique identifier for this room.
    std::string name;                              ///< Display name shown to the player.
    std::string description;                       ///< Full description printed when the room is entered.
    std::string glimpse;                           ///< Fallback description when viewed from an adjacent room.
    std::map<Direction, Exit*> exits;              ///< Map of available exits to adjacent rooms.
    std::map<Direction, std::string> glimpse_map;  ///< Map that defines what it seen from adjacent rooms in each direction.

    /**
     * @brief Constructs a Room with the given id, name, and description.
     * @param id Unique identifier for this room.
     * @param name Display name shown to the player.
     * @param description Full description printed when the room is entered.
     */
    Room(std::string id, std::string name, std::string description, std::string glimpse = "", 
        std::map<Direction, std::string> glimpse_map = {});

    /**
     * @brief Returns a glimpse description of this room from a given direction.
     * @details Checks the glimpse map for a direction-specific description first.
     *          Falls back to the generic glimpse string, then the room name.
     * @param glimpse_direction The direction from which the room is being viewed.
     * @return A short description of the room as seen from the given direction.
     */
    std::string glimpse_room(Direction glimpse_toward);

    /**
     * @brief Prints the room's name, description, and glimpses of adjacent exits
     * to the console.
     */
    void print_room();
private:
    /**
     * @brief Prints the room's description to the console.
     */
    void print_description();
    /**
     * @brief Prints the room's name to the console.
     */
    void print_name();
    /**
     * @brief Prints glimpses of adjacent exists to the console.
     */
    void print_exits();
};