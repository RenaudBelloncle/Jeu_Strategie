#include "SpriteManager.h"

void SpriteManager::loadSprite(const std::string &name, const sf::Texture &spritesheet, const int widthSprite, const int heightSprite,
	const int column, const int line)
{
	sf::Sprite sprite;
	sprite.setTexture(spritesheet);
	sprite.setTextureRect(sf::IntRect(widthSprite*column,heightSprite*line,widthSprite,heightSprite));
	m_sprites[name] = sprite;

	return;
}

sf::Sprite& SpriteManager::getRef(const std::string &sprite)
{
	return m_sprites.at(sprite);
}