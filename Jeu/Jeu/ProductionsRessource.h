#pragma once

#include "Batiment.h"
#include "Ressource.h"

class ProductionRessource : public Batiment
{
public:
	ProductionRessource(int _x, int _y, string _nom, string _desc, Ressource _ressourceStock, int _stockMax, Ressource _ressourceProduit, int _produitParTour);
	~ProductionRessource();
	int getQuantiteProduite();
	void setQuantiteProduite(int quantiteProduite);
	Ressource getRessourceProduite();
	void setRessourceProduite(Ressource ressource);

	void update();
private:
	int quantiteProduite;
	Ressource ressourceProduite;
};