#pragma once

#include <SFML/Graphics.hpp>

#define SOLEIL 1
#define	PLUIE 2
#define NEIGE 3

class Meteo {

private:

	int activeMeteo; //vaut 1 si soleil, 2 si pluie, 3 si neige
	
	sf::CircleShape neige;
	sf::RectangleShape pluie;

	std::map<int, sf::Sprite> element;

	sf::RenderWindow *m_window;

public:
	Meteo(sf::RenderWindow *window);
	void change(int nouvelleMeteo);
	void render();
};