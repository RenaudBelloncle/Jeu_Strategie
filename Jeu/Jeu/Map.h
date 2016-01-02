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
    Map(float nivMer, float nivPlage, float nivPlaine, float nivColine);

    void mapGenerator(float nivMer, float nivPlage, float nivPlaine, float nivColine);
    float bruitPerlin(float x, float y, float res);
    TypeCase whichType(float hauteur, float nivMer, float nivPlage, float nivPlaine, float nivColine);

    void render(sf::RenderWindow* renderWindow);
};