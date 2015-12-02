#ifndef PROJET_TEXTUREMANAGER_H
#define PROJET_TEXTUREMANAGER_H


#include <map>
#include <SFML/Graphics.hpp>

class TextureManager {
private:
    std::map<std::string, sf::Texture> m_textures;

public:
    TextureManager() { }

    void loadTexture(const std::string& name, const std::string& filename);

    sf::Texture& getRef(const std::string& texture);
};


#endif //PROJET_TEXTUREMANAGER_H
