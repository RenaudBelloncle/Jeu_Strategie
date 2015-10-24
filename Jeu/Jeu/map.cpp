#include <cstdio>
#include <cstdlib>
#include "map.h"
#include "TextureManager.h"

Map::Map(){
	Map(10, 10);
}
Map::Map(int w, int h){

	for(int i = 0 ; i < w ; i++){

		m_tile.push_back(std::vector<Tile>());
		for(int j = 0 ; j < h ; j++){
			Tile t(0);
			m_tile[i].push_back(t);
		}
	}
}

void Map::print(sf::RenderWindow *window){

	sf::Sprite sprite;

	sf::RectangleShape rec(sf::Vector2f(40, 40));

	rec.setFillColor(sf::Color(0, 0, 0));
	rec.setOutlineThickness(2);
	rec.setOutlineColor(sf::Color(255, 255, 255));

	for(int unsigned i = 0 ; i < m_tile.size() ; i++){
		for(int unsigned j = 0 ; j < m_tile[i].size() ; j++){

			switch(m_tile[i][j].getType()){

				case 0:
					sprite.setTexture(*TextureManager::getTexture("empty"));
					break;

				case 1:
					sprite.setTexture(*TextureManager::getTexture("grass"));
					break;

				case 2:
					sprite.setTexture(*TextureManager::getTexture("water"));
					break;

				default:
					break;
			}

			rec.setPosition(sf::Vector2f(i*40, j*40));
			window->draw(rec); 
		}
	}
}