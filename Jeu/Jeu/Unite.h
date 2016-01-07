#pragma once
#include "Arme.h"
#include "Entite.h"
#include "TypeUnite.h"
#include "CouleurJoueur.h"
#include <string>

class Unite : public Entite {

private : 
	int stockRessourceActuel, stockResssourceMax, deplacementMax, champVision, resistance,
		stockMunitionActuel, stockMunitionMax, rangeMin, rangeMax;
	bool aAgi;
	TypeUnite type;

	sf::Sprite getFond(SpriteManager *manager);
	sf::Sprite getIcon(SpriteManager *manager);
	sf::Sprite getIconMaritime(SpriteManager *manager);
	sf::Sprite getIconInfanterie(SpriteManager *manager);
	sf::Sprite getIconMotorise(SpriteManager *manager);
	sf::Sprite getIconAerienne(SpriteManager *manager);

public : 
	Unite(int _x, int _y, std::string _nom, std::string _desc, int _ressMax, int _deplacementMax, int _champVision, TypeUnite _type);

	int getStockMaxRess() const;
	int getDeplacementMax()const;
	int getChampVision()const;
	int getResistance() const;

	void setResistance(int _res);

	int getStockRessActuel()const;
	
	bool peutSeDeplacer(int distance);
	bool peutAgir();

	void reaprovisionnement();
	void prendDegat(int degat);
	void seDeplace(int x, int y);
	void soin();
	bool estDetruit();

	bool isUnite();
	bool isAerienne();
	bool isMotorise();
	bool isInfanterie();
	bool isMaritime();

	void render(sf::RenderWindow *renderWindow, sf::Color color, SpriteManager *manager);
	void update();
};