/**
 * @file utils.h
 * @brief General purpose utility functions.
 */

#pragma once
#include <iostream>
#include <string>
#include "ansi.h"

#ifdef _DEBUG
	#define LOG_DEBUG(msg) std::cerr << "DEBUG: " << msg << "\n"
#else
	#define LOG_DEBUG(msg)
#endif

 // ============================================================
 // Constants
 // ============================================================
inline constexpr int DEFAULT_WRAP_WIDTH = 100;

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
std::string style_text(const std::string& text, const std::string& color, const std::string& style = ansi::STYLE_NONE, bool apply_word_wrap = true);

/**
 * @brief Converts a string to lowercase in place (ASCII only).
 * @param text The string to modify.
 */
std::string to_lower(std::string text);

/**
 * @brief Wraps text to a specified width on word boundaries.
 * @param text The string to wrap.
 * @param width Maximum line width in characters.
 * @return The wrapped string.
 */
std::string word_wrap(const std::string& text, int width = DEFAULT_WRAP_WIDTH);