#pragma once
#include "../System/Block.h"

class MovedBlock : public virtual Block
{
private:
    bool moveStatus;
    sf::Clock clock;
    virtual void move();
    sf::Int64 speed;
public:
    MovedBlock();
    MovedBlock(const std::string &_fileName);
    MovedBlock(const std::string &_fileName, const sf::IntRect &_intRect, int _x, int _y);
    ~MovedBlock();
    virtual bool isMove() const;
    virtual void setMove(int _x, int _y);
    virtual void draw(sf::RenderWindow &_window);
    virtual bool isMovedItem() const;
};

