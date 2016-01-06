#include "Game.h"
#include "Constantes.h"

void Game::loadTextures()
{
	m_textureManager.loadTexture("unite","media/res/SpriteSheetUnite.png");
	m_textureManager.getRef("unite").setSmooth(true);
	m_textureManager.loadTexture("interface", "media/res/Interface.png");
	m_textureManager.loadTexture("tile", "media/res/Tile.png");
	m_textureManager.loadTexture("ressource", "media/res/Ressource.png");
}

void Game::loadSprites()
{
	m_spriteManager.loadSprite("interface", m_textureManager.getRef("interface"), 800, 175, 0, 0);
	m_spriteManager.getRef("interface").setPosition(0, WIN_HEIGTH + 181);
	m_spriteManager.getRef("interface").scale(1.25, 1.25);
	m_spriteManager.loadSprite("interface_unite", m_textureManager.getRef("interface"), 800, 175, 0, 0);
	m_spriteManager.getRef("interface_unite").setPosition(0, WIN_HEIGTH + 181);
	m_spriteManager.getRef("interface_unite").scale(1.25, 1.25);
	m_spriteManager.loadSprite("interface_batiment", m_textureManager.getRef("interface"), 800, 175, 0, 0);
	m_spriteManager.getRef("interface_batiment").setPosition(0, WIN_HEIGTH + 181);
	m_spriteManager.getRef("interface_batiment").scale(1.25, 1.25);

	m_spriteManager.loadSprite("petrole",m_textureManager.getRef("ressource"),32,32,0,0);
	m_spriteManager.loadSprite("vivre", m_textureManager.getRef("ressource"), 32, 32, 1, 0);
	m_spriteManager.loadSprite("metal", m_textureManager.getRef("ressource"), 32, 32, 0,1);
	m_spriteManager.loadSprite("void", m_textureManager.getRef("ressource"), 32, 32, 1, 1);

	m_spriteManager.loadSprite("plaine", m_textureManager.getRef("tile"), 128, 128, 0, 0);
	m_spriteManager.loadSprite("plage", m_textureManager.getRef("tile"), 128, 128, 1, 0);
	m_spriteManager.loadSprite("montagne", m_textureManager.getRef("tile"), 128, 128, 2, 0);
	m_spriteManager.loadSprite("mer", m_textureManager.getRef("tile"), 128, 128, 0, 1);
	m_spriteManager.loadSprite("foret", m_textureManager.getRef("tile"), 128, 128, 1,1);
	m_spriteManager.loadSprite("marais", m_textureManager.getRef("tile"), 128, 128, 2, 1);
	m_spriteManager.loadSprite("coline", m_textureManager.getRef("tile"), 128, 128, 0, 2);
	m_spriteManager.loadSprite("ville", m_textureManager.getRef("tile"), 128, 128, 1, 2);
	m_spriteManager.loadSprite("ruine", m_textureManager.getRef("tile"), 128, 128, 2, 2);

	m_spriteManager.loadSprite("infanterie", m_textureManager.getRef("unite"), 128, 128, 0, 0);
	m_spriteManager.loadSprite("soldat", m_textureManager.getRef("unite"), 128, 128, 1, 0);
	m_spriteManager.loadSprite("soldat_arme", m_textureManager.getRef("unite"), 128, 128, 2, 0);
	m_spriteManager.loadSprite("demolisseur", m_textureManager.getRef("unite"), 128, 128, 3, 0);

	m_spriteManager.loadSprite("maritime", m_textureManager.getRef("unite"), 128, 128, 0, 1);

	m_spriteManager.loadSprite("motorise", m_textureManager.getRef("unite"), 128, 128, 0, 2);

	m_spriteManager.loadSprite("aerien", m_textureManager.getRef("unite"), 128, 128, 0, 3);
	
}

Game::Game()
{
	std::cout << "Chargement des textures ..." << std::endl;
    loadTextures();
	std::cout << "Chargement des textures termine" << std::endl;
	std::cout << "Chargement des sprites ..." << std::endl;
	loadSprites();
	std::cout << "Chargement des sprites termine" << std::endl;
	m_map = Map(-0.2f, -0.15f, 0.3, 0.4);
	m_minimap = Minimap(&m_map);
	m_interface = Interface();
    m_window.create(sf::VideoMode(WIN_WIDTH,WIN_HEIGTH), "Jeu de Strategie", sf::Style::Close);
	centreImage.x = MAP_WIDTH / 2; centreImage.y = MAP_HEIGTH / 2;

	if (MAP_WIDTH % 2 == 0)
		c_view[0] = (MAP_WIDTH * SPRITE) / 2;
	else
		c_view[0] = ((MAP_WIDTH-1) * SPRITE) / 2;
	if (MAP_HEIGTH % 2 == 0)
		c_view[1] = (MAP_HEIGTH * SPRITE) / 2;
	else
		c_view[1] = ((MAP_HEIGTH - 1) * SPRITE) / 2;

    m_view = sf::View(sf::Vector2f((float)c_view[0],(float)c_view[1]),sf::Vector2f((float)WIN_WIDTH,(float)WIN_HEIGTH));
    //m_view.zoom(SPRITE >> 6);
    m_window.setFramerateLimit(60);

	m_player = new Player(sf::Color(127,127,127));
}

void Game::render()
{
	//Render de la map et des entites (batiments et unite) 
	m_view.setCenter((float)c_view[0],(float) c_view[1]);
	m_window.setView(m_view);
	m_map.render(&m_window, &m_spriteManager);
	m_player->render(&m_window, &m_spriteManager);

	//Croix rouge au milieu de l'écran
	sf::RectangleShape shape(sf::Vector2f(2, 10));
	shape.setPosition(c_view[0]-1,c_view[1]-5);
	shape.setFillColor(sf::Color(255, 0, 0));
	m_window.draw(shape);
	sf::RectangleShape shape2(sf::Vector2f(10, 2));
	shape2.setPosition(c_view[0]-5, c_view[1]-1);
	shape2.setFillColor(sf::Color(255, 0, 0));
	m_window.draw(shape2);

	// Render de l'interface
	m_window.setView(m_viewInterface);
	m_interface.render(&m_window, &m_spriteManager);

	// Render de la minimap
	m_window.setView(m_viewMinimap);
	m_minimap.render(&m_window);
	if (m_minimap.getUniteMode()) {
		m_minimap.renderPlayer(&m_window,m_player);
	}
}

void Game::clic(int x, int y) {
	// Zone clique jeu
	if (testClicZoneJeu(x, y)) {
		sf::Vector2i caseClique(0, 0);
		// Variable à modifier pour gérer le zoom
		int tailleCaseSurEcran = SPRITE;
		int nbCaseAfficheParLigne = WIN_WIDTH / tailleCaseSurEcran;
		int nbCaseAfficheParColonne = (WIN_HEIGTH - INTERFACE_HEIGTH) / tailleCaseSurEcran;
		int decalageX = (WIN_WIDTH - (nbCaseAfficheParLigne * tailleCaseSurEcran)) / 2;
		int decalageY = ((WIN_HEIGTH - INTERFACE_HEIGTH) - nbCaseAfficheParColonne * tailleCaseSurEcran) / 2;
		for (int i = 0; i < nbCaseAfficheParLigne; i++) {
			for (int j = 0; j < nbCaseAfficheParColonne; j++) {
				if (x >= decalageX + i*tailleCaseSurEcran && x < decalageX + (i + 1)*tailleCaseSurEcran - 1
					&& y < decalageY + (j + 1)*tailleCaseSurEcran - 1 && y >= (j*tailleCaseSurEcran) + decalageY) {

					caseClique.y = centreImage.y + (-nbCaseAfficheParLigne / 2 + 1 + j);
					caseClique.x = centreImage.x + (-nbCaseAfficheParColonne + 1 / 2 + i);

					std::cout << "X" << caseClique.x << std::endl;
					std::cout << "Y" << caseClique.y << std::endl;

					break;
				}
			}
		}
		for (int i = 0; i < getPlayer()->getNombreUnite(); i++) {
			if (getPlayer()->getUnite(i)->getCoordX() == caseClique.x && getPlayer()->getUnite(i)->getCoordY() == caseClique.y) {
				std::cout << "Unite clique" << std::endl;
			}
		}
		for (int i = 0; i < getPlayer()->getNombreBatiment(); i++) {
			if (getPlayer()->getBatiment(i)->getCoordX() == caseClique.x && getPlayer()->getBatiment(i)->getCoordY() == caseClique.y) {
				std::cout << "Batiment clique" << std::endl;
			}
		}
	}// Zone clique interface
	else {
		clicInterface(x, y);
	}
}

bool Game::testClicZoneJeu(int x, int y) {
	// Zone principale
	if (y < WIN_HEIGTH - INTERFACE_HEIGTH)
		return true;
	// Rectangle au dessus de l'interface
	else if (x >= 226 && y >= 469 && y <= 506)
		return true;
	// Triangle au dessus de l'interface
	else if (x < 226 && x >= 177 && y < 506 && y > 469) {
		float coeffDir = (506.0 - 469.0) / (226.0 - 177.0);
		float ordonneeOri = 469 - coeffDir * 177.0;
		std::cout << coeffDir << std::endl;
		if (y < x*coeffDir + ordonneeOri)
			return true;
	}
	return false;
}

void Game::clicUnite(int x, int y) {
	m_interface.setModeUnite();
}

void Game::clicInterface(int x, int y) {
	if (x < 225 && 185 < x) {
		if (y < 538 && 523 < y) {
			m_minimap.changeModeTopo();
		}
		else if (y < 560 && 546 < y) {
			m_minimap.changeModeRessource();
		}
		else if (y < 683 && 568 < y) {
			m_minimap.changeModeUnite();
		}
	}
}

Player* Game::getPlayer() 
{
	return m_player;
}