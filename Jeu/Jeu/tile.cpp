#include <cstdio>
#include <cstdlib>
#include "tile.h"

Tile::Tile(){
	Tile(0);
}

Tile::Tile(int t): m_type(t) {}

int Tile::getType(){
	return m_type;
}