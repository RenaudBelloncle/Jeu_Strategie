#pragma once

#include "entite.h"

class Batiment : public Entity
{
public:
	Batiment();
	~Batiment();
	int getTempsConstruction();
	int setTempsContruction(int tempsConstruction);
private:
	int tempsConstruction;
};