#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Constantes.h"

int main()
{
    Game game;
    bool leftPressed(false), rightPressed(false), upPressed(false), downPressed(false);
    float zoom(SPRITE >> 6);

    sf::Clock m_clock;

    while(game.m_window.isOpen())
    {
        sf::Event event;
        while(game.m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                game.m_window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Left:
                        if(!leftPressed)
                            leftPressed = true;
                        break;
                    case sf::Keyboard::Right:
                        if(!rightPressed)
                            rightPressed = true;
                        break;
                    case sf::Keyboard::Up:
                        if(!upPressed)
                            upPressed = true;
                        break;
                    case sf::Keyboard::Down:
                        if(!downPressed)
                            downPressed = true;
                        break;
                    case sf::Keyboard::Space:
                        game.c_view[0] = MAP_WIDTH/2;
                        game.c_view[1] = MAP_HEIGTH/2;
                        break;
                    default:
                        break;
                }
            }

            if (event.type == sf::Event::KeyReleased)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Left:
                        leftPressed = false;
                        break;
                    case sf::Keyboard::Right:
                        rightPressed = false;
                        break;
                    case sf::Keyboard::Up:
                        upPressed = false;
                        break;
                    case sf::Keyboard::Down:
                        downPressed = false;
                        break;
                    default:
                        break;
                }
            }

            if (event.type == sf::Event::MouseWheelMoved)
            {
                if (event.mouseWheel.delta < 0)
                {
                    if (zoom < 5)
                    {
                        game.m_view.zoom(1.1);
                        zoom = zoom * 1.1f;
                    }
                }
                else
                {
                    if (zoom > 1)
                    {
                        game.m_view.zoom(0.9);
                        zoom = zoom * 0.9f;
                    }
                }
            }

            if (leftPressed)
            {
                if (game.c_view[0] - ((WIN_WIDTH / 2) - SPRITE) > 0)
                {
                    game.c_view[0] -= m_clock.getElapsedTime().asMicroseconds() / 20;
                }
            }

            if (rightPressed)
            {
                if (game.c_view[0] + ((WIN_WIDTH / 2) - SPRITE) < (MAP_WIDTH * SPRITE))
                {
                    game.c_view[0] += m_clock.getElapsedTime().asMicroseconds() / 20;
                }
            }

            if (upPressed)
            {
                if (game.c_view[1] - ((WIN_HEIGTH / 2) - SPRITE) > 0)
                {
                    game.c_view[1] -= m_clock.getElapsedTime().asMicroseconds() / 20;
                }
            }

            if (downPressed)
            {
                if (game.c_view[1] + ((WIN_HEIGTH / 2) - SPRITE) < (MAP_HEIGTH * SPRITE))
                {
                    game.c_view[1] += m_clock.getElapsedTime().asMicroseconds() / 20;
                }
            }
        }

        game.m_window.clear(sf::Color::Black);
        game.render();
        game.m_window.display();
        int framerate = 1000 /(m_clock.getElapsedTime().asMilliseconds() + 1);
        m_clock.restart();
    }

    return 0;
}