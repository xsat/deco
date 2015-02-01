#include "Levels.h"

Levels::Levels(Grid &_grid, sf::Event &_event) : levelStatus(true),  grid(_grid), event(_event), current(nullptr)
{
    levels.emplace_back(std::shared_ptr<Level> (new Level1(_grid, _event, *this, 2000, 2000)));
    levels.emplace_back(std::shared_ptr<Level>(new Level2(_grid, _event, *this, 1000, 1000)));
    current = levels[0];
}

Levels::~Levels()
{
}

void Levels::callEvent()
{
    if (current != nullptr)
        current->callEvent();
}

void Levels::draw()
{
    if (levelStatus && current != nullptr) {
        levelStatus = false;
        current->draw();
    }
}

void Levels::setLevel(std::shared_ptr<Level> _level)
{
    if (&_level != &current) {
        levelStatus = true;
        current = _level;
    }
}

void Levels::setLevel(const int level)
{
    setLevel(levels[level]);
}