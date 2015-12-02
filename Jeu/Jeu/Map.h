#ifndef PROJET_MAP_H
#define PROJET_MAP_H


#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Tile.h"
#include "TextureManager.h"

class Map {
private:
    std::vector<std::vector<Tile>> m_tiles;

public:
    Map();
    Map(int width, int heigth);

    void print(sf::RenderWindow* renderWindow);
};


#endif //PROJET_MAP_H
