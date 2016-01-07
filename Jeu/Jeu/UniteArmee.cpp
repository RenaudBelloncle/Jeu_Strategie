#include "UniteArmee.h"

UniteArmee::UniteArmee(int _x, int _y, std::string _nom, std::string _desc, int _ressMax, int _deplacementMax, int _champVision, TypeUnite _type,
	int _munMax, int _rangeMax, int _rangeMin,Arme principale, Arme secondaire, bool bougeEtAttaque) : Unite(_x,_y,_nom, _desc, _ressMax, _deplacementMax, _champVision, _type) 
{
	rangeMin = _rangeMin;
	rangeMax = _rangeMax;
	munMax = _munMax;
	munRestante = munMax;
	armePrincipale = &principale;
	armeSecondaire = &secondaire;
	peutBougerEtAttaquer = bougeEtAttaque;
}

int UniteArmee::getRangeMin()const
{
	return rangeMin;
}

int UniteArmee::getRangeMax()const
{
	return rangeMax;
}

int UniteArmee::getStockMunActuel()const
{
	return munRestante;
}

int UniteArmee::getStockMaxMun()const
{
	return munMax;
}

void UniteArmee::attaque(Entite *ennemi)
{
	std::cout << ennemi->isUnite() << std::endl;
	if (ennemi->isUnite()) {
		std::cout << "Attaque unite !" << std::endl;
		attaqueUnite((Unite*) ennemi);
		std::cout << ennemi->getPvRestant() << std::endl;
	}
	else if (ennemi->isBatiment()) {
		//attaqueBatiment();
	}
}

void UniteArmee::attaqueUnite(Unite *ennemi)
{
	if (ennemi->isAerienne()) {
		if (munRestante > 0) {
			ennemi->prendDegat(armePrincipale->getDegatAerien());
			munRestante--;
		}
		else if (munRestante < 0 && armeSecondaire != NULL){
			ennemi->prendDegat(armeSecondaire->getDegatAerien());
			munRestante--;
		}
	}

	else if (ennemi->isInfanterie()) {
		if (munRestante > 0) {
			ennemi->prendDegat(armePrincipale->getDegatInfanterie());
			munRestante--;
		}
		else if (munRestante < 0 && armeSecondaire != NULL) {
			ennemi->prendDegat(armeSecondaire->getDegatInfanterie());
			munRestante--;
		}
	}

	else if (ennemi->isMaritime()) {
		if (munRestante > 0) {
			ennemi->prendDegat(armePrincipale->getDegatMarin());
			munRestante--;
		}
		else if (munRestante < 0 && armeSecondaire != NULL) {
			ennemi->prendDegat(armeSecondaire->getDegatMarin());
			munRestante--;
		}
	}

	else if (ennemi->isMotorise()) {
		if (munRestante > 0) {
			ennemi->prendDegat(armePrincipale->getDegatMotorise());
			munRestante--;
		}
		else if (munRestante < 0 && armeSecondaire != NULL) {
			ennemi->prendDegat(armeSecondaire->getDegatMotorise());
			munRestante--;
		}
	}
}

bool UniteArmee::getPeutBougerEtAttaquer() {
	return peutBougerEtAttaquer;
}
