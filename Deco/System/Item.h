#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

class Item
{
private:
    sf::Vector2i cordinates;
    sf::Vector2u size;
public:
    Item();
    Item(int _x, int _y, unsigned int _width, unsigned int _height);
    ~Item();
    virtual void setX(int _x);
    virtual void setY(int _y);
    virtual void setWidth(unsigned int _width);
    virtual void setHeight(unsigned int _height);
    virtual int getX() const;
    virtual int getY() const;
    virtual unsigned int getWidth() const;
    virtual unsigned int getHeight() const;
    virtual bool isIn(const Item * _item) const;
    virtual bool isIn(const std::shared_ptr<Item> &_item) const;
    virtual bool isNear(const std::shared_ptr<Item> &_item) const;
    void show() const;
    virtual void draw(sf::RenderWindow &_window) = 0;
    virtual void setMove(int _x, int _y);
    virtual void setMove(bool _status);
    virtual bool isObstacle() const;
    virtual bool isMove() const;
    virtual bool isMovedItem() const;
};

