#include "Interface.h"

Interface::Interface() {
	getModeNormal();
}

void Interface::setModeNormal() {
	modeNormal = true;
	modeUnite = false;
	modeBatiment = false;
}

bool Interface::getModeNormal() {
	return modeNormal;
}

void Interface::setModeUnite() {
	modeNormal = false;
	modeUnite = true;
	modeBatiment = false;
}

bool Interface::getModeUnite() {
	return modeUnite;
}

void Interface::setModeBatiment() {
	modeNormal = false;
	modeUnite = false;
	modeBatiment = true;
}

bool Interface::getModeBatiment() {
	return modeBatiment;
}

void Interface::render(sf::RenderWindow *renderWindow, SpriteManager *manager) {
	if (modeNormal) {
		renderWindow->draw(manager->getRef("interface"));
		return;
	}
	else if (modeUnite) {
		renderWindow->draw(manager->getRef("interface"));
		return;
	}
	else if (modeBatiment) {
		renderWindow->draw(manager->getRef("interface"));
		return;
	}
}
