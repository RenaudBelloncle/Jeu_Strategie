#include "Player.h"
#include <iostream>

Player::Player(sf::Color color) {
	couleur = color;
}

void Player::creerUnite(Unite *unite, int x, int y) {
	std::cout << unite->getNom() << std::endl;
	unite->setCoord(x, y);
	listUnite.push_back(unite);
}
/*
void Player::creerBatiment(Batiment batiment) {

}

void Player::detruireBatiment(Batiment batiement) {

}
*/
void Player::deplacerUnite(Unite *unite, int newX, int newY) {

}

void Player::attaquer(Unite *unite, Entite *ennemi) {

}

int Player::getNombreUnite() {
	return listUnite.size();
}

Unite* Player::getUnite(int index) {
	return listUnite[index];
}

int Player::getNombreBatiment() {
	return listBatiment.size();
}

Batiment* Player::getBatiment(int index) {
	return listBatiment[index];
}

sf::Color Player::getColor() {
	return couleur;
}

void Player::render(sf::RenderWindow *renderWindow, SpriteManager *manager) {

	for (unsigned int i = 0; i < listUnite.size(); i++) {
		listUnite[i]->render(renderWindow, couleur, manager);
	}
	/*for (std::list<Batiment>::iterator it = listBatiment.begin(); it != listBatiment.end(); ++it) {
		it->render(renderWindow);
	}*/
}