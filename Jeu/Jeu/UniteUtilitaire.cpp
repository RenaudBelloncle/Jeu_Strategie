#include "UniteUtilitaire.h"

UniteUtilitaire::UniteUtilitaire(int _x, int _y, std::string _nom, std::string _desc, int _ressMax, int _deplacementMax, int _champVision, TypeUnite _type,
	int _reaproRestant, int _outilRestant, Outil _outil,bool peutReappro,  bool bougeEtAttaque) : Unite(_x, _y, _nom, _desc, _ressMax, _deplacementMax, _champVision, _type, bougeEtAttaque)
{
	reaproRestante = _reaproRestant;
	outilRestant = _outilRestant;
	outil = _outil;
	peutReaprovisionner = peutReappro;
}

void UniteUtilitaire::reapprovisionne(Unite* unite)
{
	if (peutReaprovisionner) {
		unite->reaprovisionnement();
	}
}

void UniteUtilitaire::chargeUnite(Unite* unite)
{
	if (outil == Outil::transport) {
		uniteTransporté = unite;
	}
}

void UniteUtilitaire::dechargeUnite()
{
	if (outil == Outil::transport) {
		
	}
}

void UniteUtilitaire::convertir(Unite* ennemi)
{

}

void UniteUtilitaire::explorationDeSol()
{

}
