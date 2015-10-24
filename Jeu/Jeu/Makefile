test: main.o map.o tile.o TextureManager.o
	g++ -g main.o map.o tile.o TextureManager.o -o test -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -Wall -c main.cpp

map.o: map.cpp
	g++ -Wall -c map.cpp

tile.o: tile.cpp
	g++ -Wall -c tile.cpp

TextureManager.o: TextureManager.cpp
	g++ -Wall -c TextureManager.cpp