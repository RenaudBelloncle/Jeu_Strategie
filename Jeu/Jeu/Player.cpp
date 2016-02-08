#include "Player.h"
#include <iostream>

Player::Player(sf::Color color) {
	couleur = color;
	initTechnologies();

    energie = 10;
    essence = 10;
    metaux = 10;
    vivre = 10;
}

int Player::getEnergie() {
    return energie;
}

int Player::getEssence() {
    return essence;
}

int Player::getMetaux() {
    return metaux;
}

int Player::getVivre() {
    return vivre;
}

void Player::creerUnite(Unite *unite,int resistance) {
	unite->setResistance(resistance);
	listUnite.push_back(unite);
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGTH; j++) {
			caseDecouverte[i][j] = false;
			ressourceDecouverte[i][j] = false; 
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

	Technologie recherche("Description","Recherche", 0, 0, 0, 0);
	Technologie exploration("Description","Exploration", 0, 0, 0, 0);
	Technologie vivres("Description","Vivres", 0, 0, 0, 0);
	Technologie petrole("Description","Petrole", 0, 0, 0, 0);
	Technologie caserne("Description","Caserne", 0, 0, 0, 0);
	Technologie avantPoste("Description","Avant poste", 0, 0, 0, 0);
	Technologie recrutement("Description","Recrutement", 0, 0, 0, 0);
	Technologie metal("Description","Metal", 0, 0, 0, 0);
	Technologie soldat("Description","Soldat", 0, 0, 0, 0);
	Technologie demolisseur("Description","Demolisseur", 0, 0, 0, 0);
	Technologie usine("Description","Usine", 0, 0, 0, 0);
	Technologie aeroport("Description","Aeroport", 0, 0, 0, 0);
	Technologie port("Description","Port", 0, 0, 0, 0);
	Technologie jeep("Description","Jeep", 0, 0, 0, 0);
	Technologie charAssault("Description","Char", 0, 0, 0, 0);
	Technologie artillerie("Description","Artillerie", 0, 0, 0, 0);
	Technologie dca("Description","DCA", 0, 0, 0, 0);
	Technologie chasseur("Description","Chasseur", 0, 0, 0, 0);
	Technologie bombardier("Description","Bombardier", 0, 0, 0, 0);
	Technologie helicoptere("Description","Helicoptere", 0, 0, 0, 0);
	Technologie cuirasse("Description","Cuirasse", 0, 0, 0, 0);
	Technologie torpilleur("Description","Torpilleur", 0, 0, 0, 0);
	Technologie corvette("Description","Corvette", 0, 0, 0, 0);
	Technologie vivresStock("Description","Stockage de vivres", 0, 0, 0, 0);
	Technologie petroleStock("Description","Stockage de petrole", 0, 0, 0, 0);
	Technologie metalStock("Description","Stockage de metaux", 0, 0, 0, 0);
	Technologie transportTerrestre("Description","Transport Terrestre", 0, 0, 0, 0);
	Technologie transportMarin("Description","Transport Marin", 0, 0, 0, 0);
	Technologie transportAerien("Description","Transport Aerien", 0, 0, 0, 0);

	listTechnologie.push_back(recherche);
	listTechnologie.push_back(exploration);
	listTechnologie.push_back(vivres);
	listTechnologie.push_back(petrole);
	listTechnologie.push_back(caserne);
	listTechnologie.push_back(avantPoste);
	listTechnologie.push_back(recrutement);
	listTechnologie.push_back(metal);
	listTechnologie.push_back(soldat);
	listTechnologie.push_back(demolisseur);
	listTechnologie.push_back(usine);
	listTechnologie.push_back(aeroport);
	listTechnologie.push_back(port);
	listTechnologie.push_back(jeep);
	listTechnologie.push_back(charAssault);
	listTechnologie.push_back(artillerie);
	listTechnologie.push_back(dca);
	listTechnologie.push_back(chasseur);
	listTechnologie.push_back(bombardier);
	listTechnologie.push_back(helicoptere);
	listTechnologie.push_back(cuirasse);
	listTechnologie.push_back(torpilleur);
	listTechnologie.push_back(corvette);
	listTechnologie.push_back(vivresStock);
	listTechnologie.push_back(petroleStock);
	listTechnologie.push_back(metalStock);
	listTechnologie.push_back(transportTerrestre);
	listTechnologie.push_back(transportMarin);
	listTechnologie.push_back(transportAerien);

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

void Player::rechercheTechnologie(Technologie* tech) {
	if (tech->verifierCoutTechnologie(energie, essence, metaux, vivre) && tech->verifierSiRecherchable()) {
		tech->setEstRecherche(true);
	}
}

vector<Technologie*> Player::getTechnoARechercher() {
	std::vector<Technologie*> listTechRech;
	for (Technologie & technologie : listTechnologie)
	{
		if (technologie.verifierSiRecherchable())
		{
			listTechRech.push_back(&technologie);
		}
	}

	return  listTechRech;
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

bool Player::aDecouvertLaRessource(int x, int y) {
	return ressourceDecouverte[x][y];
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

void Player::decouvreRessource(int x, int y) {
	for (int i = x-1; i < x + 1; i++) {
		if (0 < i && i < MAP_WIDTH) {
			for (int j = y - 1; j < y + 1; j++) {
				if (0 < j && j < MAP_HEIGTH) {
					ressourceDecouverte[i][j] = true;
				}
			}
		}
	}
}
