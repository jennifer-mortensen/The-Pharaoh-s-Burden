#include "types.h"

// ============================================================
// Public Methods
// ============================================================
Direction parseDirection(std::string input)
{
	return (input == "n" || input == "north") ? Direction::North
		: (input == "s" || input == "south") ? Direction::South
		: (input == "e" || input == "east") ? Direction::East
		: (input == "w" || input == "west") ? Direction::West
		: Direction::None;
}