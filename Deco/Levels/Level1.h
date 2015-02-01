#pragma once
#include "../System/Level.h"
#include "../System/Levels.h"
#include "../Blocks/MovedBlock.h"

class Level1 : public Level
{
private:
    virtual void default();
public:
    Level1(Grid &_grid, sf::Event &_event, Levels &_levels, const int _width, const int _height);
    ~Level1();
    virtual void callEvent();
};

