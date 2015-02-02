#include "Cell.h"

Cell::Cell() : Item()
{
}

Cell::Cell(int _x, int _y, unsigned int _width, unsigned int _height) : Item(_x, _y, _width, _height)
{
}

void Cell::addItem(std::shared_ptr<Item> &_item)
{
    items.emplace_back(_item);
    if (_item->isObstacle())
        obstacleItems.emplace_back(_item);
}

void Cell::show() const 
{
    std::cout << "===========" << std::endl;
    Item::show();

    if (items.size() > 0)
        std::cout << "------------" << std::endl;

    for (auto item : items)
        item->show();

    std::cout << "===========" << std::endl;
}

void Cell::draw(sf::RenderWindow &_window)
{
    for (auto item : items)
        item->draw(_window);
}