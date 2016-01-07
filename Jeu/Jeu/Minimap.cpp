#include <SFML/Graphics.hpp>
#include <iostream>
#include "Minimap.h"

Minimap::Minimap() {}

Minimap::Minimap(Map *map) {
	m_imageMinimap.create(MAP_WIDTH,MAP_HEIGTH);
	m_imageRessource.create(MAP_WIDTH, MAP_HEIGTH);
	m_topo = true;
	m_ressource = false;
	m_unite = false;
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGTH;j++) {
			switch (map->getTile(i, j).getTypeCase()) {
			case TypeCase::PLAINE:
				m_imageMinimap.setPixel(i, j, sf::Color(0, 255, 0));
				break;

			case TypeCase::PLAGE:
				m_imageMinimap.setPixel(i, j, sf::Color(255, 255, 0));
				break;

			case TypeCase::MONTAGNE:
				m_imageMinimap.setPixel(i, j, sf::Color(90, 60, 30));
				break;

			case TypeCase::MER:
				m_imageMinimap.setPixel(i, j, sf::Color(0, 0, 255));
				break;

			case TypeCase::FORET:
				m_imageMinimap.setPixel(i, j, sf::Color(0, 100, 0));
				break;

			case TypeCase::MARAIS:
				m_imageMinimap.setPixel(i, j, sf::Color(150, 255, 150));
				break;

			case TypeCase::COLINE:
				m_imageMinimap.setPixel(i, j, sf::Color(170, 140, 100));
				break;

			case TypeCase::VILLE:
				m_imageMinimap.setPixel(i, j, sf::Color(0, 0, 0));
				break;

			case TypeCase::RUINE:
				m_imageMinimap.setPixel(i, j, sf::Color(150, 150, 150));
				break;
			default:
				m_imageMinimap.setPixel(i, j, sf::Color(0, 0, 0));
				break;
			}
			switch (map->getTile(i, j).getRessource()) {
			case Ressource::VIVRES:
				m_imageRessource.setPixel(i, j, sf::Color(250, 90, 0));
				break;

			case Ressource::METAL:
				m_imageRessource.setPixel(i, j, sf::Color(250, 250, 250));
				break;

			case Ressource::PETROLE:
				m_imageRessource.setPixel(i, j, sf::Color(50, 50, 50));
				break;
			default:
				m_imageRessource.setPixel(i, j, m_imageMinimap.getPixel(i, j));
			}
		}
	}
}

// Peut être modfifiee pour afficher une map selon les ressources (switch entre les deux modes) 
void Minimap::render(sf::RenderWindow *renderWindow) {
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Image img;
	img.create(MAP_WIDTH, MAP_HEIGTH);
	texture.loadFromImage(img);
	sprite.setTexture(texture);
	if (m_ressource) {
		texture.loadFromImage(m_imageRessource);
		sprite.setTexture(texture);
	}
	else if (m_topo) {
		texture.loadFromImage(m_imageMinimap);
		sprite.setTexture(texture);
	}
	else if (m_unite) {
		return;
	}

	float scale = (float) 165.0 / MAP_WIDTH;
	if ((float) 165.0 / MAP_HEIGTH < scale) {
		scale = (float) 165.0 / MAP_HEIGTH;
	}

	sprite.scale(scale, scale);

	int x = 33 + (165 - MAP_WIDTH*scale) / 2 +70;
	int y = WIN_HEIGTH + 205 + (165 - MAP_HEIGTH*scale) / 2 +20;

	sprite.setPosition(x, y);
	renderWindow->draw(sprite);
}

void Minimap::renderPlayer(sf::RenderWindow *renderWindow, Player *player[], int nbJoueur) {
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Image img;
	img.create(MAP_WIDTH, MAP_HEIGTH);
	for (int j = 0; j < nbJoueur; j ++) {
		for (int i = 0; i < player[j]->getNombreUnite(); i++) {
			Unite* unite = player[j]->getUnite(i);
			img.setPixel(unite->getCoordX(), unite->getCoordY(), player[j]->getColor());
		}

		for (int i = 0; i < player[j]->getNombreBatiment(); i++) {
			Batiment* batiment = player[j]->getBatiment(i);
			img.setPixel(batiment->getCoordX(), batiment->getCoordY(), player[j]->getColor());
		}
	}

	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGTH; j++) {
			if (img.getPixel(i, j) == sf::Color(0, 0, 0)) {
				img.setPixel(i, j, m_imageMinimap.getPixel(i, j));
			}
		}
	}

	float scale = (float) 165.0 / MAP_WIDTH;
	if ((float) 165.0 / MAP_HEIGTH < scale) {
		scale = (float) 165.0 / MAP_HEIGTH;
	}

	texture.loadFromImage(img);
	sprite.setTexture(texture);

	sprite.scale(scale, scale);

	int x = 33 + (165 - MAP_WIDTH*scale) / 2 + 70;
	int y = WIN_HEIGTH + 205 + (165 - MAP_HEIGTH*scale) / 2+20;

	sprite.setPosition(x, y);
	renderWindow->draw(sprite);
}

void Minimap::changeModeTopo() {
	if (!m_topo) {
		m_ressource = false;
		m_unite = false;
		m_topo = true;
	}
}

void Minimap::changeModeRessource() {
	if (!m_ressource) {
		m_ressource = true;
		m_unite = false;
		m_topo = false;
	}
}

void Minimap::changeModeUnite() {
	if (!m_unite) {
		m_ressource = false;
		m_unite = true;
		m_topo = false;
	}
}

bool Minimap::getUniteMode() {
	return m_unite;
}

