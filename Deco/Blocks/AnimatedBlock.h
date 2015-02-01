#pragma once
#include "../System/Block.h"
#include <map>

class AnimatedBlock : public virtual Block
{
private:
    std::map<std::string, sf::IntRect> intRects;
public:
    AnimatedBlock();
    AnimatedBlock(const std::string &_fileName);
    AnimatedBlock(const std::string &_fileName, const sf::IntRect &_intRect, int _x, int _y);
    ~AnimatedBlock();
    void addRect(const std::string &_rectKey, const sf::IntRect &_intRect);
    virtual void setRect(const std::string &_rectKey, const sf::IntRect &_intRect);
    virtual void setRect(const std::string &_rectKey);
};

