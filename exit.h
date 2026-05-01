/**
 * @file exit.h
 * @brief Defines the Exit class representing a directional passage between rooms.
 */

#pragma once
#include <string>
class Room;
#include "types.h"

// ============================================================
// Classes
// ============================================================

/**
 * @brief Represents a directional exit leading from one room to another.
 * @details Each exit optionally carries its own glimpse description. If absent,
 *          the destination room is queried for its own glimpse data.
 */
class Exit
{
public:
    Room* destination;   ///< Pointer to the room this exit leads to.
    std::string glimpse; ///< Optional glimpse description for this specific exit.

    /**
     * @brief Constructs an Exit to the given destination with an optional glimpse.
     * @param destination Pointer to the destination room.
     * @param glimpse Optional short description of what lies in this direction.
     */
    Exit(Room* destination, std::string glimpse = "");

    /**
     * @brief Returns a glimpse description for this exit.
     * @details Returns the exit's own glimpse if defined, otherwise delegates
     *          to the destination room's glimpse_room function.
     * @param glimpse_toward The direction the player is looking.
     * @return A short description of what lies in this direction.
     */
    std::string glimpse_exit(Direction glimpse_toward);
};