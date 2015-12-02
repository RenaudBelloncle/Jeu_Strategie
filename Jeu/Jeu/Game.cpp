#include "Game.h"
#include "Constantes.h"

void Game::loadTextures()
{
    m_textureManager.loadTexture("Vide", "media/Vide.png");
    m_textureManager.loadTexture("Plaine", "media/Plaine.png");
}

Game::Game()
{
    m_map = Map(MAP_WIDTH,MAP_HEIGTH);
    loadTextures();
    m_window.create(sf::VideoMode(WIN_WIDTH,WIN_HEIGTH), "Jeu de Stratégie");
    c_view[0] = WIN_WIDTH/2;
    c_view[1] = WIN_HEIGTH/2;
    m_view = sf::View(sf::Vector2f(c_view[0],c_view[1]),sf::Vector2f(WIN_WIDTH,WIN_HEIGTH));
    m_window.setFramerateLimit(60);
}

void Game::print()
{
    m_map.print(&m_window);
    m_view.setCenter(c_view[0],c_view[1]);
    m_window.setView(m_view);
}