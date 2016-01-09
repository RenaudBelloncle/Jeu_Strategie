#pragma once

#include "ProductionsRessource.h"

ProductionRessource::ProductionRessource(int _x, int _y, string _nom, string _desc, Ressource _ressourceStock, int _stockMax, Ressource _ressourceProduite, int _produitParTour) : Batiment(_x, _y, _nom, _desc, _ressourceStock, _stockMax)
{
	ressourceProduite = _ressourceProduite;
	quantiteProduite = _produitParTour;
}

ProductionRessource::~ProductionRessource()
{

}

int ProductionRessource::getQuantiteProduite()
{
	return quantiteProduite;
}

void ProductionRessource::setQuantiteProduite(int _quantiteProduite)
{
	quantiteProduite = _quantiteProduite;
}

Ressource ProductionRessource::getRessourceProduite()
{
	return ressourceProduite;
}

void ProductionRessource::setRessourceProduite(Ressource _ressourceProduite)
{
	ressourceProduite = _ressourceProduite;
}

bool ProductionRessource::isProductionRessource()
{
	return true;
}

void ProductionRessource::update()
{
	setStock(getQuantiteProduite() + getStock());
}