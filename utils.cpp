#include <sstream>
#include "utils.h"

// ============================================================
// Public Methods
// ============================================================
std::string styleText(const std::string& text, const std::string& color, const std::string& style, bool applyWordWrap)
{
    std::string styledText = applyWordWrap ? wordWrap(text) : text;
    return style + color + styledText + COLOR_RESET;
}

std::string wordWrap(const std::string& text, int width)
{
    std::string result;
    std::istringstream words(text);
    std::string word;
    int lineLength = 0;

    while (words >> word)
    {
        if (lineLength + word.length() + 1 > width && lineLength > 0)
        {
            result += "\n";
            lineLength = 0;
        }
        if (lineLength > 0)
        {
            result += " ";
            lineLength++;
        }
        result += word;
        lineLength += word.length();
    }
    return result;
}