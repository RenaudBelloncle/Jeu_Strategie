#pragma once
#include <SFML/Graphics.hpp>

class Tile{

private:
	int m_type;
	
public:
	Tile();
	Tile(int t);

	int getType();
};