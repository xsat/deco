#pragma once
#include "../System/Block.h"

class MovedBlock : public virtual Block
{
private:
    bool moveStatus;
    bool moveTop;
    bool moveRight;
    bool moveBottom;
    bool moveLeft;
    sf::Clock clock;
    sf::Int64 speed;
    sf::Vector2i tempCordinates;
    virtual void moveCordinates();
public:
    MovedBlock();
    MovedBlock(const std::string &_fileName);
    MovedBlock(const std::string &_fileName, const sf::IntRect &_intRect, int _x, int _y);
    ~MovedBlock();
    virtual bool isMove() const;
    virtual void setMove(int _x, int _y);
    virtual void setMove(bool _status);
    virtual void draw(sf::RenderWindow &_window);
    virtual bool isMovedItem() const;
    virtual bool isNear(const std::shared_ptr<Item> &_item) const;
    virtual void move();
};

