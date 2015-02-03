#include "Level1.h"

Level1::Level1(Grid &_grid, sf::Event &_event, Levels &_levels, const int _width, const int _height) : Level(_grid, _event, _levels, _width, _height)
{
}

Level1::~Level1()
{
}

void Level1::default() 
{
    grid.addCell(std::shared_ptr<Cell>(new Cell(0, 0, 500, 500)));
    grid.addCell(std::shared_ptr<Cell>(new Cell(0, 500, 500, 500)));
    grid.addCell(std::shared_ptr<Cell>(new Cell(500, 0, 500, 500)));
    grid.addCell(std::shared_ptr<Cell>(new Cell(500, 500, 500, 500)));

    grid.addItem(std::shared_ptr<Block>(new Block("grass.png", sf::IntRect(0, 0, getWidth(), getHeight()), 0, 0)));

    grid.addItem(std::shared_ptr<Block>(new Block("house.png", sf::IntRect(0, 0, 100, 120), 300, 244)));
    grid.addItem(std::shared_ptr<Block>(new Block("house.png", sf::IntRect(0, 0, 100, 120), 500, 150)));
    grid.addItem(std::shared_ptr<Block>(new Block("house.png", sf::IntRect(0, 0, 100, 120), 256, 100)));

    grid.addItem(std::shared_ptr<Block>(new Block("fire.png", sf::IntRect(0, 0, 50, 50), 390, 190)));

    grid.addItem(std::shared_ptr<Block>(new Block("tree.png", sf::IntRect(0, 0, 70, 100), 530, 36)));
    grid.addItem(std::shared_ptr<Block>(new Block("tree.png", sf::IntRect(0, 0, 70, 100), 490, 51)));
    grid.addItem(std::shared_ptr<Block>(new Block("tree.png", sf::IntRect(0, 0, 70, 100), 383, 28)));
    grid.addItem(std::shared_ptr<Block>(new Block("tree.png", sf::IntRect(0, 0, 70, 100), 429, 69)));

    grid.addItem(std::shared_ptr<ObstacleBlock>(new ObstacleBlock("stone.png", sf::IntRect(0, 0, 50, 50), 70, 70)));

    grid.addItem(1, std::shared_ptr<MovedBlock>(new MovedBlock("stone_move.png", sf::IntRect(0, 0, 50, 50), 10, 10)));
    grid.addItem(2, std::shared_ptr<MovedBlock>(new MovedBlock("stone_move.png", sf::IntRect(0, 0, 50, 50), 10, 500)));
}

void Level1::callEvent()
{
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == 1) {
        grid.getItem(1)->setMove(event.mouseButton.x + grid.getX(), event.mouseButton.y + grid.getY());
    }

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == 0) {
        grid.getItem(2)->setMove(event.mouseButton.x + grid.getX(), event.mouseButton.y + grid.getY());
    }

    /*if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == 0) {
        levels.setLevel(1);
    }*/
}