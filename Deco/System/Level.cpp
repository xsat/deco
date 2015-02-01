#include "Level.h"

Level::Level(Grid &_grid, sf::Event &_event, Levels &_levels, const int _width, const int _height) : grid(_grid), event(_event), levels(_levels), width(_width), height(_height)
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
