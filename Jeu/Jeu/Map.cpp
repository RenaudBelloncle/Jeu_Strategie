#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"

Map::Map()
{
	std::cout << "Creation de la map" << std::endl;
    //randomMapGenerator();
    std::vector<int> tab;
    for (int i = 0; i < MAP_WIDTH; ++i) {
        for (int j = 0; j < MAP_HEIGTH; ++j) {
            tab.push_back(i + j);
        }
    }
    std::random_shuffle(tab.begin(), tab.end());

    for (int i = 0; i < MAP_WIDTH; ++i) {
        for (int j = 0; j < MAP_HEIGTH; ++j) {
            permutation[i+j] = (unsigned int)(tab.at((unsigned long)(i + j)));
        }
    }
    mapGenerator();
	std::cout << "Création de la map terminee" << std::endl;
}

void Map::randomMapGenerator()
{
    for (int i = 0; i < MAP_WIDTH; ++i)
    {
        for (int j = 0; j < MAP_HEIGTH; ++j)
        {
            TypeCase typeCase = static_cast<TypeCase>(rand() % 9);
            m_tiles[i][j] = Tile(typeCase);
        }
    }
}

void Map::mapGenerator()
{
    for (int i = 0; i < MAP_WIDTH; ++i) {
        for (int j = 0; j < MAP_HEIGTH; ++j) {
            m_tiles[i][j] = whichType(bruitPerlin(i+0.5f,j+0.5f,10));
        }
    }
}

float Map::bruitPerlin(float x, float y, float res)
{
    float tempX, tempY;
    int x0, y0, ii, jj, gi0, gi1, gi2, gi3;
    float unit = (float)(1.0f / sqrt(2));
    float tmp, s, t, u, v, Cx, Cy, Li1, Li2;
    float gradient2[8][2] = {{unit,unit},{-unit,unit},{unit,-unit},{-unit,-unit},
                             {1,0},{-1,0},{0,1},{0,-1}};

    x /= res;
    y /= res;

    x0 = (int)(x);
    y0 = (int)(y);

    ii = x0 & 255;
    jj = y0 & 255;

    gi0 = permutation[ii + permutation[jj]] % 8;
    gi1 = permutation[ii + 1 + permutation[jj]] % 8;
    gi2 = permutation[ii + permutation[jj + 1]] % 8;
    gi3 = permutation[ii + 1 + permutation[jj + 1]] % 8;

    tempX = x - x0;
    tempY = y - y0;
    s = gradient2[gi0][0] * tempX + gradient2[gi0][1] * tempY;

    tempX = x - (x0 + 1);
    tempY = y - y0;
    t = gradient2[gi1][0] * tempX + gradient2[gi1][1] * tempY;

    tempX = x - x0;
    tempY = y - (y0 + 1);
    u = gradient2[gi2][0] * tempX + gradient2[gi2][1] * tempY;

    tempX = x - (x0 + 1);
    tempY = y - (y0 + 1);
    v = gradient2[gi3][0] * tempX + gradient2[gi3][1] * tempY;

    tmp = x - x0;
    Cx = 3 * tmp * tmp - 2 * tmp * tmp * tmp;

    Li1 = s + Cx * (t - s);
    Li2 = u + Cx * (v - u);

    tmp = y - y0;
    Cy = 3 * tmp * tmp - 2 * tmp * tmp * tmp;

    return Li1 + Cy * (Li2 - Li1);
}

TypeCase Map::whichType(float hauteur)
{
    if (hauteur <= -0.05) return TypeCase::MER;
    else if (hauteur <= 0) return TypeCase::PLAGE;
    else if (hauteur <= 0.3) return TypeCase::PLAINE;
    else if (hauteur <= 0.4) return TypeCase::COLINE;
    else return TypeCase::MONTAGNE;
}

Tile Map::getTile(int x, int y) {
	return m_tiles[x][y];
}

void Map::render(sf::RenderWindow *renderWindow, SpriteManager *manager)
{
	m_imageMinimap.create(MAP_WIDTH, MAP_HEIGTH);
	m_imageRessource.create(MAP_WIDTH, MAP_HEIGTH);
	for (int i = 0; i < MAP_WIDTH; ++i)
	{
		for (int j = 0; j < MAP_HEIGTH; ++j)
		{
			sf::Sprite terrain, ressource;
			switch (m_tiles[i][j].getTypeCase())
			{
				case TypeCase::PLAINE:
					m_imageMinimap.setPixel(i, j, sf::Color(0, 255, 0));
					terrain = manager->getRef("plaine");
					break;

				case TypeCase::PLAGE:
					m_imageMinimap.setPixel(i, j, sf::Color(255, 255, 0));
					terrain = manager->getRef("plage");
					break;

				case TypeCase::MONTAGNE:
					m_imageMinimap.setPixel(i, j, sf::Color(90, 60, 30));
					terrain = manager->getRef("montagne");
					break;

				case TypeCase::MER:
					m_imageMinimap.setPixel(i, j, sf::Color(0, 0, 255));
					terrain = manager->getRef("mer");
					break;

				case TypeCase::FORET:
					m_imageMinimap.setPixel(i, j, sf::Color(0, 100, 0));
					terrain = manager->getRef("foret");
					break;

				case TypeCase::MARAIS:
					m_imageMinimap.setPixel(i, j, sf::Color(150, 255, 150));
					terrain = manager->getRef("marais");
					break;

				case TypeCase::COLINE:
					m_imageMinimap.setPixel(i, j, sf::Color(170, 140, 100));
					terrain = manager->getRef("coline");
					break;

				case TypeCase::VILLE:
					m_imageMinimap.setPixel(i, j, sf::Color(0, 0, 0));
					terrain = manager->getRef("ville");
					break;

				case TypeCase::RUINE:
					m_imageMinimap.setPixel(i, j, sf::Color(150, 150, 150));
					terrain = manager->getRef("ruine");
					break;
				default : 
					m_imageMinimap.setPixel(i, j, sf::Color(0,0,0));
					terrain = manager->getRef("void");
					break;
				}
			switch (m_tiles[i][j].getRessource()) {
			case Ressource::VIVRES:
				ressource = manager->getRef("vivre");
				m_imageRessource.setPixel(i, j, sf::Color(250, 90, 0));
				break;

			case Ressource::METAL:
				ressource = manager->getRef("metal");
				m_imageRessource.setPixel(i, j, sf::Color(250, 250, 250));
				break;

			case Ressource::PETROLE:
				ressource = manager->getRef("petrole");
				m_imageRessource.setPixel(i, j, sf::Color(50, 50, 50));
				break;
			}

			terrain.setPosition(sf::Vector2f(i*SPRITE, j*SPRITE));
			ressource.setPosition(sf::Vector2f(i*SPRITE, j*SPRITE));
			renderWindow->draw(terrain);
			renderWindow->draw(ressource);
		}
	}
}

