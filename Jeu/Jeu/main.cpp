#include <cstdio>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "map.h"
#include "TextureManager.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#define MAP_WIDTH 20
#define MAP_HEIGHT 15

int main(int argc, char const *argv[])
{
	int c_view[2] = {400, 300};
	Map map(MAP_WIDTH, MAP_HEIGHT);

	TextureManager::load("img/empty.png", "empty");
	TextureManager::load("img/grass.png", "grass");
	TextureManager::load("img/water.png", "water");
	TextureManager::load("img/dirt.png", "dirt");
	TextureManager::load("img/mountain.png", "mountain");
	TextureManager::load("img/desert.png", "desert");

	sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "This Game Is Awesome !!!");
	sf::View view(sf::Vector2f(c_view[0], c_view[1]), sf::Vector2f(800, 600));
	sf::Vector2i localPosition;

	window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(60);

	sf::Clock deltaClock;
	while(window.isOpen()){
		int dt = deltaClock.restart().asMilliseconds();
		sf::Event event;
		while(window.pollEvent(event)){

			if(event.type == sf::Event::Closed){
				window.close();
			}

			if(event.type == sf::Event::KeyPressed){

				switch(event.key.code){

					case sf::Keyboard::Left: if(c_view[0] - ((WIN_WIDTH / 2) - 2 * 40) > 0) c_view[0] -= 20; break;
					case sf::Keyboard::Right: if(c_view[0] + (WIN_WIDTH / 2) - 2 * 40 < WIN_WIDTH) c_view[0] += 20; break;
					case sf::Keyboard::Up: if(c_view[1] - ((WIN_HEIGHT / 2) - 2 * 40) > 0) c_view[1] -= 20; break;
					case sf::Keyboard::Down: if(c_view[1] + (WIN_HEIGHT / 2) - 2 * 40 < WIN_HEIGHT) c_view[1] += 20; break;
					case sf::Keyboard::Space: c_view[0] = 400; c_view[1] = 300; break;
					default: break;
				}
			}
		}

		localPosition = sf::Mouse::getPosition(window);
		if(localPosition.x < 2 * 40){
			if(c_view[0] - ((WIN_WIDTH / 2) - 2 * 40) > 0) c_view[0] -= dt / 50.f;
		}

		if(localPosition.x > WIN_WIDTH - 2 * 40){
			if(c_view[0] + (WIN_WIDTH / 2) - 2 * 40 < WIN_WIDTH) c_view[0] += dt / 50.f;
		}

		if(localPosition.y < 2 * 40){
			if(c_view[1] - ((WIN_HEIGHT / 2) - 2 * 40) > 0) c_view[1] -= dt / 50.f;
		}

		if(localPosition.y > WIN_HEIGHT - 2 * 40){
			if(c_view[1] + (WIN_HEIGHT / 2) - 2 * 40 < WIN_HEIGHT) c_view[1] += dt / 50.f;
		}

		window.clear(sf::Color::Red);
		map.print(&window);
		view.setCenter(c_view[0], c_view[1]);
		window.setView(view);
		window.display();
	}
	return 0;
}