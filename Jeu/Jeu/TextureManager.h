#pragma once

#include <iostream>
#include <string>
#include <map>
#include <SFML/Graphics.hpp>

class TextureManager
{
public:
	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
	static bool load(std::string file, std::string id);
	static sf::Texture* getTexture(std::string id);
protected:
private:
	TextureManager() {}
	~TextureManager() {}

	TextureManager(const TextureManager&);
	TextureManager& operator=(const TextureManager&);
	static TextureManager* s_pInstance;
	static std::map<std::string, sf::Texture*> m_textureMap;
};
