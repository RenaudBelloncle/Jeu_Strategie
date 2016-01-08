#pragma once

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Tile.h"
#include "SpriteManager.h"
#include "Constantes.h"
#include "Player.h"

class Map {
private:
    Tile m_tiles[MAP_WIDTH][MAP_HEIGTH];
    unsigned int permutation[256];
	bool m_topo, m_ressource, m_unite;

public:

    Map();

    void mapGenerator();
    float bruitPerlin(float x, float y, float res);
    TypeCase whichType(float hauteur);

	Tile getTile(int x, int y);

    void render(sf::RenderWindow* renderWindow, SpriteManager *manager, Player *player);
	void render(sf::RenderWindow* renderWindow, SpriteManager *manager);
};