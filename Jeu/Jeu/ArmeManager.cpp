#include "ArmeManager.h"
ArmeManager::ArmeManager() {
	m_armes["ScieHache"] = Arme ("Scie-Hache", 5, 1, 0, 0);
	m_armes["null"] = Arme ("null", 0, 0, 0, 0);
	m_armes["Harpon"] = Arme ("Harpon", 8, 4, 6, 0);
	m_armes["Balle"] = Arme ("Balle", 6, 2, 2, 0);
	m_armes["Roquette"] = Arme ("Roquette", 4, 6, 6, 4);
	m_armes["Canon"] = Arme ("Canon", 3, 7, 0, 5);
	m_armes["Missile"] = Arme ("Missile", 0, 0, 8, 0);
	m_armes["Torpille"] = Arme ("Torpille", 0, 0, 0, 8);
	m_armes["Bombe"] = Arme("Bombe", 8, 7, 0, 6);
}

Arme* ArmeManager::getRef(const std::string &arme)
{
	return new Arme(m_armes.at(arme));
}