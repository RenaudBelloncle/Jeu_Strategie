#pragma once
#include <string>

class Arme {
private:
	std::string nom;
	int degInf, degMot, degAer, degMar;
public:
	Arme();
	Arme(std::string _nom, int _degatInf, int _degatMotor, int _degatAerien, int _degatMarin);
	std::string getType();
	int getDegatInfanterie();
	int getDegatMotorise();
	int getDegatAerien();
	int getDegatMarin();
};


