#pragma once
#include "../System/Block.h"

class ObstacleBlock : public virtual Block
{
public:
    ObstacleBlock();
    ObstacleBlock(const std::string &_fileName);
    ObstacleBlock(const std::string &_fileName, const sf::IntRect &_intRect, int _x, int _y);
    ~ObstacleBlock();
    virtual bool isObstacle() const;
};

