#include "Item.h"

Item::Item() : x(0), y(0), width(0), height(0), obstacleStatus(false)
{
}

Item::Item(int _x, int _y, unsigned int _width, unsigned int _height) : x(_x), y(_y), width(_width), height(_height), obstacleStatus(false)
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
    x = _x;
}

void Item::setY(int _y)
{
    y = _y;
}

void Item::setWidth(unsigned int _width)
{
    width = _width;
}

void Item::setHeight(unsigned int _height)
{
    height = _height;
}

int Item::getX() const
{
    return x;
}

int Item::getY() const
{
    return y;
}

unsigned int Item::getWidth() const
{
    return width;
}

unsigned int Item::getHeight() const
{
    return height;
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
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "width = " << width << std::endl;
    std::cout << "height = " << height << std::endl << std::endl;
}

void Item::setMove(int _x, int _y)
{
    setX(_x);
    setY(_y);
}

bool Item::isObstacle() const
{
    return obstacleStatus;
}
void Item::setObstacle(bool status)
{
    obstacleStatus = status;
}