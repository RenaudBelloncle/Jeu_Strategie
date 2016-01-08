#ifndef PROJET_ARMEMANAGER_H
#define PROJET_ARMEMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>
#include "Arme.h"

class ArmeManager {
private:
	std::map<std::string, Arme> m_armes;

public:
	ArmeManager();

	Arme* getRef(const std::string &arme);
};


#endif //PROJET_ARMEMANAGER_H
#pragma once
