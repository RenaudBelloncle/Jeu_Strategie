#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;
std::map<std::string, sf::Texture*> TextureManager::m_textureMap;

bool TextureManager::load(std::string file, std::string id){
	sf::Texture* texture = new sf::Texture();

	if (!texture->loadFromFile(file))
	{
		return false;
	}

	m_textureMap[id] = texture;

	return true;
}

sf::Texture* TextureManager::getTexture(std::string id){
	return m_textureMap[id];
}