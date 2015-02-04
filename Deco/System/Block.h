#pragma once
#include "Item.h"
#include <SFML/Graphics.hpp>
#include <string>

class Block : public Item
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    void loadTexture(const std::string &_fileName);
public:
    Block();
    Block(const std::string &_fileName);
    Block(const std::string &_fileName, const sf::IntRect &_intRect, int _x, int _y);
    ~Block();
    void setPosition(int _x, int _y);
    void setPosition(float _x, float _y);
    virtual void setRect(const sf::IntRect &_intRect);
    virtual void draw(sf::RenderWindow &_window);
    const sf::FloatRect &getFloatRect() const;
    virtual int getX() const;
    virtual int getY() const;
};

