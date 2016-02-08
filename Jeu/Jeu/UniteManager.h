#ifndef PROJET_UNITEMANAGER_H
#define PROJET_UNITEMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>
#include "Unite.h"
#include "UniteArmee.h"
#include "UniteUtilitaire.h"
#include "ArmeManager.h"
#include "Outil.h"

class UniteManager {
private:
	ArmeManager manager = ArmeManager();
	std::map<std::string, Unite*> m_unites;

public:
	UniteManager();

	void addUnite(const std::string& name, Unite unite);

	Unite* getRef(const std::string& unite);

	Unite* creerUnite(const std::string &unite, int x, int y);
};


#endif //PROJET_UNITEMANAGER_H
#pragma once