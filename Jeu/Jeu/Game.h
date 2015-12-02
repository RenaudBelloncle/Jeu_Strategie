#ifndef PROJET_GAME_H
#define PROJET_GAME_H


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

    std::stack<GameState*> m_states;

    sf::RenderWindow m_window;
    sf::View m_view;
    int c_view[2];
    TextureManager m_textureManager;

    Map m_map;

    void pushState(GameState* state);
    void print();
};


#endif //PROJET_GAME_H
