#include <iostream>

#include "TextureManager.h"
#include "SpriteManager.h"
#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal(sf::RenderWindow *window) {

	m_window = window;

	std::cout << "Chargement du menu principal" << std::endl;
	std::cout << "Chargement des textures" << std::endl;
	
	//if (!font.loadFromFile("media/28_day_later.ttf")) {
	//	std::cout << "[ ERREUR ] Impossible de charger la police du menu" << std::endl;
	//}

	if (!font.loadFromFile("media/constantine.ttf")) {
		std::cout << "[ ERREUR ] Impossible de charger la police du menu" << std::endl;
	}

	nouvellePartie.setFont(font);
	nouvellePartie.setString("Nouvelle Partie");
	nouvellePartie.setColor(sf::Color::Black);
	nouvellePartie.setPosition(100, 400);
	
	std::cout << nouvellePartie.getGlobalBounds().top << std::endl;
	std::cout << nouvellePartie.getGlobalBounds().left << std::endl;
	std::cout << nouvellePartie.getGlobalBounds().height << std::endl;
	std::cout << nouvellePartie.getGlobalBounds().width << std::endl;

	reprendrePartie.setFont(font);
	reprendrePartie.setString("Reprendre Partie");
	reprendrePartie.setColor(sf::Color(127, 127, 127, 255));
	reprendrePartie.setPosition(100, 435);

	option.setFont(font);
	option.setString("Option");
	option.setColor(sf::Color(127, 127, 127, 255));
	option.setPosition(100, 470);

	quitter.setFont(font);
	quitter.setString("Quitter");
	quitter.setColor(sf::Color::Black);
	quitter.setPosition(100, 505);
	
	std::cout << "Chargement des sprites" << std::endl;
}

void MenuPrincipal::render() {

	m_window->clear(sf::Color::White);
	m_window->draw(nouvellePartie);
	m_window->draw(reprendrePartie);
	m_window->draw(option);
	m_window->draw(quitter);
}

bool MenuPrincipal::hitQuitter(int x, int y) {

	if (quitter.getGlobalBounds().left <= x
		&& x <= quitter.getGlobalBounds().left + quitter.getGlobalBounds().width
		&& quitter.getGlobalBounds().top <= y
		&& y <= quitter.getGlobalBounds().top + quitter.getGlobalBounds().height)
		return true;

	return false;
}

bool MenuPrincipal::hitNouvellePartie(int x, int y) {

	if (nouvellePartie.getGlobalBounds().left <= x
		&& x <= nouvellePartie.getGlobalBounds().left + nouvellePartie.getGlobalBounds().width
		&& nouvellePartie.getGlobalBounds().top <= y
		&& y <= nouvellePartie.getGlobalBounds().top + nouvellePartie.getGlobalBounds().height)
		return true;

	return false;
}