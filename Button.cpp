#include "Button.h"
#include <iostream>
Button::Button() {
	initializeButton(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f));
	isTheButtonActive = false;
}

Button::Button(std::string textureLocation, sf::Vector2f buttonSize, sf::Vector2f buttonPosition) {
	initializeButton(buttonSize, buttonPosition);
	loadTexture(textureLocation);
	isTheButtonActive = false;
}

void Button::initializeButton(sf::Vector2f buttonSize, sf::Vector2f buttonPosition) {
	button = sf::RectangleShape(buttonSize);
	button.setPosition(buttonPosition);
}

void Button::loadTexture(std::string textureLocation) {
	buttonTexture.loadFromFile(textureLocation);
	button.setTexture(&buttonTexture);
}

Button::~Button() {

}

sf::RectangleShape Button::displayButton() {

	return button;
}

bool Button::getStatus() {
	return isTheButtonActive;
}

void Button::setStatus(bool status) {
	isTheButtonActive = status;
}