#pragma once
#include "Unite.h"
#include "Arme.h"
#include <string>

class UniteArmee : public Unite {

private:
	int munMax, munRestante, rangeMax, rangeMin;
	Arme *armePrincipale, *armeSecondaire;

public :
	UniteArmee(int _x, int _y, std::string _nom, std::string _desc, int _ressMax, int _deplacementMax, int _champVision, TypeUnite _type, 
		int _munMax, int _rangeMax, int _rangeMin, Arme principale, Arme secondaire);
	int getRangeMin()const;
	int getRangeMax()const;
	int getStockMunActuel()const;
	int getStockMaxMun()const;
	
	void attaque(Entite *ennemi);
	void attaqueUnite(Unite *ennemi);

	//void attaqueBatiment();
};