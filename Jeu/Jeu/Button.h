#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "SpriteManager.h"
#include "Game.h"

class Game;

class Button 
{
private : 
	bool enabled, pressed;
	sf::Sprite sprite;
	sf::Vector2i coord;
	sf::Vector2i taille;
	std::string name;
	void(Game::*func)(void);

public :
	Button(std::string _name, sf::Vector2i _coord, sf::Vector2i _taille, sf::Sprite _button, void(Game::*_func)(void));
	void buttonPressed();
	void buttonReleased();
	void setEnabled();
	bool clic(Game* game, int x, int y);

	void render(sf::RenderWindow *renderWindow);

	
};