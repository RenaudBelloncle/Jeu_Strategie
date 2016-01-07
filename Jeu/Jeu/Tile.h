#pragma once

#include "TypeCase.h"
#include "Ressource.h"

class Tile {
private:
    TypeCase m_typeCase;
    Ressource m_ressource;
	int bonusRes;

public:
    Tile(TypeCase type = TypeCase::PLAINE);

    TypeCase getTypeCase();
    Ressource getRessource();
	int getBonusRes();
	void setBonusRes();

    void initRessource();
    Ressource whichRessource(int proba, int pVivres, int pMetal, int pPetrole);
};