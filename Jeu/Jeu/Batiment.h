#pragma once

#include "Entite.h"
#include "Ressource.h"

using namespace std;

class Batiment : public Entite
{
private:
	Ressource ressourceStock;
	int stock, maxStock;
public:
	Batiment(int _x, int _y, string _nom, string _desc, Ressource _ressourceStock, int _maxStock);
    ~Batiment();

	void prendDegat(int degat);
	void seDeplace(int nbCaseDeplace);
	void soin();
	void render(sf::RenderWindow *renderWindow, sf::Color color, SpriteManager *manager);
	void update();
	void setStock(int _stock);
	void setStockMax(int _maxStock);

	bool estDetruit();
	bool isBatiment();
	
	Ressource getRessourceStocked();

	int getStock();
	int getMaxStock();
private:
};