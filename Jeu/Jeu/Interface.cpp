#include "Interface.h"
#include "Technologie.h"
#include "Button.h"

Interface::Interface()
{
	setModeNormal();
	this->width = 0;
	this->height = 0;
}

Interface::Interface(int width, int height) {
	setModeNormal();
	this->width = width;
	this->height = height;
}

void Interface::resize(int width, int height)
{
	this->width = width;
	this->height = height;
}

void Interface::setModeNormal() {
	modeNormal = true;
	modeBatiment = false;
}

bool Interface::getModeNormal() {
	return modeNormal;
}

void Interface::setModeBatiment() {
	modeNormal = false;
	modeBatiment = true;
}

bool Interface::getModeBatiment() {
	return modeBatiment;
}

void Interface::clic(Game* game, int x, int y)
{
	for (int i = 0; i < m_buttons.size(); i++)
	{
		if (m_buttons.at(i)->clic(game, x, y))
		{
			return;
		}
	}
}

void Interface::ajouterBouton(Button* button)
{
	m_buttons.push_back(button);
}

void Interface::render(sf::RenderWindow *renderWindow, SpriteManager *manager) {
	int longueur = width / 10;
	int hauteur = INTERFACE_HEIGTH / 30;

	manager->getRef("gui_haut_gauche").setPosition(0, height - INTERFACE_HEIGTH);
	renderWindow->draw(manager->getRef("gui_haut_gauche"));
	for (int i = 1; i < longueur-1; i++)
	{
		manager->getRef("gui_haut_milieu").setPosition(i * 10, height - INTERFACE_HEIGTH);
		renderWindow->draw(manager->getRef("gui_haut_milieu"));
	}
	manager->getRef("gui_haut_droite").setPosition(width-10, height - INTERFACE_HEIGTH);
	renderWindow->draw(manager->getRef("gui_haut_droite"));

	for (int i = 1; i < hauteur; i++)
	{
		manager->getRef("gui_centre_gauche").setPosition(0, height - INTERFACE_HEIGTH + i * 30);
		renderWindow->draw(manager->getRef("gui_centre_gauche"));
		for (int j = 1; j < longueur-1; j++)
		{
			manager->getRef("gui_centre_milieu").setPosition(j * 10, height - INTERFACE_HEIGTH + i * 30);
			renderWindow->draw(manager->getRef("gui_centre_milieu"));
		}
		manager->getRef("gui_centre_droite").setPosition(width-10, height - INTERFACE_HEIGTH + i * 30);
		renderWindow->draw(manager->getRef("gui_centre_droite"));
	}

	manager->getRef("gui_bas_gauche").setPosition(0, height - 30);
	renderWindow->draw(manager->getRef("gui_bas_gauche"));
	for (int i = 1; i < longueur - 1; i++)
	{
		manager->getRef("gui_bas_milieu").setPosition(i * 10, height - 30);
		renderWindow->draw(manager->getRef("gui_bas_milieu"));
	}
	manager->getRef("gui_bas_droite").setPosition(width - 10, height - 30);
	renderWindow->draw(manager->getRef("gui_bas_droite"));


	//renderWindow->draw(manager->getRef("interface"));
	//renderWindow->draw(manager->getRef("interfaceBarre"));

	return;
}

void Interface::renderTechnologies(sf::RenderWindow *renderWindow, sf::Font font, Technologie* technologie){
	std::string msgTech, nom, description, vivres, petrole, metaux, energies ;

	msgTech = "TECHNOLOGIE";
	nom = technologie->getNom();
	description = "Description : " + technologie->getDescription();
	energies = "Cout en energie : " + std::to_string(technologie->getCoutEnergie());
	metaux = "Cout en metaux : " + std::to_string(technologie->getCoutMetal());
	petrole = "Cout en petrole : " + std::to_string(technologie->getCoutPetrole());
	vivres = "Cout en vivre : " + std::to_string(technologie->getCoutVivre());

	float posX = 300;
	float posY = height - INTERFACE_HEIGTH + 50;

	ecrireMessage(renderWindow, posX, posY, msgTech, font, 12, sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 15, nom, font, 12, sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 15*2, description, font, 12, sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 15*3, energies, font, 12, sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 15*4, metaux, font, 12, sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 15*5, petrole, font, 12, sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 15*6, vivres, font, 12, sf::Color::Black);

	ecrireMessage(renderWindow, posX + 350, posY + 125, "Acheter", font, 20, sf::Color::Black);
}

void Interface::renderInfoBatiment(sf::RenderWindow *renderWindow, sf::Font font, Batiment* batiment) {
	std::string msgBatiement, nom, description, vivres, petrole, metaux, energies;

	msgBatiement = "BATIMENT";
	nom = batiment->getNom();
	description = "Description : " + batiment->getDescription();
	energies = "Cout en energie : " + std::to_string(batiment->getCoutEnergie());
	metaux = "Cout en metaux : " + std::to_string(batiment->getCoutMetal());
	petrole = "Cout en petrole : " + std::to_string(batiment->getCoutPetrole());
	vivres = "Cout en vivre : " + std::to_string(batiment->getCoutVivre());

	float posX = 403;
	float posY = 805;

	ecrireMessage(renderWindow, posX, posY, msgBatiement, font, 18, sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 25, nom, font, 18, sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 25 * 2, description, font, 18, sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 25 * 3, energies, font, 18, sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 25 * 4, metaux, font, 18, sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 25 * 5, petrole, font, 18, sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 25 * 6, vivres, font, 18, sf::Color::Black);

	ecrireMessage(renderWindow, posX + 350, posY + 125, "Construire", font, 20, sf::Color::Black);
}

void Interface::renderInfoUnite(sf::RenderWindow *renderWindow, sf::Font font, Unite *unite) {
	std::string nom, vie, reserve,description, deplacement, vision, res;

	nom = "Nom : " + unite->getNom();
	description = "Description : " + unite->getDescription();
	
	reserve = "Reserve : ";
	reserve = reserve + std::to_string(unite->getStockRessActuel()) + "/"+ std::to_string(unite->getStockMaxRess());
	
	vie = "Vie : ";
	vie = vie + std::to_string(unite->getPvRestant()) + "/10";
	
	deplacement = "Deplacement : ";
	deplacement = deplacement + std::to_string(unite->getDeplacementMax()-1);
	
	vision = "Vision : ";
	vision = vision + std::to_string(unite->getChampVision()-1);
	
	res = "Resistance env. : ";
	res = res + std::to_string(unite->getResistance());

	float posX = 403;
	float posY = 805;

	ecrireMessage(renderWindow, posX, posY, nom, font, 18,sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 18, description, font, 18, sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 18*2, vie, font, 18, sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 18*3, reserve, font, 18, sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 18*4, deplacement, font, 18, sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 18*5, vision, font, 18, sf::Color::Black);
	ecrireMessage(renderWindow, posX, posY + 18*6, res, font, 18, sf::Color::Black);
	
	if (unite->isArmee()) {
		UniteArmee* armee = (UniteArmee*)unite;
		std::string mun = "Munition : ", port = "Portee : ";
		mun = mun + std::to_string(armee->getStockMunActuel()) + '/' + std::to_string(armee->getStockMaxMun());
		port = port + std::to_string(armee->getRangeMin()-1) + '/' + std::to_string(armee->getRangeMax()-1);

		ecrireMessage(renderWindow, posX, posY + 18*7, mun, font, 18, sf::Color::Black);
		ecrireMessage(renderWindow, posX, posY + 18*8, port, font, 18, sf::Color::Black);
	}
}

void Interface::ecrireMessage(sf::RenderWindow *renderWindow, float posX, float posY, std::string msg, sf::Font font, int fontSize, sf::Color color) {
	sf::Text text;
	text.setString(msg);
	text.setPosition(sf::Vector2f(posX, posY));
	text.setColor(color);
	text.setCharacterSize(fontSize);
	text.setFont(font);
	text.setStyle(sf::Text::Bold);
	renderWindow->draw(text);
}