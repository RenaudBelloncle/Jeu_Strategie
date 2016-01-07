#pragma once
#include <stack>
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"

class Interface
{
private:
	bool modeNormal, modeUnite, modeBatiment;
public:
	Interface();

	bool getModeNormal();
	bool getModeUnite();
	bool getModeBatiment();

	void setModeNormal();
	void setModeUnite();
	void setModeBatiment();

	void render(sf::RenderWindow *renderWindow,SpriteManager *manager);
};