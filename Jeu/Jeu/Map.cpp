#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"

Map::Map()
{
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

void Map::render(sf::RenderWindow *renderWindow)
{
    sf::Font font;
    if (!font.loadFromFile("media/Constantine.ttf"))
    {
        std::cerr << "Erreur chargement Font" << std::endl;
        std::exit(1);

    }
    sf::Text text;
    text.setFont(font);

    sf::RectangleShape rectangleShape(sf::Vector2f(SPRITE,SPRITE));

    for (int i = 0; i < MAP_WIDTH; ++i)
    {
        for (int j = 0; j < MAP_HEIGTH; ++j)
        {
            switch (m_tiles[i][j].getTypeCase())
            {
                case TypeCase::PLAINE:
                    rectangleShape.setFillColor(sf::Color(0,255,0));
                    break;

                case TypeCase::PLAGE:
                    rectangleShape.setFillColor(sf::Color(255,255,0));
                    break;

                case TypeCase::MONTAGNE:
                    rectangleShape.setFillColor(sf::Color(90,60,30));
                    break;

                case TypeCase::MER:
                    rectangleShape.setFillColor(sf::Color(0,0,255));
                    break;

                case TypeCase::FORET:
                    rectangleShape.setFillColor(sf::Color(0,100,0));
                    break;

                case TypeCase::MARAIS:
                    rectangleShape.setFillColor(sf::Color(150,255,150));
                    break;

                case TypeCase::COLINE:
                    rectangleShape.setFillColor(sf::Color(170,140,100));
                    break;

                case TypeCase::VILLE:
                    rectangleShape.setFillColor(sf::Color(150,150,150));
                    break;

                case TypeCase::RUINE:
                    rectangleShape.setFillColor(sf::Color(0,0,0));
                    break;
            }
            switch (m_tiles[i][j].getRessource()) {
                case Ressource::VIVRES :
                    text.setString("V");
                    break;

                case Ressource::METAL :
                    text.setString("M");
                    break;

                case Ressource::PETROLE :
                    text.setString("P");
                    break;

                default:
                    text.setString("");
                    break;
            }

            rectangleShape.setPosition(sf::Vector2f(i*SPRITE,j*SPRITE));
            text.setPosition(sf::Vector2f(i*SPRITE,j*SPRITE));
            renderWindow->draw(rectangleShape);
            renderWindow->draw(text);
        }
    }
}