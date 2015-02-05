#include "MovedBlock.h"

MovedBlock::MovedBlock() : Block(), moveStatus(false), moveTop(false), moveRight(false), moveBottom(false), moveLeft(false), clock(), speed(1250), tempCordinates(0, 0)
{
}

MovedBlock::MovedBlock(const std::string &_fileName) : Block(_fileName), moveStatus(false), moveTop(false), moveRight(false), moveBottom(false), moveLeft(false), clock(), speed(1250), tempCordinates(0, 0)
{
}

MovedBlock::MovedBlock(const std::string &_fileName, const sf::IntRect &_intRect, int _x, int _y) : Block(_fileName, _intRect, _x, _y), moveStatus(false), moveTop(false), moveRight(false), moveBottom(false), moveLeft(false), clock(), speed(1250), tempCordinates(0, 0)
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
    moveTop = true;
    moveRight = true;
    moveBottom = true;
    moveLeft = true;
    /*tempCordinates.x = Block::getX();
    tempCordinates.y = Block::getY();*/
}

void MovedBlock::setMove(bool _status)
{
    moveStatus = _status;
}

void MovedBlock::moveCordinates()
{
    if (clock.getElapsedTime().asMicroseconds() >= speed && isMove() /*&& (Block::getX() != Item::getX() || Block::getY() != Item::getY())*/) {
        int tempX = Block::getX();
        int tempY = Block::getY();

        if (tempX > Item::getX() && moveBottom)
            tempX--;
        else if (tempX < Item::getX() && moveTop)
            tempX++;

        if (tempY > Item::getY() && moveLeft)
            tempY--;
        else if (tempY < Item::getY() && moveRight)
            tempY++;

        tempCordinates.x = tempX;
        tempCordinates.y = tempY;
    }

    if (clock.getElapsedTime().asSeconds() >= 60)
        clock.restart();
}

void MovedBlock::move()
{
    if (clock.getElapsedTime().asMicroseconds() >= speed && isMove() /*&& (Block::getX() != Item::getX() || Block::getY() != Item::getY())*/) {
        clock.restart();
        setPosition(tempCordinates.x, tempCordinates.y);
    }
}

void MovedBlock::draw(sf::RenderWindow &_window)
{
    moveCordinates();
    Block::draw(_window);
}

bool MovedBlock::isMovedItem() const
{
    return true;
}

bool MovedBlock::isNear(const std::shared_ptr<Item> &_item) const;
{
    bool nearStatus = tempCordinates.x + getWidth() > _item->getX() &&
        tempCordinates.x < _item->getX() + _item->getWidth() &&
        tempCordinates.y + getHeight() > _item->getY() &&
        tempCordinates.y < _item->getY() + _item->getHeight();
    /*
    if (nearStatus) {
        moveLeft = (tempCordinates.x < _item->getX());
        moveRight = (tempCordinates.x + getWidth() > _item->getX() + _item->getWidth());
        moveTop = (tempCordinates.y < _item->getY());
        moveBottom = (tempCordinates.y + getHeight() > _item->getY() + _item->getHeight());
    }
    */

    return nearStatus;
}
