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
	m_map = Map();
	m_minimap = Minimap(&m_map);
    m_window.create(sf::VideoMode(WIN_WIDTH,WIN_HEIGTH), "Jeu de Strategie", sf::Style::Close);

    c_view[0] = (MAP_WIDTH * SPRITE) / 2;;
    c_view[1] = (MAP_HEIGTH * SPRITE) / 2;;

    m_view = sf::View(sf::Vector2f((float)c_view[0],(float)c_view[1]),sf::Vector2f((float)WIN_WIDTH,(float)WIN_HEIGTH));
    m_view.zoom(SPRITE >> 6);
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

	// Render de l'interface
	m_window.setView(m_viewInterface);
	m_window.draw(m_spriteManager.getRef("interface"));

	// Render de la minimap
	m_window.setView(m_viewMinimap);
	m_minimap.render(&m_window);
	if (m_minimap.getUniteMode()) {
		m_minimap.renderPlayer(&m_window,m_player);
	}
}

Player* Game::getPlayer() 
{
	return m_player;
}