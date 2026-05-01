#include "exit.h"
#include "room.h"

// ============================================================
// Constructors
// ============================================================
Exit::Exit(Room* destination, std::string glimpse)
	: destination(destination), glimpse(glimpse) {}

// ============================================================
// Public Methods
// ============================================================
std::string Exit::glimpse_exit(Direction glimpse_toward)
{
	return glimpse.empty() ? destination->glimpse_room(glimpse_toward) : glimpse;
}