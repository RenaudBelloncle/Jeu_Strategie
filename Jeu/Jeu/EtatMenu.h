#pragma once

#include "Etat.h"

class EtatMenu : public Etat
{
public:
	EtatMenu(Game* jeu, sf::RenderWindow* window);
	~EtatMenu();
	void render();
	void update(int delta);
};