#include "Game.h"
#include "Constantes.h"
#include "Button.h"

void Game::loadTextures() {
	m_textureManager.loadTexture("unite","media/res/SpriteSheetUnite.png");
	m_textureManager.getRef("unite").setSmooth(true);
	m_textureManager.loadTexture("interface", "media/res/Interface.png");
	m_textureManager.loadTexture("interfaceBarre", "media/res/InterfaceBarre.png");
	m_textureManager.loadTexture("tile", "media/res/Tile.png");
	m_textureManager.loadTexture("ressource", "media/res/Ressource.png");
	m_textureManager.loadTexture("filtre", "media/res/Filtre.png");
	m_textureManager.loadTexture("ui", "media/res/Ui.png");
	m_textureManager.loadTexture("gui", "media/res/gui.png");
}

void Game::loadSprites()
{
	m_spriteManager.loadSprite("vie", m_textureManager.getRef("ui"), 128, 10, 0, 1);
	m_spriteManager.loadSprite("vieEnleve", m_textureManager.getRef("ui"), 128, 10, 0, 0);

	m_spriteManager.loadSprite("interface", m_textureManager.getRef("interface"), 800, 200, 0, 0);
	m_spriteManager.getRef("interface").setPosition(0, WIN_HEIGTH - 200);

	m_spriteManager.loadSprite("filtre selection", m_textureManager.getRef("filtre"), 128, 128, 0, 0);
	m_spriteManager.loadSprite("filtre attaque", m_textureManager.getRef("filtre"), 128, 128, 1, 0);
	m_spriteManager.loadSprite("filtre deplacement", m_textureManager.getRef("filtre"), 128, 128, 0, 1);
	m_spriteManager.loadSprite("filtre agi", m_textureManager.getRef("filtre"), 128, 128, 1, 1);

	m_spriteManager.loadSprite("interfaceBarre", m_textureManager.getRef("interfaceBarre"), 800, 60, 0, 0);
	m_spriteManager.getRef("interfaceBarre").setPosition(0, 0);

	m_spriteManager.loadSprite("petrole",m_textureManager.getRef("ressource"),32,32,0,0);
	m_spriteManager.loadSprite("vivre", m_textureManager.getRef("ressource"), 32, 32, 1, 0);
	m_spriteManager.loadSprite("metal", m_textureManager.getRef("ressource"), 32, 32, 0,1);
	m_spriteManager.loadSprite("void", m_textureManager.getRef("ressource"), 32, 32, 1, 1);

	m_spriteManager.loadSprite("plaine", m_textureManager.getRef("tile"), 128, 128, 0, 0);
	m_spriteManager.loadSprite("plage", m_textureManager.getRef("tile"), 128, 128, 1, 0);
	m_spriteManager.loadSprite("montagne", m_textureManager.getRef("tile"), 128, 128, 2, 0);
	m_spriteManager.loadSprite("mer", m_textureManager.getRef("tile"), 128, 128, 3, 0);
	m_spriteManager.loadSprite("foret", m_textureManager.getRef("tile"), 128, 128, 4,0);
	m_spriteManager.loadSprite("marais", m_textureManager.getRef("tile"), 128, 128, 5, 0);
	m_spriteManager.loadSprite("coline", m_textureManager.getRef("tile"), 128, 128, 6, 0);
	m_spriteManager.loadSprite("ville", m_textureManager.getRef("tile"), 128, 128, 7,0);
	m_spriteManager.loadSprite("ruine", m_textureManager.getRef("tile"), 128, 128, 8, 0);

	m_spriteManager.loadSprite("infanterie", m_textureManager.getRef("unite"), 128, 128, 0, 0);
	m_spriteManager.loadSprite("soldat", m_textureManager.getRef("unite"), 128, 128, 1, 0);
	m_spriteManager.loadSprite("soldat_arme", m_textureManager.getRef("unite"), 128, 128, 2, 0);
	m_spriteManager.loadSprite("demolisseur", m_textureManager.getRef("unite"), 128, 128, 3, 0);
	m_spriteManager.loadSprite("colon", m_textureManager.getRef("unite"), 128, 128, 3, 0);
	m_spriteManager.loadSprite("recruteur", m_textureManager.getRef("unite"), 128, 128, 3, 0);
	m_spriteManager.loadSprite("explorateur", m_textureManager.getRef("unite"), 128, 128, 3, 0);

	m_spriteManager.loadSprite("maritime", m_textureManager.getRef("unite"), 128, 128, 0, 1);

	m_spriteManager.loadSprite("motorise", m_textureManager.getRef("unite"), 128, 128, 0, 2);
	m_spriteManager.loadSprite("artillerie", m_textureManager.getRef("unite"), 128, 128, 1, 2);
	m_spriteManager.loadSprite("transporteur", m_textureManager.getRef("unite"), 128, 128, 1, 2);

	m_spriteManager.loadSprite("aerien", m_textureManager.getRef("unite"), 128, 128, 0, 3);

	m_spriteManager.loadSprite("gui_haut_gauche", m_textureManager.getRef("gui"), 10, 30, 0, 0);
	m_spriteManager.loadSprite("gui_haut_milieu", m_textureManager.getRef("gui"), 10, 30, 1, 0);
	m_spriteManager.loadSprite("gui_haut_droite", m_textureManager.getRef("gui"), 10, 30, 2, 0);
	m_spriteManager.loadSprite("gui_centre_gauche", m_textureManager.getRef("gui"), 10, 30, 3, 0);
	m_spriteManager.loadSprite("gui_centre_milieu", m_textureManager.getRef("gui"), 10, 30, 4, 0);
	m_spriteManager.loadSprite("gui_centre_droite", m_textureManager.getRef("gui"), 10, 30, 5, 0);
	m_spriteManager.loadSprite("gui_bas_gauche", m_textureManager.getRef("gui"), 10, 30, 6, 0);
	m_spriteManager.loadSprite("gui_bas_milieu", m_textureManager.getRef("gui"), 10, 30, 7, 0);
	m_spriteManager.loadSprite("gui_bas_droite", m_textureManager.getRef("gui"), 10, 30, 8, 0);
}

Game::Game()
	: meteo(&m_window), menu_p(&m_window)
{
	gameState = 1;
	brouillardDeGuerre = false;
	m_uniteSelectionne = NULL;
	m_batimentSelectionne = NULL;
	m_tour = 0;
	m_winSize = sf::Vector2f(WIN_WIDTH, WIN_HEIGTH);
	std::cout << "Chargement des textures ..." << std::endl;
    loadTextures();
	std::cout << "Chargement des textures termine" << std::endl;
	std::cout << "Chargement des sprites ..." << std::endl;
	loadSprites();
	std::cout << "Chargement des sprites termine" << std::endl;
	m_map = Map(MAP_WIDTH,MAP_HEIGTH);
	m_minimap = Minimap(&m_map);
	m_interface = new Interface(m_winSize.x, m_winSize.y);
    m_window.create(sf::VideoMode(m_winSize.x,m_winSize.y), "Jeu de Strategie");
	centreImage.x = MAP_WIDTH / 2; centreImage.y = MAP_HEIGTH / 2;
	m_tileSize = SPRITE;
	m_batimentManager = BatimentManager(&UniteManager());
	if (MAP_WIDTH % 2 == 0)
		c_view[0] = (MAP_WIDTH * m_tileSize) / 2;
	else
		c_view[0] = ((MAP_WIDTH-1) * m_tileSize) / 2;
	if (MAP_HEIGTH % 2 == 0)
		c_view[1] = (MAP_HEIGTH * m_tileSize) / 2;
	else
		c_view[1] = ((MAP_HEIGTH - 1) * m_tileSize) / 2;

    m_view = sf::View(sf::Vector2f((float)c_view[0],(float)c_view[1]),sf::Vector2f(m_winSize.x,m_winSize.y));
	m_viewInterface = sf::View(sf::Vector2f(m_winSize.x/2, m_winSize.y/2), sf::Vector2f(m_winSize.x, m_winSize.y));
	m_viewMinimap = sf::View(sf::Vector2f(m_winSize.x / 2, m_winSize.y / 2), sf::Vector2f(m_winSize.x, m_winSize.y));
    //m_view.zoom(SPRITE >> 6);

    m_window.setFramerateLimit(60);
	m_nbJoueur = 2;
	m_players = new Player*[m_nbJoueur];
 	m_players[0] = new Player(sf::Color(127,127,127));
	m_players[1] = new Player(sf::Color(0, 127, 127));
	m_numJoueurActif = 0;
	m_playerActif = m_players[m_numJoueurActif];
	m_players[0]->decouvre();

	if (!font.loadFromFile("media/Constantine.ttf"))
	{
		std::cout << "Erreur chargement font" << std::endl;
	}

	Button* b = new Button("Test", sf::Vector2i(0, 0), sf::Vector2i(100, 100), &Game::afficherNextBatimentConstruire);
	m_interface->ajouterBouton(b);

	textEau.setFont(font);
	textEau.setString(std::to_string(0));
	textEau.setCharacterSize(12);
	textEau.setColor(sf::Color::White);
	textEau.setStyle(sf::Text::Bold);
	textEau.setPosition(c_view[0] - 370, c_view[1] - 295);

	textEnergie.setFont(font);
	textEnergie.setString(std::to_string(0));
	textEnergie.setCharacterSize(12);
	textEnergie.setColor(sf::Color::White);
	textEnergie.setStyle(sf::Text::Bold);
	textEnergie.setPosition(c_view[0] - 254, c_view[1] - 295);

	textPetrole.setFont(font);
	textPetrole.setString(std::to_string(0));
	textPetrole.setCharacterSize(12);
	textPetrole.setColor(sf::Color::White);
	textPetrole.setStyle(sf::Text::Bold);
	textPetrole.setPosition(c_view[0] - 370, c_view[1] - 264);

	textMetaux.setFont(font);
	textMetaux.setString(std::to_string(0));
	textMetaux.setCharacterSize(12);
	textMetaux.setColor(sf::Color::White);
	textMetaux.setStyle(sf::Text::Bold);
	textMetaux.setPosition(c_view[0] - 254, c_view[1] - 264);
	if (brouillardDeGuerre)
	{
		m_minimap = Minimap(&m_map, m_playerActif);
	}
	else
	{
		m_minimap = Minimap(&m_map);
	}

	tech = false;
	batiment = false;
    indice = 0;
}

void Game::render() {
	if (gameState == 0) {
		menu_p.render();
	}
	if (gameState == 1) {
		//Render de la map et des entites (batiments et unite) 
		m_view.setCenter((float)c_view[0], (float)c_view[1]);
		m_window.setView(m_view);
		calculNombreTileAffichable();
		if (brouillardDeGuerre) {
			m_map.render(&m_window, &m_spriteManager, m_playerActif, nombreTileAffiche, centreImage);
		}
		else {
			m_map.render(&m_window, &m_spriteManager, nombreTileAffiche, centreImage);
		}
		for (int i = 0; i < m_nbJoueur; i++) {
			if (brouillardDeGuerre) {
				m_players[i]->render(&m_window, &m_spriteManager, m_playerActif, nombreTileAffiche, centreImage);
			}
			else
				m_players[i]->render(&m_window, &m_spriteManager, nombreTileAffiche, centreImage);
		}

		if (m_uniteSelectionne != NULL) {
			surbrillanceCaseDeplacement();
		}
		// Render de l'interface
		m_window.setView(m_viewInterface);
		m_interface->render(&m_window, &m_spriteManager);
		if (m_uniteSelectionne != NULL) {
			m_interface->renderInfoUnite(&m_window, font, m_uniteSelectionne);
		}
		if (tech) {
			m_interface->renderTechnologies(&m_window, font, m_technologie);
		}
		if (batiment) {
			m_interface->renderInfoBatiment(&m_window, font, m_batiment);
		}
		const int tour = m_tour;
		m_interface->ecrireMessage(&m_window, (float)630 * 1.25, (float)9 * 1.25, std::to_string(tour), font, 18, sf::Color::White);
		const int nbEau = m_playerActif->getEssence();
		m_interface->ecrireMessage(&m_window, (float)30 * 1.25, (float)5 * 1.25, std::to_string(nbEau), font, 18, sf::Color::Black);
		const int nbEnergie = m_playerActif->getEnergie();
		m_interface->ecrireMessage(&m_window, (float)146 * 1.25, (float)5 * 1.25, std::to_string(nbEnergie), font, 18, sf::Color::Black);
		const int nbVivres = m_playerActif->getVivre();
		m_interface->ecrireMessage(&m_window, (float)30 * 1.25, (float)36 * 1.25, std::to_string(nbVivres), font, 18, sf::Color::Black);
		const int nbMetaux = m_playerActif->getMetaux();
		m_interface->ecrireMessage(&m_window, (float)146 * 1.25, (float)36 * 1.25, std::to_string(nbMetaux), font, 18, sf::Color::Black);

		// Render de la minimap
		m_window.setView(m_viewMinimap);
		m_minimap.render(&m_window, m_winSize.x, m_winSize.y);
		if (m_minimap.getUniteMode()) {
			m_minimap.renderPlayer(&m_window, m_players, m_nbJoueur, m_winSize.x, m_winSize.y);
		}

		if (weather_clock.getElapsedTime().asMilliseconds() < 16) { // 60 fps
			meteo.render();
			weather_clock.restart();
		}
	}
}

void Game::clic(int x, int y) {

	if (gameState == 0) {		
		if (menu_p.hitQuitter(x, y)) {
			m_window.close();
		}

		if (menu_p.hitNouvellePartie(x, y)) {
			gameState = 1;
		}
	}

	if (gameState == 1) {
		clicInterface(x, y);
		/*if (testClicZoneJeu(x, y)) {
			clicZoneJeu(x, y);
		}// Zone clique interface
		else {
			clicInterface(x, y);
		}*/
	}
}

bool Game::testClicZoneJeu(int x, int y) {
	// Zone principale
	return y < m_winSize.y - INTERFACE_HEIGTH;
}

sf::Vector2i Game::definitionCaseClique(int x, int y) {
	sf::Vector2i caseClique(-1, -1);
	// Variable à modifier pour gérer le zoom
	int tailleCaseSurEcran = m_tileSize;
	int nbCaseAfficheParLigne = round(m_winSize.x / tailleCaseSurEcran);
	int nbCaseAfficheParColonne = round((float)(m_winSize.y - INTERFACE_HEIGTH ) / (float)tailleCaseSurEcran);
	int decalageX = round((m_winSize.x - (nbCaseAfficheParLigne * tailleCaseSurEcran)) / 2);
	int decalageY = INTERFACE_HAUT_HEIGHT;

	// Défini les zones de clics des cases
	for (int i = 0; i < nbCaseAfficheParLigne; i++) {
		for (int j = 0; j < nbCaseAfficheParColonne; j++) {
			if (x >= decalageX + i*tailleCaseSurEcran && x < decalageX + (i + 1)*tailleCaseSurEcran 
				&& y < decalageY + (j + 1)*tailleCaseSurEcran  && y >= (j*tailleCaseSurEcran) + decalageY) {
				caseClique.y = centreImage.y + (-nbCaseAfficheParLigne / 2 + 1 + j);
				caseClique.x = centreImage.x + (-nbCaseAfficheParColonne + 1 / 2 + i);
				break;
			}
		}
	}
	return caseClique;
}

void Game::actionUnite(sf::Vector2i caseClique) {
	for (int i = 0; i < m_deplacement.size(); i++) {
		if (caseClique.x == m_deplacement[i].x / m_tileSize && caseClique.y == m_deplacement[i].y / m_tileSize) {
			m_uniteSelectionne->seDeplace(caseClique.x, caseClique.y, &m_window, m_playerActif->getColor(), &m_spriteManager);
			m_playerActif->decouvre();
		}
	}
	for (int i = 0; i < m_attaque.size(); i++) {
		if (caseClique.x == m_attaque[i].x / m_tileSize && caseClique.y == m_attaque[i].y / m_tileSize) {
			UniteArmee *unite = (UniteArmee*)m_uniteSelectionne;
			for (int j = 0; j < m_nbJoueur; j++) {
				if (!j == m_numJoueurActif) {
					for (int k = 0; k < m_players[j]->getNombreUnite(); k++) {
						if (m_players[j]->getUnite(k)->getCoordX() == caseClique.x && m_players[j]->getUnite(k)->getCoordY() == caseClique.y) {
							int ecartUniteX = unite->getCoordX() - m_players[j]->getUnite(k)->getCoordX();
							int ecartUniteY = unite->getCoordY() - m_players[j]->getUnite(k)->getCoordY();
							int distance = abs(ecartUniteX) + abs(ecartUniteY);

							if (distance > unite->getRangeMax()) {
								deplacementAutoPourAttaque(ecartUniteX, ecartUniteY, distance, unite, m_players[j]->getUnite(k)->getCoordX(), m_players[j]->getUnite(k)->getCoordY());
								m_playerActif->decouvre();
							}
							unite->attaque(m_players[j]->getUnite(k));
							
							if (m_players[j]->getUnite(k)->estDetruit()) {
								m_players[j]->detruireUnite(k);
							}
						}
					}
				}
			}
		}

	}
}

void Game::deplacementAutoPourAttaque(int ecartX, int ecartY, int distance, UniteArmee* unite, int posXEnnemi, int posYEnnemi) {
	int deplacementX = 0, deplacementY = 0;
	while (distance > unite->getRangeMax()) {
		if (abs(ecartX) < abs(ecartY)) {
			if (posYEnnemi < unite->getCoordY() + deplacementY) {
				deplacementY--;
			}
			else {
				deplacementY++;
			}
		}
		else {
			if (posXEnnemi < unite->getCoordX() + deplacementX) {
				deplacementX--;
			}
			else {
				deplacementX++;
			}
		}
		ecartX = unite->getCoordX() + deplacementX - posXEnnemi;
		ecartY = unite->getCoordY() + deplacementY - posYEnnemi;
		distance = abs(ecartX) + abs(ecartY);
	}
	unite->seDeplace(unite->getCoordX() + deplacementX, unite->getCoordY() + deplacementY, &m_window, m_playerActif->getColor(),&m_spriteManager);
}

void Game::clicZoneJeu(int x, int y) {
	sf::Vector2i caseClique = definitionCaseClique(x, y);
	//tech = false;

	if (m_uniteSelectionne != NULL && m_uniteSelectionne->peutAgir()) {
		actionUnite(caseClique);
		deselection();
	}
	else {
		selection(caseClique, x, y);
	}
}

void Game::clicUnite(int x, int y, Unite *unite) {
	m_uniteSelectionne = unite;
	m_interface->renderInfoUnite(&m_window, font, unite);
	definitionCase();
	tech = false;
	batiment = false;
}

void Game::clicInterface(int x, int y) {
	m_interface->clic(this, x, y);
	/*
	if (x < 43 && 6 < x) {
		if (y < 485 && 465 < y) {
			m_minimap.changeModeTopo();
		}
		else if (y < 530 && 510 < y) {
			m_minimap.changeModeRessource();
		}
		else if (y < 575 && 555 < y) {
			m_minimap.changeModeUnite();
		}
	}
	else if (x < 233 && 64 < x && y < 485 && 460 < y) {
		finTour();
	}
	else if (x < 312 && 266 < x && y < 575 && 490 < y) {
		std::cout << "Fleche gauche " << std::endl;
        if (tech) afficherPrevTechAChercher();
		if (batiment) afficherPrevBatiementConstruire();
	}
	else if (x < 786 && 740 < x && y < 575 && 490 < y) {
        std::cout << "Fleche droite " << std::endl;
        if (tech) afficherNextTechAChercher();
		if (batiment) afficherNextBatiementConstruire();
    }
	else if (tech && x > 600 && x < 675 && y > 560  && y < 570 ) {
        std::cout << "Achat" << std::endl;
        buyTech();
    }
	else if (x < 395 && 261 < x && y < 30 && 4 < y) {
		std::cout << "Technologie " << std::endl;
		deselection();
		afficherTechAChercher();
		batiment = false;
	}
	else if (x < 544 && 410 < x && y < 30 && 4 < y) {
		std::cout << "Construction " << std::endl;
		deselection();
		afficherBatimentAConstruire();
		tech = false;
	}
	else if (x < 744 && 710 < x && y < 31 && 2 < y) {
		std::cout << "Options " << std::endl;
		deselection();
		tech = false;
		batiment = false;
	}
	else if (x < 787 && 753 < x && y < 31 && 2 < y) {
		m_window.close();
	}*/
}

void Game::afficherTechAChercher() {
    tech = true;
    indice = 0;
    m_technologie = m_playerActif->getTechnoARechercher()[indice];
}

void Game::afficherBatimentAConstruire() {
	batiment = true;
	indice = 0;
	m_batiment = m_batimentManager.getBatimentConstructible()[indice];
}

void Game::afficherPrevTechAChercher() {
    if (indice > 0) {
        indice--;
        m_technologie = m_playerActif->getTechnoARechercher()[indice];
    }
}

void Game::afficherNextTechAChercher() {
    if (indice < (m_playerActif->getTechnoARechercher().size() - 1)) {
        indice++;
        m_technologie = m_playerActif->getTechnoARechercher()[indice];
    }
}

void Game::afficherPrevBatiementConstruire()
{
	if (indice > 0) {
		indice--;
		m_batiment = m_batimentManager.getBatimentConstructible()[indice];
	}
}

void Game::afficherNextBatimentConstruire()
{
	printf("next batiement");
	if (indice < (m_batimentManager.getBatimentConstructible().size() - 1)) {
		indice++;
		m_batiment = m_batimentManager.getBatimentConstructible()[indice];
	}
}

void Game::buyTech() {
    m_playerActif->rechercheTechnologie(m_technologie);
    tech = false;
}

Player* Game::getPlayerActif() {
	return m_playerActif;
}

void Game::joueurSuivant() {
	m_deplacement.clear();
	m_attaque.clear();
	m_numJoueurActif++;
	if (m_numJoueurActif >= m_nbJoueur) {
		m_tour++;
		m_numJoueurActif = 0;
	}
	std::cout << "c'est au tour du joueur " << m_numJoueurActif << std::endl;
	m_playerActif = m_players[m_numJoueurActif];
	m_playerActif->decouvre();
}

void Game::finTour() {
	m_batimentSelectionne = NULL;
	m_uniteSelectionne = NULL;
	m_playerActif->update();
	joueurSuivant();
	// Ca pourrait etre sympa d'afficher en plus "C'est au tour de joueur : "
}

void Game::definitionCase() {
	cout << m_uniteSelectionne->getDeplacementMax() << endl;
	m_attaque.clear();
	m_deplacement.clear();
	// Unite armee
	definitionCaseDeplacement(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY(), m_uniteSelectionne->getDeplacementMax());
	if (m_uniteSelectionne->isArmee()) {
		UniteArmee* unite = (UniteArmee*)m_uniteSelectionne;
		if (unite->peutAttaquer()) {
			definitionCaseAttaque();
		}
	}
	else if (m_uniteSelectionne->isUtilitaire()) {
		UniteUtilitaire* unite = (UniteUtilitaire*)m_uniteSelectionne;
		if (unite->getPeutBougerEtAttaquer()) {
		}
		// Unite type colon
		else {

		}
	}
}

bool Game::inDeplacement(sf::Vector2f item) {
	for (int i = 0; i < m_deplacement.size(); i++) {
		if (m_deplacement.at(i).x == item.x && m_deplacement.at(i).y == item.y) {
			return true;
		}
	}
	return false;
}

bool Game::inAttaque(sf::Vector2f item) {
	for (int i = 0; i < m_attaque.size(); i++) {
		if (m_attaque.at(i).x == item.x && m_attaque.at(i).y == item.y) {
			return true;
		}
	}
	return false;
}

void Game::definitionCaseDeplacement(int x, int y, int profondeur) {
	if (profondeur == 1) {
		return;
	}
	if (m_map.isInBound(x + 1, y)  && testUniteSelectionneTypeCase(x + 1,y) && !testEntiteEnnemie(x + 1, y)) {
		if (!inDeplacement(sf::Vector2f((x + 1)*m_tileSize, y*m_tileSize)) && !testUniteAlliee(x + 1, y)) {
			m_deplacement.push_back(sf::Vector2f((x + 1)*m_tileSize, y*m_tileSize));
		}
		definitionCaseDeplacement(x + 1, y, profondeur - 1);
	}
	if (m_map.isInBound(x - 1, y)  && testUniteSelectionneTypeCase(x - 1, y) && !testEntiteEnnemie(x - 1, y)) {
		if (!inDeplacement(sf::Vector2f((x - 1)*m_tileSize, y*m_tileSize)) && !testUniteAlliee(x - 1, y)) {
			m_deplacement.push_back(sf::Vector2f((x - 1)*m_tileSize, y*m_tileSize));
		}
		definitionCaseDeplacement(x - 1, y, profondeur - 1);
	}
	if (m_map.isInBound(x, y + 1)  && testUniteSelectionneTypeCase(x, y + 1) && !testEntiteEnnemie(x, y + 1)) {
		if (!inDeplacement(sf::Vector2f(x*m_tileSize, (y + 1)*m_tileSize)) && !testUniteAlliee(x, y + 1)) {
			m_deplacement.push_back(sf::Vector2f(x*m_tileSize, (y + 1)*m_tileSize));
		}
		definitionCaseDeplacement(x, y + 1, profondeur - 1);
	}
	if (m_map.isInBound(x, y - 1) && testUniteSelectionneTypeCase(x, y - 1) && !testEntiteEnnemie(x, y - 1)) {
		if (!inDeplacement(sf::Vector2f(x*m_tileSize, (y - 1)*m_tileSize)) && !testUniteAlliee(x, y - 1)) {
			m_deplacement.push_back(sf::Vector2f(x*m_tileSize, (y - 1)*m_tileSize));
		}
		definitionCaseDeplacement(x, y - 1, profondeur - 1);
	}
}

void Game::definitionCaseAttaque() {
	UniteArmee* unite = (UniteArmee*)m_uniteSelectionne;
	if (unite->getPeutBougerEtAttaquer()) {
		for (int i = 0; i < m_deplacement.size();i++) {
			definitionCaseAttaque(m_deplacement[i].x/m_tileSize, m_deplacement[i].y / m_tileSize);
		}
	}
	else {
		definitionCaseAttaque(unite->getCoordX(), unite->getCoordY());
	}
}

void Game::definitionCaseAttaque(int x, int y) {
	UniteArmee* unite = (UniteArmee*)m_uniteSelectionne;
	int max = unite->getRangeMax();
	int min = unite->getRangeMin();
	for (int i = x - max; i <= x + max; i++) {
		if (m_map.isInBound(i, 0)) {
			for (int j = y - max; j <= y + max; j++) {
				if (m_map.isInBound(i, j) && abs(y - j) + abs(x - i) >= min && abs(y - j) + abs(x - i) < max && !inAttaque(sf::Vector2f(i*m_tileSize, j*m_tileSize)) && testEntiteEnnemie(i,j)) {
					m_attaque.push_back(sf::Vector2f(i*m_tileSize, j*m_tileSize));
				}
			}
		}
	}
}

void Game::calculNombreTileAffichable() {
	 nombreTileAffiche.x = m_winSize.x / m_tileSize + 2;
	 nombreTileAffiche.y = m_winSize.y / m_tileSize + 2;
}

void Game::surbrillanceCaseDeplacement() {
	sf::Sprite sprite = m_spriteManager.getRef("filtre attaque");
	for (int i = 0; i < m_attaque.size(); i++) {
		sprite.setPosition(m_attaque[i]);
		m_window.draw(sprite);
	}

	sprite = m_spriteManager.getRef("filtre deplacement");
	for (int i = 0; i < m_deplacement.size(); i++) {
		sprite.setPosition(m_deplacement[i]);
		m_window.draw(sprite);
	}
	sprite = m_spriteManager.getRef("filtre selection");
	sprite.setPosition(sf::Vector2f(m_uniteSelectionne->getCoordX()*m_tileSize, m_uniteSelectionne->getCoordY()*m_tileSize));
	m_window.draw(sprite);
}

bool Game::testUniteAlliee(int x, int y) {
	if (x == m_uniteSelectionne->getCoordX() && y == m_uniteSelectionne->getCoordY()) {
		return false;
	}
	for (int i = 0; i < getPlayerActif()->getNombreUnite(); i++) {
		if (m_playerActif->getUnite(i)->getCoordX() == x && m_playerActif->getUnite(i)->getCoordY() == y) {
			return true;
		}
	}
	return false;
}

bool Game::testEntiteEnnemie(int x, int y) {
	for (int j = 0; j < m_nbJoueur; j++) {
		if (!j == m_numJoueurActif) {
			for (int i = 0; i < m_players[j]->getNombreUnite(); i++) {
				if (m_players[j]->getUnite(i)->getCoordX() == x && m_players[j]->getUnite(i)->getCoordY() == y) {
					return true;
				}
			}
			for (int i = 0; i < m_players[j]->getNombreBatiment(); i++) {
				if (m_players[j]->getBatiment(i)->getCoordX() == x && m_players[j]->getBatiment(i)->getCoordY() == y) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Game::testUniteSelectionneTypeCase(int x, int y) {
	TypeCase caseActuelle = m_map.getTile(x, y).getTypeCase();
	if (caseActuelle == TypeCase::MONTAGNE && !m_uniteSelectionne->isAerienne())
		return false;
	if (m_uniteSelectionne->isMaritime()) {
		if (caseActuelle == TypeCase::MER || caseActuelle == TypeCase::PLAGE) 
			return true;
	}
	else if (m_uniteSelectionne->isInfanterie() || m_uniteSelectionne->isMotorise()) {
		if (caseActuelle == TypeCase::MER)
			return false;
	}
	return true;
}

void Game::selection(sf::Vector2i caseClique, int x, int y) {
	if(m_uniteSelectionne == NULL && m_batimentSelectionne == NULL){
		for (int i = 0; i < m_playerActif->getNombreUnite(); i++) {
			if (m_playerActif->getUnite(i)->getCoordX() == caseClique.x && m_playerActif->getUnite(i)->getCoordY() == caseClique.y && m_playerActif->getUnite(i)->peutAgir()) {
				clicUnite(x, y, m_playerActif->getUnite(i));
				std::cout << "Nom : " << m_uniteSelectionne->getNom() << std::endl;
				std::cout << "Description : " << m_uniteSelectionne->getDescription() << std::endl;
				std::cout << "PV : " << m_uniteSelectionne->getPvRestant()<< "/" << 10 << std::endl;
				std::cout << "Ressource : " << m_uniteSelectionne->getStockRessActuel()<<"/"<< m_uniteSelectionne->getStockMaxRess() <<std::endl;
				if (m_uniteSelectionne->isArmee()) {
					UniteArmee* unite = (UniteArmee*)m_uniteSelectionne;
					std::cout << "Munition : " << unite->getStockMunActuel() << "/" << unite->getStockMaxMun() << std::endl;
					std::cout << "Portée entre " << unite->getRangeMin() << " et " << unite->getRangeMax() << std::endl;
				}
			}
		}
		if (m_uniteSelectionne == NULL) {
			for (int i = 0; i < m_playerActif->getNombreBatiment(); i++) {
				if (m_playerActif->getBatiment(i)->getCoordX() == caseClique.x && m_playerActif->getBatiment(i)->getCoordY() == caseClique.y) {
					std::cout << "Batiment clique" << std::endl;
				}
			}
		}
	}
}

void Game::deselection() {
	m_uniteSelectionne = NULL;
	m_batimentSelectionne = NULL;
}

void Game::resize()
{
	m_winSize.x = m_window.getSize().x;
	m_winSize.y = m_window.getSize().y;
	m_view = sf::View(sf::Vector2f((float)c_view[0], (float)c_view[1]), sf::Vector2f(m_winSize.x, m_winSize.y));
	m_viewInterface = sf::View(sf::Vector2f(m_winSize.x / 2, m_winSize.y / 2), sf::Vector2f(m_winSize.x, m_winSize.y));
	m_viewMinimap = sf::View(sf::Vector2f(m_winSize.x / 2, m_winSize.y / 2), sf::Vector2f(m_winSize.x, m_winSize.y));
	m_interface->resize(m_winSize.x, m_winSize.y);
}

int Game::getState() {
	return gameState;
}