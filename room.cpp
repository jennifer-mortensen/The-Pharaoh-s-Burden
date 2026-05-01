#include <iostream>
#include <vector>
#include "room.h"
#include "theme.h"
#include "utils.h"

// ============================================================
// Constructors
// ============================================================
Room::Room(std::string id, std::string name, std::string description, std::string glimpse, std::map<Direction, std::string> glimpse_map)
	: id(id), name(name), description(description), glimpse(glimpse), glimpse_map(glimpse_map) {}

// ============================================================
// Public Methods
// ============================================================
void Room::print_room()
{
    print_name();
    print_description();
    std::cout << "\n";
    print_exits();
}

std::string Room::glimpse_room(Direction glimpse_toward)
{
    if (glimpse_map.count(glimpse_toward))
        if (!glimpse_map[glimpse_toward].empty())
            return glimpse_map[glimpse_toward];
        else
            LOG_DEBUG("Debug: glimpse key exists but value is empty for direction " << static_cast<int>(glimpse_toward));
    return glimpse.empty() ? name : glimpse;
}

// ============================================================
// Private Methods
// ============================================================
void Room::print_name()
{
    std::cout << style_text(name, theme::COLOR_ROOM_NAME) << "\n";
}

void Room::print_description()
{
    std::cout << style_text(description, theme::COLOR_ROOM_DESCRIPTION) << "\n";
}

void Room::print_exits()
{
    std::vector<std::pair<Direction, std::string>> cardinals =
    {
        { Direction::North, "North:" },
        { Direction::East,  "East: " },
        { Direction::South, "South:" },
        { Direction::West,  "West: " }
    };

    bool any = false;
    for (auto& [dir, label] : cardinals)
    {
        if (!exits.count(dir)) 
            continue;
        std::string glimpse = exits[dir]->glimpse_exit(dir);
        if (glimpse.empty()) 
            continue;
        std::cout << style_text(label, theme::COLOR_GLIMPSE_DIRECTION, theme::STYLE_GLIMPSE_DIRECTION)
            << " " << style_text(glimpse, theme::COLOR_GLIMPSE, theme::STYLE_GLIMPSE) << "\n";
        any = true;
    }
    if (any) std::cout << "\n";
}