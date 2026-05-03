/**
 * @file types.h
 * @brief Shared types, enums, and parsing utilities.
 */

#pragma once
#include <string>

 // ============================================================
 // Enums
 // ============================================================

 /**
  * @brief Cardinal directions for room navigation.
  * @details None is returned when input cannot be parsed as a valid direction.
  */
enum class Direction { North, South, East, West, None };

// ============================================================
// Public Methods
// ============================================================

/**
 * @brief Parses a string input into a Direction enum value.
 * @param input Player input string, e.g. "n", "north".
 * @return The corresponding Direction, or Direction::None if unrecognized.
 */
Direction parse_direction(std::string input);