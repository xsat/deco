#pragma once
#include "Cell.h"
#include <map>

class Grid
{
private:
    sf::Vector2i cordinates;
    std::vector<std::shared_ptr<Cell>> cells;
    std::vector<std::shared_ptr<Item>> items;
    std::map<unsigned int, std::shared_ptr<Item>> idItems;
    void addID(unsigned int _id, std::shared_ptr<Item> &_item);
public:
    Grid();
    ~Grid();
    void addCell(std::shared_ptr<Cell> &_cell);
    void addItem(std::shared_ptr<Item> _item);
    void addItem(unsigned int _id, std::shared_ptr<Item> _item);
    std::shared_ptr<Item> &getItem(unsigned int _id);
    void show() const;
    virtual void draw(sf::RenderWindow &_window);
    void clear();
    void setX(int _x);
    void setY(int _y);
    int getX() const;
    int getY() const;
};

