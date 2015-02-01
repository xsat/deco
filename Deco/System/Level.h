#pragma once
#include "Grid.h"

class Levels;

class Level
{
private:
    void clearGrid();
    virtual void default() = 0;
protected:
    Grid &grid;
    sf::Event &event;
    Levels &levels;
    const int width;
    const int height;
public:
    Level(Grid &_grid, sf::Event &_event, Levels &_levels, const int _width, const int _height);
    ~Level();
    void draw();
    virtual void callEvent();
};

