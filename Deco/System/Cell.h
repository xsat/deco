#pragma once
#include "Block.h"
#include "Item.h"
#include <vector>

class Cell : public Item
{
private:
    std::vector<std::shared_ptr<Item>> items;
    std::vector<std::shared_ptr<Item>> obstacleItems;
public:
    Cell();
    Cell(int _x, int _y, unsigned int _width, unsigned int _height);
    void Cell::addItem(std::shared_ptr<Item> &_item);
    void show() const;
    virtual void draw(sf::RenderWindow &_window);
};

