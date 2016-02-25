#pragma once
#include "Unite.h"
#include "Batiment.h"
#include "CouleurJoueur.h"
#include "SpriteManager.h"
#include "Technologie.h"
#include <list>
#include <iostream>

class Player {
private : 
	sf::Color couleur;
	int energie;
	int essence;
	int metaux;
	int vivre;
	std::vector<Unite*> listUnite;
	std::vector<Batiment*> listBatiment;
	std::vector<Technologie> listTechnologie;
	bool caseDecouverte[MAP_WIDTH][MAP_HEIGTH];
	bool ressourceDecouverte[MAP_WIDTH][MAP_HEIGTH];

public : 
	Player(sf::Color color);

	int getEnergie();
	int getEssence();
	int getMetaux();
	int getVivre();

	void creerUnite(Unite *unite, int resistance);
	void detruireUnite(int index);

	void initTechnologies();
	void rechercheTechnologie(Technologie* tech);
	vector<Technologie*> getTechnoARechercher();
	
	void creerBatiment(Batiment *batiment);
	void detruireBatiment(int index);
	void render(sf::RenderWindow *renderWindow, SpriteManager *manager, sf::Vector2i nbCase, sf::Vector2i caseCentrale);
	void render(sf::RenderWindow *renderWindow, SpriteManager *manager, Player *player, sf::Vector2i nbCase, sf::Vector2i caseCentrale);
	void update();
	int getNombreUnite();
	int getNombreBatiment();
	Unite* getUnite(int index);
	Batiment* getBatiment(int index);
	sf::Color getColor();
	bool aDecouvertLaCase(int x, int y);
	bool aDecouvertLaRessource(int x, int y);
	void decouvre();
	void decouvreRessource(int x, int y);
};