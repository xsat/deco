#include "Level.h"

Level::Level(Grid &_grid, sf::Event &_event, Levels &_levels, const int _width, const int _height) : grid(_grid), event(_event), levels(_levels), size(_width, _height)
{
}

Level::~Level()
{
}

void Level::clearGrid()
{
    grid.clear();
}

void Level::draw()
{
    clearGrid();
    default();
}

void Level::callEvent()
{
}

unsigned int Level::getWidth() const
{
    return size.x;
}

unsigned int Level::getHeight() const
{
    return size.y;
}
