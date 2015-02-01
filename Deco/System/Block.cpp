#include "Block.h"

Block::Block() : Item(), texture(), sprite()
{
}

Block::Block(const std::string &_fileName) : Item(), texture(), sprite()
{
    loadTexture(_fileName);
}

Block::Block(const std::string &_fileName, const sf::IntRect &_intRect, int _x, int _y) : Item(_x, _y, _intRect.width, _intRect.height), texture(), sprite()
{
    loadTexture(_fileName);
    sprite.setTextureRect(_intRect);
    setPosition(_x, _y);
}

Block::~Block()
{
}

void Block::setPosition(int _x, int _y)
{
    setPosition(static_cast<float>(_x), static_cast<float>(_y));
}

void Block::setPosition(float _x, float _y)
{
    sprite.setPosition(static_cast<float>(_x), static_cast<float>(_y));
}

void Block::loadTexture(const std::string &_fileName)
{
    texture.loadFromFile(_fileName);
    texture.setRepeated(true);
    sprite.setTexture(texture);
}

void Block::setRect(const sf::IntRect &_intRect)
{
    setX(0);
    setY(0);
    setWidth(_intRect.width);
    setHeight(_intRect.height);
    sprite.setTextureRect(_intRect);
}

void Block::draw(sf::RenderWindow &_window)
{
    _window.draw(sprite);
}

const sf::FloatRect &Block::getFloatRect() const
{
    return sprite.getGlobalBounds();
}
