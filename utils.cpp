#include <sstream>
#include "ansi.h"
#include "utils.h"

// ============================================================
// Public Methods
// ============================================================
std::string style_text(const std::string& text, const std::string& color, const std::string& style, bool apply_word_wrap)
{
    std::string styled_text = apply_word_wrap ? word_wrap(text) : text;
    return style + color + styled_text + ansi::COLOR_RESET;
}

std::string to_lower(std::string text)
{
    for (char& c : text)
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return text;
}

std::string word_wrap(const std::string& text, int width)
{
    std::string result;
    std::istringstream words(text);
    std::string word;
    int line_length = 0;

    while (words >> word)
    {
        if (line_length + word.length() + 1 > width && line_length > 0)
        {
            result += "\n";
            line_length = 0;
        }
        if (line_length > 0)
        {
            result += " ";
            line_length++;
        }
        result += word;
        line_length += word.length();
    }
    return result;
}