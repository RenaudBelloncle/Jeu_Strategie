#ifndef PROJET_SPRITEMANAGER_H
#define PROJET_SPRITEMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>

class SpriteManager {
private:
	std::map<std::string, sf::Sprite> m_sprites;

public:
	SpriteManager() { }

	void loadSprite(const std::string& name, const sf::Texture& spritesheet, const int widthSprite, const int heightSprite, 
		const int column, const int line);

	sf::Sprite& getRef(const std::string& sprite);
};


#endif //PROJET_SPRITEMANAGER_H
#pragma once
