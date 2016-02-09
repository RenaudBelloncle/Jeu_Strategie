#pragma once

#include <stack>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "SpriteManager.h"
#include "Map.h"
#include "Minimap.h"
#include "Player.h"
#include "UniteArmee.h"
#include "UniteUtilitaire.h"
#include "Interface.h"
#include "Meteo.h"
#include "MenuPrincipal.h"

class Game
{
private:
	int gameState; // To know if we are in menu or in game
	bool brouillardDeGuerre;
    void loadTextures();
	void loadSprites();

	void definitionCase();
	void definitionCaseDeplacement();
	void definitionCaseAttaque();
	void definitionCaseAttaque(int x, int y);

	sf::Vector2i definitionCaseClique(int x, int y);
	void surbrillanceCaseDeplacement();
	void deplacementAutoPourAttaque(int ecartX, int ecartY, int distance, UniteArmee* unite, int posXEnnemi, int posYEnnemi);

	bool testClicZoneJeu(int x, int y);
	bool testUniteAlliee(int x, int y);
	bool testEntiteEnnemie(int x, int y);
	bool testUniteSelectionneTypeCase(int x, int y);
	void calculNombreTileAffichable();

	bool tech;
    int indice;
	void afficherTechAChercher();
    void afficherPrevTechAChercher();
    void afficherNextTechAChercher();
	std::vector<sf::Vector2f> nettoyerDoublon(std::vector<sf::Vector2f> vector);

    void buyTech();
	MenuPrincipal menu_p;
	Meteo meteo;
	sf::Clock weather_clock;

public:
	Game();
    sf::RenderWindow m_window;
    sf::View m_view, m_viewMinimap, m_viewInterface;
    int c_view[2], m_tour, m_nbJoueur, m_numJoueurActif, m_tileSize;
	sf::Vector2i centreImage, nombreTileAffiche, m_winSize;
    TextureManager m_textureManager;
	SpriteManager m_spriteManager;
	sf::Font font;
	sf::Text textTour;
	sf::Text textEau;
	sf::Text textEnergie;
	sf::Text textPetrole;
	sf::Text textMetaux;

	std::vector<sf::Vector2f> m_deplacement, m_attaque;

    Map m_map;
	Minimap m_minimap;

	Player **m_players, *m_playerActif;

    void render();
	Player* getPlayerActif();

	Unite* m_uniteSelectionne;
	Batiment* m_batimentSelectionne;
    Technologie* m_technologie;

	Interface m_interface;

	void actionUnite(sf::Vector2i caseClique);

	void clic(int x, int y);
	void clicInterface(int x, int y);
	void clicZoneJeu(int x, int y);
	void clicUnite(int x, int y, Unite *unite);
	void clicBatiment(int x, int y);

	void joueurSuivant();
	void finTour();
	void selection(sf::Vector2i caseClique, int x, int y);
	void deselection();

	int getState();
};