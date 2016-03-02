#pragma once

#include "Batiment.h"
#include "Ressource.h"

class ProductionRessource : public Batiment
{
public:
	ProductionRessource(int _x, int _y, string _nom, string _desc, Ressource _ressourceStock, int _stockMax, Ressource _ressourceProduit, int _produitParTour, int _coutEnergie, int _coutVivre, int _coutMetal, int _coutPetrole);
	~ProductionRessource();
	int getQuantiteProduite();
	void setQuantiteProduite(int quantiteProduite);
	Ressource getRessourceProduite();
	void setRessourceProduite(Ressource ressource);
	bool isProductionRessource();

	void update();
private:
	int quantiteProduite;
	Ressource ressourceProduite;
};