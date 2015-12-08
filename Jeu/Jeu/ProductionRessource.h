#pragma once

#include "Batiment.h"
#include "Ressource.h"

class ProductionRessource : public Batiment
{
public:
    ProductionRessource();
    ~ProductionRessource();

    int getQuantiteProduite();
    void setQuantiteProduite(int quantiteProduite);
    Ressource getRessource();
    Ressource setRessource(Ressource ressource);

private:
    int quantiteProduite;
    Ressource ressource;
};