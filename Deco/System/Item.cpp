#include "Item.h"

Item::Item() : cordinates(0, 0), size(0,0)
{
}

Item::Item(int _x, int _y, unsigned int _width, unsigned int _height) : cordinates(_x, _y), size(_width, _height)
{

}

Item::~Item()
{
}

void Item::draw(sf::RenderWindow &_window)
{
}

void Item::setX(int _x)
{
    cordinates.x = _x;
}

void Item::setY(int _y)
{
    cordinates.y = _y;
}

void Item::setWidth(unsigned int _width)
{
    size.x = _width;
}

void Item::setHeight(unsigned int _height)
{
    size.y = _height;
}

int Item::getX() const
{
    return cordinates.x;
}

int Item::getY() const
{
    return cordinates.y;
}

unsigned int Item::getWidth() const
{
    return size.x;
}

unsigned int Item::getHeight() const
{
    return size.y;
}

bool Item::isIn(const Item * _item) const
{
    return (getX() >= _item->getX() && getX() + getWidth() <= _item->getX() + _item->getWidth()) || (getY() >= _item->getY() && getY() + getHeight() <= _item->getY() + _item->getHeight());
}

bool Item::isIn(const std::shared_ptr<Item> &_item) const
{
    return (getX() >= _item->getX() && getX() + getWidth() <= _item->getX() + _item->getWidth()) || (getY() >= _item->getY() && getY() + getHeight() <= _item->getY() + _item->getHeight());
}

void Item::show() const
{
}

void Item::setMove(int _x, int _y)
{
    setX(_x);
    setY(_y);
}

void Item::setMove(bool _status)
{
}

bool Item::isObstacle() const
{
    return false;
}

bool Item::isMove() const
{
    return false;
}

bool Item::isMovedItem() const
{
    return false;
}