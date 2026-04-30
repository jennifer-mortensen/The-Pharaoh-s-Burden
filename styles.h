/**
 * @file styles.h
 * @brief ANSI escape code constants for console text coloring and styling.
 */

#pragma once
#include <string>

// ============================================================
// Constants (Console Display)
// ============================================================

const std::string COLOR_RESET = "\033[0m";           ///< Resets color to terminal default.

// Standrd colors
const std::string COLOR_BLACK = "\033[30m";          ///< Standard black.
const std::string COLOR_RED = "\033[31m";            ///< Standard red.
const std::string COLOR_GREEN = "\033[32m";          ///< Standard green.
const std::string COLOR_YELLOW = "\033[33m";         ///< Standard yellow.
const std::string COLOR_BLUE = "\033[34m";           ///< Standard blue.
const std::string COLOR_MAGENTA = "\033[35m";        ///< Standard magenta.
const std::string COLOR_CYAN = "\033[36m";           ///< Standard cyan.
const std::string COLOR_WHITE = "\033[37m";          ///< Standard white.

// Bright variants
const std::string COLOR_BRIGHT_BLACK = "\033[90m";   ///< Bright black (dark gray).
const std::string COLOR_BRIGHT_RED = "\033[91m";     ///< Bright red.
const std::string COLOR_BRIGHT_GREEN = "\033[92m";   ///< Bright green.
const std::string COLOR_BRIGHT_YELLOW = "\033[93m";  ///< Bright yellow.
const std::string COLOR_BRIGHT_BLUE = "\033[94m";    ///< Bright blue.
const std::string COLOR_BRIGHT_MAGENTA = "\033[95m"; ///< Bright magenta.
const std::string COLOR_BRIGHT_CYAN = "\033[96m";    ///< Bright cyan.
const std::string COLOR_BRIGHT_WHITE = "\033[97m";   ///< Bright white.

// Styles
const std::string STYLE_BOLD = "\033[1m";            ///< Bold.
const std::string STYLE_UNDERLINE = "\033[4m";       ///< Underlined.
const std::string STYLE_DIM = "\033[2m";             ///< Dim.
const std::string STYLE_ITALIC = "\033[3m";          ///< Italic.
const std::string STYLE_NONE = "";                   ///< No style (default).