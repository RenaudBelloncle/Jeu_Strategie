#pragma once
#include "Arme.h"
#include "Entite.h"
#include "TypeUnite.h"
#include "CouleurJoueur.h"
#include <string>

class Unite : public Entite {

private : 
	int stockRessourceActuel, stockResssourceMax, deplacementMax, champVision, resistance;
	TypeUnite type;

	//void animation(int x, int y, sf::RenderWindow *renderWindow, sf::Color color, SpriteManager *manager);
	sf::Sprite getFond(SpriteManager *manager);
	sf::Sprite getIcon(SpriteManager *manager);
	sf::Sprite getIconMaritime(SpriteManager *manager);
	sf::Sprite getIconInfanterie(SpriteManager *manager);
	sf::Sprite getIconMotorise(SpriteManager *manager);
	sf::Sprite getIconAerienne(SpriteManager *manager);
	bool peutBougerEtAttaquer;
protected:
	bool aAgi;
public :
	bool estArmee, estUtilitaire;

	Unite(int _x, int _y, std::string _nom, std::string _desc, int _ressMax, int _deplacementMax, int _champVision, TypeUnite _type,bool _moveEtAttack);

	int getStockMaxRess() const;
	int getDeplacementMax()const;
	int getChampVision()const;
	int getResistance();

	void setResistance(int _res);

	int getStockRessActuel();
	
	bool getPeutBougerEtAttaquer();
	bool peutSeDeplacer(int distance);
	bool peutAgir();
	bool getPeutBougerEtAttaquer();

	void reaprovisionnement();
	void prendDegat(int degat);
	void seDeplace(int x, int y, sf::RenderWindow *renderWindow, sf::Color color, SpriteManager *manager);
	void soin();
	bool estDetruit();

	bool isArmee() { return estArmee; }
	bool isUtilitaire(){ return estUtilitaire; }
	bool isAerienne();
	bool isMotorise();
	bool isInfanterie();
	bool isMaritime();

	void render(sf::RenderWindow *renderWindow, sf::Color color, SpriteManager *manager);
	void update();
};