#include <cstdio>
#include <cstdlib>
#include "Technologie.h"

Technologie::Technologie() { }

Technologie::Technologie(std::string _description,std::string _nom, int _coutEnergie, int _coutVivre, int _coutMetal, int _coutPetrole)
{
	description = _description;
	nom = _nom;
	coutEnergie = _coutEnergie;
	coutMetal = _coutMetal;
	coutPetrole = _coutPetrole;
	coutVivre = _coutVivre;
	estRecherche = false;
}

bool Technologie::verifierCoutTechnologie(int energie, int essence, int metaux, int vivre)
{
	return coutEnergie <= energie && coutPetrole <= essence
		   && coutMetal <= metaux && coutVivre <= vivre;
}

bool Technologie::verifierSiRecherchable() {
    if (estRecherche) return false;
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

std::string Technologie::getDescription(){
	return description;
}

std::string Technologie::getNom(){
	return nom;
}

int Technologie::getCoutEnergie() {
	return coutEnergie;
}

int Technologie::getCoutVivre() {
	return coutVivre;
}

int Technologie::getCoutPetrole() {
	return coutPetrole;
}

int Technologie::getCoutMetal() {
	return coutMetal;
}