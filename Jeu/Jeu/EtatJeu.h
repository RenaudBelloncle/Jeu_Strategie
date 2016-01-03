#pragma once

#include "Etat.h"

class EtatJeu : public Etat
{
public:
	EtatJeu(Game* jeu, sf::RenderWindow* window);
	~EtatJeu();
	void render();
	void update(int delta);
};