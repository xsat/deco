#include "Level2.h"

Level2::Level2(Grid &_grid, sf::Event &_event, Levels &_levels, const int _width, const int _height) : Level(_grid, _event, _levels, _width, _height)
{
}

Level2::~Level2()
{
}

void Level2::default()
{
    /*grid.addCell(new Cell(0, 0, 500, 500));
    grid.addItem(new Block("default.png", sf::IntRect(0, 0, 5, 5), 100, 200));*/
}

void Level2::callEvent()
{
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == 0) {
        levels.setLevel(0);
    }
}