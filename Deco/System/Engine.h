#pragma once
#include "Grid.h"
#include "Levels.h"

class Engine
{
private:
    sf::RenderWindow window;
    sf::Event event;
    Grid grid;
    Levels levels;
    int zoom;
    bool isMoveTop;
    bool isMoveRight;
    bool isMoveBot;
    bool isMoveLeft;
    bool isMove() const;
    void move();
    void moveTop(sf::View &_view);
    void moveRight(sf::View &_view);
    void moveBot(sf::View &_view);
    void moveLeft(sf::View &_view);
    void updateGridXY(const sf::View &_view);
public:
    enum window {
        width = 1000,
        height = 500
    };
    Engine();
    ~Engine();
    void run();
    void callEvents();
    void callIterations();
};

