#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Constantes.h"

int main()
{
    Game game;

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
                        if (game.c_view[0] - ((WIN_WIDTH/2) - 2*SPRITE) > 0)
                        {
                            game.c_view[0] -= SPRITE / 2;
                        }
                        break;
                    case sf::Keyboard::Right:
                        if (game.c_view[0] - ((WIN_WIDTH/2) - 2*SPRITE) < WIN_WIDTH)
                        {
                            game.c_view[0] += SPRITE / 2;
                        }
                        break;
                    case sf::Keyboard::Up:
                        if (game.c_view[1] - ((WIN_HEIGTH/2) - 2*SPRITE) > 0)
                        {
                            game.c_view[1] -= SPRITE / 2;
                        }
                        break;
                    case sf::Keyboard::Down:
                        if (game.c_view[1] - ((WIN_HEIGTH/2) - 2*SPRITE) < WIN_HEIGTH)
                        {
                            game.c_view[1] += SPRITE / 2;
                        }
                        break;
                    case sf::Keyboard::Escape:
                        game.c_view[0] = WIN_WIDTH/2;
                        game.c_view[1] = WIN_HEIGTH/2;
                        break;
                    default:
                        break;
                }
            }
            if (event.type == sf::Event::MouseWheelMoved)
            {
                if (event.mouseWheel.delta < 0) game.m_view.zoom(1.1);
                else game.m_view.zoom(0.9);
            }
            game.m_window.clear(sf::Color::Black);
            game.print();
            game.m_window.display();
        }
    }

    return 0;
}