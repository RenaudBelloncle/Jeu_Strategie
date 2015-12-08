#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Constantes.h"

int main()
{
    Game game;
    float zoom = SPRITE >> 6;

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
                        if (game.c_view[0] - ((WIN_WIDTH/2) - SPRITE) > 0)
                        {
                            game.c_view[0] -= (SPRITE / 2) * zoom;
                        }
                        break;
                    case sf::Keyboard::Right:
                        if (game.c_view[0] + ((WIN_WIDTH/2) - SPRITE) < (MAP_WIDTH * SPRITE))
                        {
                            game.c_view[0] += (SPRITE / 2) * zoom;
                        }
                        break;
                    case sf::Keyboard::Up:
                        if (game.c_view[1] - ((WIN_HEIGTH/2) - SPRITE) > 0)
                        {
                            game.c_view[1] -= (SPRITE / 2) * zoom;
                        }
                        break;
                    case sf::Keyboard::Down:
                        if (game.c_view[1] + ((WIN_HEIGTH/2) - SPRITE) < (MAP_HEIGTH * SPRITE))
                        {
                            game.c_view[1] += (SPRITE / 2) * zoom;
                        }
                        break;
                    case sf::Keyboard::Space:
                        game.c_view[0] = MAP_WIDTH/2;
                        game.c_view[1] = MAP_HEIGTH/2;
                        break;
                    default:
                        break;
                }
            }
            if (event.type == sf::Event::MouseWheelMoved)
            {
                if (event.mouseWheel.delta < 0)
                {
                    //if (zoom < 5)
                    //{
                        game.m_view.zoom(1.1);
                        zoom = zoom * 1.1f;
                    //}
                }
                else
                {
                    //if (zoom > 1)
                    //{
                        game.m_view.zoom(0.9);
                        zoom = zoom * 0.9f;
                    //}
                }
            }
            game.m_window.clear(sf::Color::Black);
            game.render();
            game.m_window.display();
        }
    }

    return 0;
}