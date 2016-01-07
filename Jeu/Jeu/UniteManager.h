#ifndef PROJET_UNITEMANAGER_H
#define PROJET_UNITEMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>
#include "Unite.h"
#include "UniteArmee.h"
#include "ArmeManager.h"

class UniteManager {
private:
	ArmeManager manager = ArmeManager();
	std::map<std::string, Unite*> m_unites;

public:
	UniteManager();

	void addUnite(const std::string& name, Unite unite);

	Unite* getRef(const std::string& unite);
};


#endif //PROJET_UNITEMANAGER_H
#pragma once