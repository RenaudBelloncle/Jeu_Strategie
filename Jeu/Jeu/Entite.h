#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Constantes.h"
#include "SpriteManager.h"

class Entite
{
private : 
	std::string nom, description;
	int const PV_MAX = 10;
	int pvRestant,coordX, coordY;

public : 
	bool estUnite, estBatiment;
	Entite(int _x, int _y, std::string _nom,std::string _desc);

	std::string getNom() const;
	std::string getDescription() const;
	int getPvRestant() const;
	int getCoordX() const;
	int getCoordY() const; 
	void setCoord(int x, int y);
	void setPvRestant(int pv);
	void virtual prendDegat(int degat) = 0;
	void virtual soin() = 0;
	bool virtual estDetruit() = 0;

	bool isUnite();
	bool isBatiment();

	void virtual render(sf::RenderWindow *renderWindow, sf::Color color, SpriteManager *manager) = 0;
	void virtual update() = 0;
};