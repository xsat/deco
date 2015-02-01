#include "AnimatedBlock.h"

AnimatedBlock::AnimatedBlock() : Block()
{
}

AnimatedBlock::AnimatedBlock(const std::string &_fileName) : Block(_fileName)
{
}

AnimatedBlock::AnimatedBlock(const std::string &_fileName, const sf::IntRect &_intRect, int _x, int _y) : Block(_fileName, _intRect, _x, _y)
{
    addRect("default", _intRect);
}

AnimatedBlock::~AnimatedBlock()
{
}

void AnimatedBlock::addRect(const std::string &_rectKey, const sf::IntRect &_intRect)
{
    intRects.emplace(_rectKey, _intRect);
}

void AnimatedBlock::setRect(const std::string &_rectKey, const sf::IntRect &_intRect)
{
    addRect(_rectKey, _intRect);
    Block::setRect(intRects[_rectKey]);
}

void AnimatedBlock::setRect(const std::string &_rectKey)
{
    if (intRects.count(_rectKey) >0)
        Block::setRect(intRects[_rectKey]);
}