#include "Palette.h"
#include <iostream>
Palette::Palette() {
	initializeButton(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f));
	isTheButtonActive = false;
}

Palette::Palette(std::string textureLocation, sf::Vector2f buttonSize, sf::Vector2f buttonPosition) {
	initializeButton(buttonSize, buttonPosition);
	loadTexture(textureLocation);
	isTheButtonActive = false;
}

void Palette::initializeButton(sf::Vector2f buttonSize, sf::Vector2f buttonPosition) {
	button = sf::RectangleShape(buttonSize);
	button.setPosition(buttonPosition);
}

void Palette::loadTexture(std::string textureLocation) {
	buttonTexture.loadFromFile(textureLocation);
	button.setTexture(&buttonTexture);
}

Palette::~Palette() {

}

sf::RectangleShape Palette::displayButton() {

	return button;
}

bool Palette::getStatus() {
	return isTheButtonActive;
}

void Palette::setStatus(bool status) {
	isTheButtonActive = status;
}