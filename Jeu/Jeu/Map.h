#pragma once

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

    void render(sf::RenderWindow* renderWindow);
};