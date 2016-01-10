#include "Batiment.h"

Batiment::Batiment(int _x, int _y, string _nom, string _desc, Ressource _ressourceStock, int _maxStock) : Entite(_x, _y, _nom, _desc)
{
	ressourceStock = _ressourceStock;
	maxStock = _maxStock;
	stock = 0;
}

Batiment::~Batiment()
{

}

void Batiment::prendDegat(int degat)
{
	setPvRestant(getPvRestant() - degat);
}

void Batiment::seDeplace(int nbCaseDeplace)
{
	return;
}

void Batiment::soin()
{
	setPvRestant(getPvRestant() + 1);
}

bool Batiment::estDetruit()
{
	if (getPvRestant() <= 0)
	{
		return true;
	}
	return false;
}

bool Batiment::isBatiment()
{
	return true;
}

bool Batiment::isProductionRessource()
{
	return false;
}

bool Batiment::isProductionUnite()
{
	return false;
}

Ressource Batiment::getRessourceStocked()
{
	return ressourceStock;
}

int Batiment::getStock()
{
	return stock;
}

int Batiment::getMaxStock()
{
	return maxStock;
}

void Batiment::render(sf::RenderWindow *renderWindow, sf::Color color, SpriteManager *manager)
{
	/*sf::Sprite fond = getFond(manager);
	fond.setPosition(sf::Vector2f(getCoordX()*SPRITE, getCoordY()*SPRITE));
	fond.setColor(color);
	renderWindow->draw(fond);
	//Draw unite icon
	sf::Sprite icon = getIcon(manager);
	icon.setPosition(sf::Vector2f(getCoordX()*SPRITE, getCoordY()*SPRITE));
	icon.setColor(color);
	renderWindow->draw(icon);
	if (aAgi) {
		sf::Sprite filtreAgi = manager->getRef("filtre agi");
		filtreAgi.setPosition(sf::Vector2f(getCoordX()*SPRITE, getCoordY()*SPRITE));
		filtreAgi.setColor(color);
		renderWindow->draw(filtreAgi);
	}*/
}

void Batiment::update()
{
	
}

void Batiment::setStock(int _stock)
{
	stock = _stock;
	if (stock > maxStock)
	{
		stock = maxStock;
	}
}

void Batiment::setStockMax(int _maxStock)
{
	maxStock = _maxStock;
}
