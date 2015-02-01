#pragma once
#include "../System/Level.h"
#include "../System/Levels.h"

class Level2 : public Level
{
private:
    virtual void default();
public:
    Level2(Grid &_grid, sf::Event &_event, Levels &_levels, const int _width, const int _height);
    ~Level2();
    virtual void callEvent();
};

