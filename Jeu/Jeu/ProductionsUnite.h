#pragma once

#include "Batiment.h"
#include "UniteManager.h"
#include <stdarg.h>

class ProductionsUnite : public Batiment
{
private:
	std::map<string, Unite*> unites;
public:
	ProductionsUnite(int _x, int _y, string _nom, string _desc, int _coutEnergie, int _coutVivre, int _coutMetal, int _coutPetrole, ...);
	~ProductionsUnite();
};