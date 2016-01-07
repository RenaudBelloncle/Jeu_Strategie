#include "Player.h"
#include <iostream>

Player::Player(sf::Color color) {
	couleur = color;
}

void Player::creerUnite(Unite *unite, int x, int y,int resistance) {
	unite->setResistance(resistance);
	unite->setCoord(x, y);
	listUnite.push_back(unite);
}

void Player::detruireUnite(int index) {
	listUnite.erase(listUnite.begin() + (index -1));
}
/*
void Player::creerBatiment(Batiment batiment) {

}
*/
void Player::detruireBatiment(int index) {
	listBatiment.erase(listBatiment.begin() + (index -1));
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

void Player::update() {
	for (unsigned int i = 0; i < listUnite.size(); i++) {
		listUnite[i]->update();
	}
}