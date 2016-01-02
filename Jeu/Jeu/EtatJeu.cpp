#include "EtatJeu.h"

EtatJeu::EtatJeu(Game* jeu, sf::RenderWindow* window)
{
    this->jeu = jeu;
    this->window = window;
    //Constructeur avec initialisation
}

EtatJeu::~EtatJeu()
{
    //Destructeur
}

void EtatJeu::update(int delta)
{
    //Mise à jour
}

void EtatJeu::render()
{
    //Rendu
}