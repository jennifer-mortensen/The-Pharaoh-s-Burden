/**
 * @file theme.h
 * @brief Semantic color and style definitions for user-facing console output.
 *
 * @details Provides higher-level styling constants that map to underlying
 *          ANSI escape codes. These represent meaning (e.g. parser errors,
 *          room names) rather than raw color values.
 */

#pragma once
#include "ansi.h"

// ============================================================
// Constants
// ============================================================
namespace theme
{
	const std::string COLOR_GLIMPSE             = ansi::COLOR_BRIGHT_YELLOW;          ///< Color of glimpse text.
	const std::string COLOR_GLIMPSE_DIRECTION   = ansi::COLOR_BRIGHT_GREEN;                 ///< Color of the direction prepended before glimpse strings.
	const std::string COLOR_PARSER_ERROR        = ansi::COLOR_BRIGHT_YELLOW;          ///< Parser response color on error (e.g. invalid command, invalid movement).
	const std::string COLOR_PARSER_REPLY        = ansi::COLOR_BRIGHT_YELLOW;          ///< Standard parser response color.
	const std::string COLOR_PLAYER_INPUT        = ansi::COLOR_BRIGHT_CYAN;            ///< Color of player command input.
	const std::string COLOR_ROOM_DESCRIPTION    = ansi::COLOR_BRIGHT_YELLOW;          ///< Room description color.
	const std::string COLOR_ROOM_NAME           = ansi::COLOR_YELLOW;                 ///< Room name color.
	const std::string COLOR_SUBTITLE            = ansi::COLOR_YELLOW;                 ///< Subtitle color (i.e. copyright, version).
	const std::string COLOR_TITLE               = ansi::COLOR_YELLOW;                 ///< Title color.

	const std::string STYLE_GLIMPSE             = ansi::STYLE_NONE;                   ///< Style of glimpse text.
	const std::string STYLE_GLIMPSE_DIRECTION   = ansi::STYLE_NONE;                   ///< Style of the direction prepended before glimpse strings.
	const std::string STYLE_PARSER_ERROR        = ansi::STYLE_NONE;                   ///< Parser response style on error (e.g. invalid command, invalid movement).
	const std::string STYLE_PARSER_REPLY        = ansi::STYLE_NONE;                   ///< Standard parser response style.
	const std::string STYLE_PLAYER_INPUT        = ansi::STYLE_NONE;                   ///< Style of player command input.
	const std::string STYLE_ROOM_DESCRIPTION    = ansi::STYLE_NONE;                   ///< Room description style.
	const std::string STYLE_ROOM_NAME           = ansi::STYLE_NONE;                   ///< Room name style.
	const std::string STYLE_SUBTITLE            = ansi::STYLE_NONE;                   ///< Subtitle style (i.e. copyright, version).
	const std::string STYLE_TITLE               = ansi::STYLE_NONE;                   ///< Title style.
}
