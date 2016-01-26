#pragma once

class MenuPrincipal {

private:
	sf::Font font;

	sf::Text nouvellePartie;
	sf::Text reprendrePartie;
	sf::Text option;
	sf::Text quitter;

	sf::RenderWindow *m_window;

	bool active;

public:
	MenuPrincipal(sf::RenderWindow *window);
	void render();

	bool hitQuitter(int x, int y);
	bool hitNouvellePartie(int x, int y);
};