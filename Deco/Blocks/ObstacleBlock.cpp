#include "ObstacleBlock.h"

ObstacleBlock::ObstacleBlock() : Block()
{
}

ObstacleBlock::ObstacleBlock(const std::string &_fileName) : Block(_fileName)
{
}

ObstacleBlock::ObstacleBlock(const std::string &_fileName, const sf::IntRect &_intRect, int _x, int _y) : Block(_fileName, _intRect, _x, _y)
{
}

ObstacleBlock::~ObstacleBlock()
{
}

bool ObstacleBlock::isObstacle() const
{
    return true;
}