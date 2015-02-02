#pragma once
#include "Grid.h"

class Levels;

class Level
{
private:
    void clearGrid();
    virtual void default() = 0;
    sf::Vector2u size;
protected:
    Grid &grid;
    sf::Event &event;
    Levels &levels;
public:
    Level(Grid &_grid, sf::Event &_event, Levels &_levels, const int _width, const int _height);
    ~Level();
    void draw();
    virtual void callEvent();
    unsigned int getWidth() const;
    unsigned int getHeight() const;
};

