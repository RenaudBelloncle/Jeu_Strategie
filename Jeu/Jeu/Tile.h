#pragma once

#include "TypeCase.h"
#include "Ressource.h"

class Tile {
private:
    TypeCase m_typeCase;
    Ressource m_ressource;

public:
    Tile(TypeCase type = TypeCase::PLAINE);

    TypeCase getTypeCase();
    Ressource getRessource();


    void initRessource();
    Ressource whichRessource(int proba, int pVivres, int pMetal, int pPetrole);
};