#include "Engine.h"

Engine::Engine() : window(sf::VideoMode(window::width, window::height), "Loading"), event(), grid(), levels(grid, event), zoom(5), isMoveTop(false), isMoveRight(false), isMoveBot(false), isMoveLeft(false)
{
    window.setView(sf::View(sf::FloatRect(0, 0, window::width, window::height)));
}

Engine::~Engine()
{
}

void Engine::run()
{
    for (; window.isOpen(); ) {
        for (; window.pollEvent(event);)
            callEvents();

        window.clear();

        if (isMove())
            move();

        callIterations();
        window.display();
    }
}

void Engine::callEvents()
{
    if (event.type == sf::Event::Closed)
        window.close();

    levels.callEvent();

    if (event.type == sf::Event::MouseMoved) {
        if (!isMoveTop && event.mouseMove.y >= 0 && event.mouseMove.y <= 20) {
            isMoveTop = true;
        } else if (isMoveTop) {
            isMoveTop = false;
        }

        if (!isMoveRight && event.mouseMove.x <= window::width && event.mouseMove.x >= window::width - 20) {
            isMoveRight = true;
        } else if (isMoveRight) {
            isMoveRight = false;
        }

        if (!isMoveBot && event.mouseMove.y <= window::height && event.mouseMove.y >= window::height - 20) {
            isMoveBot = true;
        } else if (isMoveBot) {
            isMoveBot = false;
        }

        if (!isMoveLeft && event.mouseMove.x >= 0 && event.mouseMove.x <= 20) {
            isMoveLeft = true;
        } else if (isMoveLeft) {
            isMoveLeft = false;
        }
    }

    /*if (event.type == sf::Event::MouseWheelMoved) {
        float factor;

        if (event.mouseWheel.delta == 1) {
            factor = 0.9f;
            zoom--;
        } else {
            factor = 1.11111111111f;
            zoom++;
        }

        if (zoom >= 0 && zoom <= 10) {
            sf::View currentView = window.getView();
            currentView.zoom(factor);
            window.setView(currentView);
        } else if (zoom > 10) {
            zoom = 10;
        } else if (zoom < 0) {
            zoom = 0;
        }
    }*/
}

void Engine::callIterations()
{
    levels.draw();
    grid.draw(window);
}

bool Engine::isMove() const
{
    return isMoveTop || isMoveRight || isMoveBot || isMoveLeft;
}

void Engine::move()
{
    sf::View currentView = window.getView();

    if (isMoveTop)
        moveTop(currentView);
    if (isMoveRight)
        moveRight(currentView);
    if (isMoveBot)
        moveBot(currentView);
    if (isMoveLeft)
        moveLeft(currentView);

    updateGridXY(currentView);
    window.setView(currentView);
}

void Engine::moveTop(sf::View &_view)
{
    _view.move(0.0f, -0.5f);
}

void Engine::moveRight(sf::View &_view)
{
    _view.move(0.5f, 0.0f);
}

void Engine::moveBot(sf::View &_view)
{
    _view.move(0.0f, +0.5f);
}

void Engine::moveLeft(sf::View &_view)
{
    _view.move(-0.5f, 0.0f);
}

void Engine::updateGridXY(const sf::View &_view)
{
    const sf::Vector2f &center = _view.getCenter();
    const sf::Vector2f &size = _view.getSize();
    grid.setX(static_cast<int>(center.x - (size.x / 2)));
    grid.setY(static_cast<int>(center.y - (size.y / 2)));
}