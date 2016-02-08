#include "Meteo.h"

Meteo::Meteo(sf::RenderWindow *window) {
	
	m_window = window;

	activeMeteo = 1;
	
	neige.setRadius(5);
	neige.setFillColor(sf::Color::White);
	
	neige.setOutlineThickness(2);
	neige.setOutlineColor(sf::Color::Black);

	pluie.setSize(sf::Vector2f(150, 2));
	pluie.setFillColor(sf::Color::Blue);
	pluie.rotate(90);
}

void Meteo::change(int nouvelleMeteo) {
	activeMeteo = nouvelleMeteo;
}

void Meteo::render() {

	if (activeMeteo == NEIGE) {

	}
}
