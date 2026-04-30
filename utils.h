/**
 * @file utils.h
 * @brief General purpose utility functions.
 */

#pragma once
#include <string>
#include "styles.h"

// ============================================================
// Constants
// ============================================================
const int DEFAULT_WRAP_WIDTH             = 100;                          ///< Default line wrap width in characters.

const std::string COLOR_PARSER_ERROR     = COLOR_BRIGHT_YELLOW;          ///< Parser response color on error (e.g. invalid command, invalid movement).
const std::string COLOR_PARSER_REPLY     = COLOR_BRIGHT_YELLOW;          ///< Standard parser response color.
const std::string COLOR_PLAYER_INPUT     = COLOR_BRIGHT_CYAN;            ///< Color of player command input.
const std::string COLOR_ROOM_DESCRIPTION = COLOR_BRIGHT_YELLOW;          ///< Room description color.
const std::string COLOR_ROOM_NAME        = COLOR_YELLOW;                 ///< Room name color.
const std::string COLOR_SUBTITLE         = COLOR_YELLOW;                 ///< Subtitle color (i.e. copyright, version).
const std::string COLOR_TITLE            = COLOR_YELLOW;                 ///< Title color.

const std::string STYLE_PARSER_ERROR     = STYLE_NONE;                   ///< Parser response style on error (e.g. invalid command, invalid movement).
const std::string STYLE_PARSER_REPLY     = STYLE_NONE;                   ///< Standard parser response style.
const std::string STYLE_PLAYER_INPUT     = STYLE_NONE;                   ///< Style of player command input.
const std::string STYLE_ROOM_DESCRIPTION = STYLE_NONE;                   ///< Room description style.
const std::string STYLE_ROOM_NAME        = STYLE_NONE;                   ///< Room name style.
const std::string STYLE_SUBTITLE         = STYLE_NONE;                   ///< Subtitle style (i.e. copyright, version).
const std::string STYLE_TITLE            = STYLE_NONE;                   ///< Title style.

// ============================================================
// Public Methods
// ============================================================

/**
 * @brief Wraps a string in ANSI color and style codes for console output.
 * @param text The string to style.
 * @param color The ANSI color code to apply.
 * @param style The ANSI style code to apply. Defaults to STYLE_NONE.
 * @param applyWordWrap Whether to apply word wrapping to the text. Defaults to true.
 * @return The styled string with reset code appended.
 */
std::string styleText(const std::string& text, const std::string& color, const std::string& style = STYLE_NONE, bool applyWordWrap = true);

/**
 * @brief Wraps text to a specified width on word boundaries.
 * @param text The string to wrap.
 * @param width Maximum line width in characters.
 * @return The wrapped string.
 */
std::string wordWrap(const std::string& text, int width = DEFAULT_WRAP_WIDTH);