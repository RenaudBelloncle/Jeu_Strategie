#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
#include "Constantes.h"

Map::Map()
{
    Map(10,10);
}

Map::Map(int width, int heigth)
{
    for (int i = 0; i < width; ++i)
    {
        m_tiles.push_back(std::vector<Tile>());
        for (int j = 0; j < heigth; ++j)
        {
            TypeCase typeCase = static_cast<TypeCase>(rand() % 9);
            m_tiles[i].push_back(Tile(typeCase));
        }
    }
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
    rectangleShape.setOutlineThickness(2);
    rectangleShape.setOutlineColor(sf::Color(255,255,255));

    for (int i = 0; i < m_tiles.size(); ++i)
    {
        for (int j = 0; j < m_tiles[i].size(); ++j)
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