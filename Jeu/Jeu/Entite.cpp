#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entite.h"

Entite::Entite(int _x, int _y, std::string _nom, std::string _desc) {
	estUnite = false;
	estBatiment = false;
	nom = _nom;
	description = _desc;
	pvRestant = PV_MAX;
	coordX = _x;
	coordY = _y;
}

std::string Entite::getNom() const{
	return nom;
}

std::string Entite::getDescription() const{
	return description;
}

int Entite::getPvRestant() const {
	return pvRestant;
}

int Entite::getCoordX() const {
	return coordX;
}

void Entite::setCoord(int x, int y) {
	coordX = x; 
	coordY = y;
}

int Entite::getCoordY() const {
	return coordY;
}

void Entite::setPvRestant(int pv){
	pvRestant = pv;
}

bool Entite::isUnite() {
	return estUnite;
}

bool Entite::isBatiment() {
	return estBatiment;
}

