#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Constantes.h"
#include "UniteManager.h"
#include "MenuPrincipal.h"

int main()
{
	UniteManager unites;
    Game game;

	bool leftPressed(false), rightPressed(false), upPressed(false), downPressed(false);
	//float zoom = SPRITE >> 6;
	float zoom = 1;
	sf::Clock m_clock;

	sf::Clock c; //Timer pour les d�placements de la carte � la souris
	int fps_move_mouse = 200; //fps des d�placmeents de la cam�ra � la souris
	int detecte_zone = -1; //zone de d�tection pour la cam�ra � la souris
	game.m_playerActif->creerUnite(unites.creerUnite("Soldat",9,9), game.m_map.getTile(9,9).getBonusRes());
	game.m_playerActif->creerUnite(unites.creerUnite("Transporteur", 10, 10), game.m_map.getTile(10, 10).getBonusRes());
	game.m_playerActif->creerUnite(unites.creerUnite("Colon", 9, 10), game.m_map.getTile(9, 10).getBonusRes());
	game.m_playerActif->creerUnite(unites.creerUnite("Explorateur", 10, 9), game.m_map.getTile(10, 9).getBonusRes());
	game.m_playerActif->creerUnite(unites.creerUnite("Recruteur", 10, 11), game.m_map.getTile(10, 11).getBonusRes());

	game.m_players[1]->creerUnite(unites.creerUnite("SoldatArmee",11,11), game.m_map.getTile(11, 11).getBonusRes());
	game.getPlayerActif()->decouvre();

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
						if (game.m_map.getWidth() % 2 == 0)
							game.c_view[0] = (game.m_map.getWidth() * SPRITE) / 2;
						else
							game.c_view[0] = ((game.m_map.getWidth() - 1) * SPRITE) / 2;
						if (game.m_map.getHeigth() % 2 == 0)
							game.c_view[1] = (game.m_map.getHeigth() * SPRITE) / 2;
						else
							game.c_view[1] = ((game.m_map.getHeigth() - 1) * SPRITE) / 2;
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

			if (event.type == sf::Event::Resized)
			{
				game.resize();
			}

            /*if (event.type == sf::Event::MouseWheelMoved)
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
            }*/

			if (event.type == sf::Event::MouseButtonPressed) {

				if (event.mouseButton.button == sf::Mouse::Left) {
					game.clic(event.mouseButton.x, event.mouseButton.y);
				}
				if (event.mouseButton.button == sf::Mouse::Right) {
					game.deselection();
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				}
			}

			if (leftPressed)
			{
				if (game.c_view[0] - ((WIN_WIDTH / 2) - SPRITE) > 0)
				{
					game.c_view[0] -= SPRITE;
					game.centreImage.x --;
				}
			}

			if (rightPressed)
			{
				if (game.c_view[0] + ((WIN_WIDTH / 2) - SPRITE) < (game.m_map.getWidth() * SPRITE))
				{
					game.c_view[0] += SPRITE;
					game.centreImage.x ++;
				}
			}

			if (upPressed)
			{
				if (game.c_view[1] - ((WIN_HEIGTH / 2) - SPRITE) > 0)
				{
					game.c_view[1] -= SPRITE;
					game.centreImage.y --;
				}
			}

			if (downPressed)
			{
				if (game.c_view[1] + ((WIN_HEIGTH / 2) - SPRITE) < (game.m_map.getHeigth() * SPRITE))
				{
					game.c_view[1] += SPRITE;
					game.centreImage.y ++;
				}
			}
        }

		if (sf::Mouse::getPosition(game.m_window).x <= detecte_zone) {
			if (c.getElapsedTime().asMilliseconds() >= fps_move_mouse && game.c_view[0] - ((WIN_WIDTH / 2) - SPRITE) > 0)
			{
				game.c_view[0] -= SPRITE;
				game.centreImage.x--;
				c.restart();
			}
		}

		if (sf::Mouse::getPosition(game.m_window).x >= WIN_WIDTH - detecte_zone) {
			if (c.getElapsedTime().asMilliseconds() >= fps_move_mouse && game.c_view[0] + ((WIN_WIDTH / 2) - SPRITE) < (game.m_map.getWidth() * SPRITE))
			{
				game.c_view[0] += SPRITE;
				game.centreImage.x ++;
				c.restart();
			}
		}

		if (sf::Mouse::getPosition(game.m_window).y <= detecte_zone + 30 && sf::Mouse::getPosition(game.m_window).y >= 30) {
			if (c.getElapsedTime().asMilliseconds() >= fps_move_mouse && game.c_view[1] - ((WIN_HEIGTH / 2) - SPRITE) > 0)
			{
				game.c_view[1] -= SPRITE;
				game.centreImage.y --;
				c.restart();
			}
		}

		if (sf::Mouse::getPosition(game.m_window).y >= WIN_HEIGTH - detecte_zone - 150 && sf::Mouse::getPosition(game.m_window).y <= WIN_HEIGTH - 150) {
			if (c.getElapsedTime().asMilliseconds() >= fps_move_mouse && game.c_view[1] + ((WIN_HEIGTH / 2) - SPRITE) < (game.m_map.getHeigth() * SPRITE))
			{
				game.c_view[1] += SPRITE;
				game.centreImage.y ++;
				c.restart();
			}
		}

		game.m_window.clear(sf::Color::Black);
		game.render();
		game.m_window.display();
		m_clock.restart();
    }

    return EXIT_SUCCESS;
}
