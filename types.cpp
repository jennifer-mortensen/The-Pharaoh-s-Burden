#include <cctype> 
#include <unordered_map>
#include "types.h"
#include "utils.h"

// ============================================================
// Public Methods
// ============================================================
Direction parse_direction(std::string input)
{
    static const std::unordered_map<std::string, Direction> directions =
    {
        {"n", Direction::North}, {"north", Direction::North},
        {"s", Direction::South}, {"south", Direction::South},
        {"e", Direction::East},  {"east", Direction::East},
        {"w", Direction::West},  {"west", Direction::West},
    };

    auto result = directions.find(to_lower(input));

    return result == directions.end() ? Direction::None : result->second;
}