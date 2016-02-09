#pragma once
#include "Unite.h"
#include "Outil.h"
#include "Player.h"
#include <string>

class UniteUtilitaire : public Unite {

private:
	int reaproRestante, outilRestant;
	Outil outil;
	bool peutReaprovisionner;
	Unite* uniteTransporté;

public:
	UniteUtilitaire(int _x, int _y, std::string _nom, std::string _desc, int _ressMax, int _deplacementMax, int _champVision, TypeUnite _type,
		int _reaproRestant, int _outilRestant, Outil _outil,bool peutReappro, bool bougeEtAttaque);
	
	void reapprovisionne(Unite* unite);
	void chargeUnite(Unite* unite);
	void dechargeUnite(int x, int y);
	void convertir(Unite* ennemi, Player* joueur, Player* joueurEnnemi);
	void explorationDeSol(Player *joueur);
	void creationVille(Player *player);
};