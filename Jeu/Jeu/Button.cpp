#include "Button.h"

Button::Button(std::string _name, sf::Vector2i _coord, sf::Vector2i _taille, sf::Sprite _sprite, void(Game::*_func)(void))
{
	this->name = _name;
	this->coord = _coord;
	this->taille = _taille;
	this->func = _func;
	this->sprite = _sprite;
}

bool Button::clic(Game* game, int x, int y)
{
	if (x >= coord.x && x <= coord.x + taille.x && y >= coord.y && y <= coord.y + taille.y)
	{
		(game->*func)();
		return true;
	}
	return false;
}

void Button::render(sf::RenderWindow *renderWindow)
{
	sprite.setPosition(coord.x, coord.y);
	renderWindow->draw(sprite);
}