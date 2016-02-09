#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "SpriteManager.h"

class Button 
{
private : 
	bool enabled, pressed;
	sf::Sprite spritePressed, spriteReleased;
	sf::Vector2i coord;
	std::string name;

public :
	Button(std::string _name, sf::Vector2i _coord);
	void buttonPressed();
	void buttonReleased();
	void setEnabled();

	void render();

	
};