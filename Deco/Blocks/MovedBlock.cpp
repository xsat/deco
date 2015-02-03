#include "MovedBlock.h"

MovedBlock::MovedBlock() : Block(), moveStatus(true), clock(), speed(1250)
{
}

MovedBlock::MovedBlock(const std::string &_fileName) : Block(_fileName), moveStatus(true), clock(), speed(1250)
{
}

MovedBlock::MovedBlock(const std::string &_fileName, const sf::IntRect &_intRect, int _x, int _y) : Block(_fileName, _intRect, _x, _y), moveStatus(true), clock(), speed(1250)
{
}

MovedBlock::~MovedBlock()
{
}

bool MovedBlock::isMove() const
{
    const float tempX = getFloatRect().left;
    const float tempY = getFloatRect().top;

    return moveStatus && (tempX != getX() || tempY != getY());
}

void MovedBlock::setMove(int _x, int _y)
{
    Block::setMove(_x, _y);
    moveStatus = true;
}

void MovedBlock::move()
{
    if (clock.getElapsedTime().asMicroseconds() >= speed && isMove()) {
        clock.restart();
        float tempX = getFloatRect().left;
        float tempY = getFloatRect().top;

        if (tempX > getX()) {
            tempX--;
        } else if (tempX < getX()) {
            tempX++;
        }

        if (tempY > getY()) {
            tempY--;
        } else if (tempY < getY()) {
            tempY++;
        }

        setPosition(tempX, tempY);
    }

    if (clock.getElapsedTime().asSeconds() >= 60)
        clock.restart();
}

void MovedBlock::draw(sf::RenderWindow &_window)
{
    move();
    Block::draw(_window);
}

bool MovedBlock::isMovedItem() const
{
    return true;
}
