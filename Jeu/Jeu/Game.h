#pragma once

#include <stack>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "SpriteManager.h"
#include "Map.h"
#include "Minimap.h"
#include "Player.h"
#include "UniteArmee.h"

class GameState;

class Game
{
private:
    void loadTextures();
	void loadSprites();

public:
    Game();

    sf::RenderWindow m_window;
    sf::View m_view, m_viewMinimap, m_viewInterface;
    int c_view[2];
    TextureManager m_textureManager;
	SpriteManager m_spriteManager;

    Map m_map;
	Minimap m_minimap;

	Player *m_player;

    void render();
	Player* getPlayer();
};