#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"

class Etat
{
public:

    virtual void render() = 0;
    virtual void update(int delta) = 0;
protected:
    Game* jeu;
    sf::RenderWindow* window;
};