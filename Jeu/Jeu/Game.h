#pragma once

#include <stack>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "SpriteManager.h"
#include "Map.h"
#include "Minimap.h"
#include "Player.h"
#include "UniteArmee.h"
#include "Interface.h"

class Game
{
private:
    void loadTextures();
	void loadSprites();
	TextureManager m_textureManager;
	SpriteManager m_spriteManager;
	Map m_map = Map(0, 0, 0, 0);
	Minimap m_minimap;
	Player *m_player;
	Interface m_interface;

public:
    Game();

    sf::RenderWindow m_window;
    sf::View m_view, m_viewMinimap, m_viewInterface;
    int c_view[2];
	sf::Vector2i centreImage;

    void render();
	Player* getPlayer();

	void clic(int x, int y);
	bool testClicZoneJeu(int x, int y);
	void clicInterface(int x, int y);
	void clicUnite(int x, int y);
	void clicBatiment(int x, int y);
};