#pragma once

#include <SFML/Graphics.hpp>
#include "jeu.h"

class Etat
{
public:
	Etat();
	virtual ~Etat() = 0;
	virtual void render() = 0;
	virtual void update(int delta) = 0;
protected:
	Jeu* jeu;
	sf::RenderWindow* window;
};