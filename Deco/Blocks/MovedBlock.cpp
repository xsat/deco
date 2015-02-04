#include "MovedBlock.h"

MovedBlock::MovedBlock() : Block(), moveStatus(false), clock(), speed(1250)
{
}

MovedBlock::MovedBlock(const std::string &_fileName) : Block(_fileName), moveStatus(false), clock(), speed(1250)
{
}

MovedBlock::MovedBlock(const std::string &_fileName, const sf::IntRect &_intRect, int _x, int _y) : Block(_fileName, _intRect, _x, _y), moveStatus(false), clock(), speed(1250)
{
}

MovedBlock::~MovedBlock()
{
}

bool MovedBlock::isMove() const
{
    return moveStatus /*&& (Block::getX() != Item::getX() || Block::getY() != Item::getY())*/;
}

void MovedBlock::setMove(int _x, int _y)
{
    Block::setMove(_x, _y);
    moveStatus = true;
}

void MovedBlock::setMove(bool _status)
{
    moveStatus = _status;
}

void MovedBlock::move()
{
    if (clock.getElapsedTime().asMicroseconds() >= speed && isMove() && (Block::getX() != Item::getX() || Block::getY() != Item::getY())) {
        clock.restart();
        int tempX = Block::getX();
        int tempY = Block::getY();

        if (tempX > Item::getX()) {
            tempX--;
        } else if (tempX < Item::getX()) {
            tempX++;
        }

        if (tempY > Item::getY()) {
            tempY--;
        } else if (tempY < Item::getY()) {
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
