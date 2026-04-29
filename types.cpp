#include "types.h"
#include <sstream>

Direction parseDirection(std::string input) {
	return (input == "n" || input == "north") ? Direction::North
		: (input == "s" || input == "south") ? Direction::South
		: (input == "e" || input == "east") ? Direction::East
		: (input == "w" || input == "west") ? Direction::West
		: Direction::None;
}

std::string wordWrap(const std::string& text, int width) {
    std::string result;
    std::istringstream words(text);
    std::string word;
    int lineLength = 0;

    while (words >> word) {
        if (lineLength + word.length() + 1 > width && lineLength > 0) {
            result += "\n";
            lineLength = 0;
        }
        if (lineLength > 0) {
            result += " ";
            lineLength++;
        }
        result += word;
        lineLength += word.length();
    }
    return result;
}