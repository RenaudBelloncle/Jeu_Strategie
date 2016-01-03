#include <stdlib.h>
#include <iostream>
#include "Tile.h"

Tile::Tile(TypeCase type) : m_typeCase(type)
{
    initRessource();
}

TypeCase Tile::getTypeCase()
{
    return m_typeCase;
}

Ressource Tile::getRessource()
{
    return m_ressource;
}

void Tile::initRessource()
{
    switch (m_typeCase)
    {
        case TypeCase::PLAINE:
            m_ressource = whichRessource(10,34,33,33);
            break;

        case TypeCase::PLAGE:
            m_ressource = whichRessource(10,34,33,33);
            break;

        case TypeCase::FORET:
            m_ressource = whichRessource(10,80,10,10);
            break;

        case TypeCase::MARAIS:
            m_ressource = whichRessource(10,10,10,80);
            break;

        case TypeCase::COLINE:
            m_ressource = whichRessource(10,10,80,10);
            break;

        default:
            m_ressource = Ressource::AUCUNE;
            break;
    }
}

Ressource Tile::whichRessource(int proba, int pVivres, int pMetal, int pPetrole)
{
    int random = rand() % 100;
    if (random <= proba)
    {
        random = rand() % 100;
        if (random <= pVivres) return Ressource::VIVRES;
        else if (random <= pVivres+pMetal) return Ressource::METAL;
        else if (random <= pVivres+pMetal+pPetrole) return Ressource::PETROLE;
    }
}