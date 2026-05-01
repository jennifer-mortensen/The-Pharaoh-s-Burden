#include "exit.h"
#include "room.h"

// ============================================================
// Constructors
// ============================================================
Exit::Exit(Room* destination, std::string glimpse, bool visible)
	: destination(destination), glimpse(glimpse), visible(visible) {}

// ============================================================
// Public Methods
// ============================================================
std::string Exit::glimpse_exit(Direction glimpse_toward)
{
    if (!visible) return "";
    return glimpse.empty() ? destination->glimpse_room(glimpse_toward) : glimpse;
}