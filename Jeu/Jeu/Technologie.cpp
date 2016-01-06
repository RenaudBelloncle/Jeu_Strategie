#include <cstdio>
#include <cstdlib>
#include "Technologie.h"

Technologie::Technologie(std::string _nom, std::string _description, int _coutEnergie, int _coutVivre, int _coutMetal, int _coutPetrole): coutEnergie(_coutEnergie)
{
	nom = _nom;
	description = _description;
	coutEnergie = _coutEnergie;
	coutMetal = _coutMetal;
	coutPetrole = _coutPetrole;
	coutVivre = _coutVivre;
	estRecherche = false;
}

bool Technologie::verifierCoutTechnologie(int energie, int essence, int metaux, int vivre)
{
	if (coutEnergie <= energie && coutPetrole <= essence
		&& coutMetal <= metaux && coutVivre <= vivre) return true;
	return false;
}

bool Technologie::verifierSiRecherchable() {
	for (int compteur(0); compteur < techPrecedente.size(); compteur++) {
		if (!techPrecedente[compteur].getEstRecherche()) {
			return false;
		}
	}
	return true;
}

bool Technologie::getEstRecherche() {
	return estRecherche;
}

void Technologie::setEstRecherche(bool status) {
	estRecherche = status;
}

void Technologie::setTechSuivante(Technologie suivante)
{
	techSuivante.push_back(suivante);
}

void Technologie::setTechPrecedente(Technologie precedente)
{
	techPrecedente.push_back(precedente);
}