#pragma once

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Tile.h"
#include "TextureManager.h"
#include "Constantes.h"

class Map {
private:
    Tile m_tiles[MAP_WIDTH][MAP_HEIGTH];
    unsigned int permutation[256];

public:
    Map();

    void randomMapGenerator();
    void mapGenerator();
    float bruitPerlin(float x, float y, float res);
    TypeCase whichType(float hauteur);

    void render(sf::RenderWindow* renderWindow);
};