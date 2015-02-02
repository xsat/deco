#include "Grid.h"

Grid::Grid() : cordinates(0, 0), cells(), items(), idItems()
{
}

Grid::~Grid()
{
}

void Grid::addCell(std::shared_ptr<Cell> &_cell)
{
    cells.emplace_back(_cell);
}

void Grid::addItem(std::shared_ptr<Item> _item)
{
    for (auto &ceil : cells)
        if (_item->isIn(ceil))
            ceil->addItem(_item);

    items.emplace_back(_item);
}

void Grid::addItem(unsigned int _id, std::shared_ptr<Item> _item)
{
    addItem(_item);
    addID(_id, _item);
}

std::shared_ptr<Item> &Grid::getItem(unsigned int _id)
{
    return idItems[_id];
}

void Grid::addID(unsigned int _id, std::shared_ptr<Item> &_item)
{
    idItems.insert(std::pair<unsigned int, std::shared_ptr<Item>>(_id, _item));
}

void Grid::show() const
{
    for (auto &ceil : cells)
        ceil->show();
}

void Grid::draw(sf::RenderWindow &_window)
{
    for (auto &ceil : cells)
        ceil->draw(_window);

    for (auto &item : items)
        item->draw(_window);
}

void Grid::clear()
{
    cells.clear();
    items.clear(); 
    idItems.clear();
}

void Grid::setX(int _x)
{
    cordinates.x = _x;
}

void Grid::setY(int _y)
{
    cordinates.y = _y;
}

int Grid::getX() const
{
    return cordinates.x;
}

int Grid::getY() const
{
    return cordinates.y;
}