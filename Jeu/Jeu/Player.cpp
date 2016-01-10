#include "Player.h"
#include <iostream>

Player::Player(sf::Color color) {
	couleur = color;
}

void Player::creerUnite(Unite *unite,int resistance) {
	unite->setResistance(resistance);
	listUnite.push_back(unite);
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGTH; j++) {
			caseDecouverte[i][j] = false;
		}
	}
}

void Player::detruireUnite(int index) {
	listUnite.erase(listUnite.begin() + index );
}

void Player::creerBatiment(Batiment* batiment) {
	listBatiment.push_back(batiment);
}

void Player::detruireBatiment(int index) {
	listBatiment.erase(listBatiment.begin() + index );
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
void Player::initTechnologies() {

	Technologie recherche("Recherche", "Permet de débloquer la bibliothèque et la recherche de technologies.", 0, 0, 0, 0);
	Technologie exploration("Exploration", "Description", 0, 0, 0, 0);
	Technologie vivres("Vivres", "Description", 0, 0, 0, 0);
	Technologie petrole("Pétrole", "Description", 0, 0, 0, 0);
	Technologie caserne("Caserne", "Description", 0, 0, 0, 0);
	Technologie avantPoste("Avant poste", "Description", 0, 0, 0, 0);
	Technologie recrutement("Recrutement", "Description", 0, 0, 0, 0);
	Technologie metal("Métal", "Description", 0, 0, 0, 0);
	Technologie soldat("Soldat", "Description", 0, 0, 0, 0);
	Technologie demolisseur("Démolisseur", "Description", 0, 0, 0, 0);
	Technologie usine("Usine", "Description", 0, 0, 0, 0);
	Technologie aeroport("Aéroport", "Description", 0, 0, 0, 0);
	Technologie port("Port", "Description", 0, 0, 0, 0);
	Technologie jeep("Jeep", "Description", 0, 0, 0, 0);
	Technologie charAssault("Char", "Description", 0, 0, 0, 0);
	Technologie artillerie("Artillerie", "Description", 0, 0, 0, 0);
	Technologie dca("DCA", "Description", 0, 0, 0, 0);
	Technologie chasseur("Chasseur", "Description", 0, 0, 0, 0);
	Technologie bombardier("Bombardier", "Description", 0, 0, 0, 0);
	Technologie helicoptere("Hélicoptère", "Description", 0, 0, 0, 0);
	Technologie cuirasse("Cuirasse", "Description", 0, 0, 0, 0);
	Technologie torpilleur("Torpilleur", "Description", 0, 0, 0, 0);
	Technologie corvette("Corvette", "Description", 0, 0, 0, 0);
	Technologie vivresStock("Stockage de vivres", "Description", 0, 0, 0, 0);
	Technologie petroleStock("Stockage de pétrole", "Description", 0, 0, 0, 0);
	Technologie metalStock("Stockage de métaux", "Description", 0, 0, 0, 0);
	Technologie transportTerrestre("Transport Terrestre", "Description", 0, 0, 0, 0);
	Technologie transportMarin("Transport Marin", "Description", 0, 0, 0, 0);
	Technologie transportAerien("Transport Aérien", "Description", 0, 0, 0, 0);

	recherche.setTechSuivante(exploration);
	recherche.setTechSuivante(vivres);
	exploration.setTechSuivante(avantPoste);
	exploration.setTechSuivante(recrutement);
	vivres.setTechSuivante(vivresStock);
	vivres.setTechSuivante(caserne);
	vivres.setTechSuivante(petrole);
	vivres.setTechSuivante(metal);
	caserne.setTechSuivante(soldat);
	caserne.setTechSuivante(demolisseur);
	petrole.setTechSuivante(petroleStock);
	petrole.setTechSuivante(usine);
	metal.setTechSuivante(petroleStock);
	metal.setTechSuivante(metalStock);
	usine.setTechSuivante(aeroport);
	usine.setTechSuivante(port);
	usine.setTechSuivante(jeep);
	usine.setTechSuivante(charAssault);
	usine.setTechSuivante(artillerie);
	usine.setTechSuivante(dca);
	usine.setTechSuivante(transportTerrestre);
	aeroport.setTechSuivante(chasseur);
	aeroport.setTechSuivante(bombardier);
	aeroport.setTechSuivante(helicoptere);
	aeroport.setTechSuivante(transportAerien);
	port.setTechSuivante(cuirasse);
	port.setTechSuivante(torpilleur);
	port.setTechSuivante(corvette);
	port.setTechSuivante(transportMarin);


	demolisseur.setTechPrecedente(caserne);
	soldat.setTechPrecedente(caserne);
	caserne.setTechPrecedente(vivres);
	vivresStock.setTechPrecedente(vivres);
	petrole.setTechPrecedente(vivres);
	metal.setTechPrecedente(vivres);
	metalStock.setTechPrecedente(metal);
	petroleStock.setTechPrecedente(petrole);
	usine.setTechPrecedente(petrole);
	usine.setTechPrecedente(metal);
	aeroport.setTechPrecedente(usine);
	port.setTechPrecedente(usine);
	jeep.setTechPrecedente(usine);
	charAssault.setTechPrecedente(usine);
	artillerie.setTechPrecedente(usine);
	dca.setTechPrecedente(usine);
	transportTerrestre.setTechPrecedente(usine);
	chasseur.setTechPrecedente(aeroport);
	bombardier.setTechPrecedente(aeroport);
	helicoptere.setTechPrecedente(aeroport);
	transportAerien.setTechPrecedente(aeroport);
	cuirasse.setTechPrecedente(port);
	torpilleur.setTechPrecedente(port);
	corvette.setTechPrecedente(port);
	transportMarin.setTechPrecedente(port);
	vivres.setTechPrecedente(recherche);
	exploration.setTechPrecedente(recherche);
	avantPoste.setTechPrecedente(exploration);
	recrutement.setTechPrecedente(exploration);
}

void Player::rechercheTechnologie(Technologie *tech) {
	if (tech->verifierCoutTechnologie(energie, essence, metaux, vivre) && tech->verifierSiRecherchable()) {
		tech->setEstRecherche(true);
	}
}

void Player::render(sf::RenderWindow *renderWindow, SpriteManager *manager, sf::Vector2i nbCase, sf::Vector2i caseCentrale) {

	for (unsigned int i = 0; i < listUnite.size(); i++) {
		if (caseCentrale.x - ((nbCase.x / 2) + 1) <= listUnite[i]->getCoordX() && listUnite[i]->getCoordX() <= caseCentrale.x + ((nbCase.x / 2) + 1)) {
			if (caseCentrale.y - ((nbCase.y / 2) + 2) < listUnite[i]->getCoordY() && listUnite[i]->getCoordY() < caseCentrale.y + ((nbCase.y / 2) + 2)) {
				listUnite[i]->render(renderWindow, couleur, manager);
			}
		}
	}
	for (unsigned int i = 0; i < listBatiment.size(); i++) {
		if (caseCentrale.x - ((nbCase.x / 2) + 1) <= listBatiment[i]->getCoordX() && listBatiment[i]->getCoordX() <= caseCentrale.x + ((nbCase.x / 2) + 1)) {
			if (caseCentrale.y - ((nbCase.y / 2) + 2) < listBatiment[i]->getCoordY() && listBatiment[i]->getCoordY() < caseCentrale.y + ((nbCase.y / 2) + 2)) {
				listBatiment[i]->render(renderWindow, couleur, manager);
			}
		}
	}
}

void Player::render(sf::RenderWindow *renderWindow, SpriteManager *manager, Player *player, sf::Vector2i nbCase, sf::Vector2i caseCentrale) {
	for (unsigned int i = 0; i < listUnite.size(); i++) {
		if (player->aDecouvertLaCase(listUnite[i]->getCoordX(), listUnite[i]->getCoordY())) {
			if (caseCentrale.x - ((nbCase.x / 2) + 1) <= listUnite[i]->getCoordX() && listUnite[i]->getCoordX() <= caseCentrale.x + ((nbCase.x / 2) + 1)) {
				if (caseCentrale.y - ((nbCase.y / 2) + 2) < listUnite[i]->getCoordY() && listUnite[i]->getCoordY() < caseCentrale.y + ((nbCase.y / 2) + 2)) {
					listUnite[i]->render(renderWindow, couleur, manager);
				}
			}
		}
	}
	for (unsigned int i = 0; i < listBatiment.size(); i++) {
		if (player->aDecouvertLaCase(listBatiment[i]->getCoordX(), listBatiment[i]->getCoordY())) {
			if (caseCentrale.x - ((nbCase.x / 2) + 1) <= listBatiment[i]->getCoordX() && listBatiment[i]->getCoordX() <= caseCentrale.x + ((nbCase.x / 2) + 1)) {
				if (caseCentrale.y - ((nbCase.y / 2) + 2) < listBatiment[i]->getCoordY() && listBatiment[i]->getCoordY() < caseCentrale.y + ((nbCase.y / 2) + 2)) {
					listBatiment[i]->render(renderWindow, couleur, manager);
				}
			}
		}
	}
}

void Player::update() {
	for (unsigned int i = 0; i < listUnite.size(); i++) {
		listUnite[i]->update();
	}
}

bool Player::aDecouvertLaCase(int x, int y) {
	return caseDecouverte[x][y];
}

void Player::decouvre() {
	for (unsigned int i = 0; i < listUnite.size(); i++) {
		Unite* unite = listUnite[i];
		for (int j = unite->getCoordY() - unite->getChampVision(); j < unite->getCoordY() + unite->getChampVision(); j++) {
			if (j >= 0 && j < MAP_HEIGTH) {
				for (int k = 1 + unite->getCoordX() - (unite->getChampVision() - abs(j - unite->getCoordY())); k < unite->getCoordX() + (unite->getChampVision() - abs(j - unite->getCoordY()));k++) {
					if (k >= 0 && k < MAP_WIDTH) {
						caseDecouverte[k][j] = true;
					}
				}
			}
		}
	}
}