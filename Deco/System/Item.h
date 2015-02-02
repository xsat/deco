#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

class Item
{
private:
    sf::Vector2i cordinates;
    sf::Vector2u size;
    bool obstacleStatus;
public:
    Item();
    Item(int _x, int _y, unsigned int _width, unsigned int _height);
    ~Item();
    void setX(int _x);
    void setY(int _y);
    void setWidth(unsigned int _width);
    void setHeight(unsigned int _height);
    int getX() const;
    int getY() const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    bool isIn(const Item * _item) const;
    bool isIn(const std::shared_ptr<Item> &_item) const;
    void show() const;
    virtual void draw(sf::RenderWindow &_window) = 0;
    virtual void setMove(int _x, int _y);
    bool isObstacle() const;
    void setObstacle(bool status);
};

