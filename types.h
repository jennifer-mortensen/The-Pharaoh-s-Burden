#pragma once
#include <string>

enum class Direction { North, South, East, West, None };

Direction parseDirection(std::string input);
std::string wordWrap(const std::string& text, int width = 100);