#pragma once
#include "tile.h"
#include <vector>
#include <iostream>

class Map{

private:
	std::vector< std::vector<Tile> > m_tile;

public:
	Map();
	Map(int w, int h);
	void print(sf::RenderWindow *window);
};