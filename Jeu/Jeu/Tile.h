#ifndef PROJET_TILE_H
#define PROJET_TILE_H


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
};


#endif //PROJET_TILE_H
