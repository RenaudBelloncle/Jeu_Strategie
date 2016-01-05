#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Constantes.h"

bool testClicZoneJeu(int x, int y) {
	// Zone principale
	if (y < WIN_HEIGTH - INTERFACE_HEIGTH)
		return true;
	// Rectangle au dessus de l'interface
	else if (x >= 226 && y >= 469 && y <= 506)
		return true;
	// Triangle au dessus de l'interface
	else if (x < 226 && x >= 177 && y < 506 && y > 469) {
		float coeffDir = (506.0 - 469.0) / (226.0 - 177.0);
		float ordonneeOri = 469 - coeffDir * 177.0;
		std::cout << coeffDir<< std::endl;
		if( y < x*coeffDir + ordonneeOri)
			return true;
	}
	return false;
}

int main()
{
    Game game;

	bool leftPressed(false), rightPressed(false), upPressed(false), downPressed(false);
	//float zoom = SPRITE >> 6;
	float zoom = 1;
	sf::Clock m_clock;

	UniteArmee* infanterie = new UniteArmee(0, 0, "Soldat", "Je suis un test et n'ai aucune raison de vivre", 50, 5, 7, TypeUnite::INFANTERIE, 10, 2, 1,
		Arme("test", 0, 0, 0, 0), Arme("test2", 0, 0, 0, 0));
	UniteArmee* bateau = new UniteArmee(1, 0, "Bateau", "Je suis un test et n'ai aucune raison de vivre", 50, 5, 7, TypeUnite::MARITIME, 10, 2, 1,
		Arme("test", 0, 0, 0, 0), Arme("test2", 0, 0, 0, 0));
	UniteArmee* avion = new UniteArmee(0, 1, "Avion", "Je suis un test et n'ai aucune raison de vivre", 50, 5, 7, TypeUnite::AERIENNE, 10, 2, 1,
		Arme("test", 0, 0, 0, 0), Arme("test2", 0, 0, 0, 0));
	UniteArmee* vehicule = new UniteArmee(1, 1, "Vehicule", "Je suis un test et n'ai aucune raison de vivre", 50, 5, 7, TypeUnite::MOTORISE, 10, 2, 1,
		Arme("test", 0, 0, 0, 0), Arme("test2", 0, 0, 0, 0));
	game.getPlayer()->creerUnite(infanterie);
	game.getPlayer()->creerUnite(bateau);
	game.getPlayer()->creerUnite(avion);
	game.getPlayer()->creerUnite(vehicule);
	sf::Vector2i centreImage(MAP_WIDTH/2,MAP_HEIGTH/2);
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
						if (MAP_WIDTH % 2 == 0)
							game.c_view[0] = (MAP_WIDTH * SPRITE) / 2;
						else
							game.c_view[0] = ((MAP_WIDTH - 1) * SPRITE) / 2;
						if (MAP_HEIGTH % 2 == 0)
							game.c_view[1] = (MAP_HEIGTH * SPRITE) / 2;
						else
							game.c_view[1] = ((MAP_HEIGTH - 1) * SPRITE) / 2;
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

			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					// Zone clique jeu
					if (testClicZoneJeu(event.mouseButton.x, event.mouseButton.y)) {
						sf::Vector2i caseClique(0, 0);
						int nbCaseAfficheParLigne = WIN_WIDTH / SPRITE;
						int nbCaseAfficheParColonne= (WIN_HEIGTH - INTERFACE_HEIGTH) / SPRITE;
						int decalageX = (WIN_WIDTH - (nbCaseAfficheParLigne * SPRITE)) / 2;
						int decalageY = ((WIN_HEIGTH - INTERFACE_HEIGTH) - nbCaseAfficheParColonne * SPRITE)/2;
						for (int i = 0; i < nbCaseAfficheParLigne; i++) {
							for (int j = 0; j < nbCaseAfficheParColonne; j++) {
								if (event.mouseButton.x >= decalageX + i*SPRITE && event.mouseButton.x < decalageX + (i + 1)*SPRITE - 1
									&& event.mouseButton.y < decalageY + (j + 1)*SPRITE - 1 && event.mouseButton.y >= (j*SPRITE) + decalageY) {

									caseClique.y = centreImage.y + (-nbCaseAfficheParLigne/2 + 1 + j);
									caseClique.x = centreImage.x + (-nbCaseAfficheParColonne+1 / 2 + i);

									std::cout << nbCaseAfficheParColonne << std::endl;
									std::cout << nbCaseAfficheParLigne << std::endl;

									std::cout << "X" << caseClique.x << std::endl;
									std::cout << "Y" << caseClique.y << std::endl;

									break;
								}
							}
						}
					}// Zone clique interface
					else {
						if (event.mouseButton.x < 225 && 185 < event.mouseButton.x && event.mouseButton.y < 538 && 523 < event.mouseButton.y) {
							game.m_minimap.changeModeTopo();
						}
						else if (event.mouseButton.x < 225 && 185 < event.mouseButton.x && event.mouseButton.y < 560 && 546 < event.mouseButton.y) {
							game.m_minimap.changeModeRessource();
						}
						else if (event.mouseButton.x < 225 && 185 < event.mouseButton.x && event.mouseButton.y < 683 && 568 < event.mouseButton.y) {
							game.m_minimap.changeModeUnite();
						}
					}
					//std::cout << event.mouseButton.x << std::endl;
					//std::cout << event.mouseButton.y << std::endl;
					sf::Vector2f worldPos = game.m_window.mapPixelToCoords(sf::Mouse::getPosition(game.m_window));
				}
			}

			if (leftPressed)
			{
				if (game.c_view[0] - ((WIN_WIDTH / 2) - SPRITE) > 0)
				{
					//game.c_view[0] -= m_clock.getElapsedTime().asMicroseconds() / 20;
					game.c_view[0] -= SPRITE;
					centreImage.x --;
					std::cout << centreImage.x << std::endl;
					std::cout << centreImage.y << std::endl;
				}
			}

			if (rightPressed)
			{
				if (game.c_view[0] + ((WIN_WIDTH / 2) - SPRITE) < (MAP_WIDTH * SPRITE))
				{
					//game.c_view[0] += m_clock.getElapsedTime().asMicroseconds() / 20;
					game.c_view[0] += SPRITE;
					centreImage.x ++;
					std::cout << centreImage.x << std::endl;
					std::cout << centreImage.y << std::endl;
				}
			}

			if (upPressed)
			{
				if (game.c_view[1] - ((WIN_HEIGTH / 2) - SPRITE) > 0)
				{
					//game.c_view[1] -= m_clock.getElapsedTime().asMicroseconds() / 20;
					game.c_view[1] -= SPRITE;
					centreImage.y --;
					std::cout << centreImage.x << std::endl;
					std::cout << centreImage.y << std::endl;
				}
			}

			if (downPressed)
			{
				if (game.c_view[1] + ((WIN_HEIGTH / 2) - SPRITE) < (MAP_HEIGTH * SPRITE))
				{
					//game.c_view[1] += m_clock.getElapsedTime().asMicroseconds() / 20;
					game.c_view[1] += SPRITE;
					centreImage.y ++;
					std::cout << centreImage.x << std::endl;
					std::cout << centreImage.y << std::endl;
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