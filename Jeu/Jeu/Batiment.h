#pragma once
#include "Entite.h"

class Batiment : public Entite
{
public:
	Batiment();
	~Batiment();
	int getTempsConstruction();
	int setTempsContruction(int tempsConstruction);
private:
	int tempsConstruction;
};