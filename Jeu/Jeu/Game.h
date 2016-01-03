#pragma once

#include <stack>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Map.h"

class GameState;

class Game
{
private:
    void loadTextures();

public:
    Game();

    sf::RenderWindow m_window;
    sf::View m_view;
    int c_view[2];
    TextureManager m_textureManager;

    Map m_map = Map(0, 0, 0, 0);

    void render();
};