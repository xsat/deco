#pragma once
#include "Grid.h"
#include "Level.h"
#include "../Levels/Level1.h"
#include "../Levels/Level2.h"

class Levels
{
private:
    bool levelStatus;
    Grid &grid;
    sf::Event &event;
    std::vector<std::shared_ptr<Level>> levels;
    std::shared_ptr<Level> current;
public:
    Levels(Grid &_grid, sf::Event &_event);
    ~Levels();
    void callEvent();
    void draw();
    void setLevel(std::shared_ptr<Level> _level);
    void setLevel(const int level);
};
