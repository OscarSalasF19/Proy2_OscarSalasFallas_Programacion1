#include "Button.h"
#include <iostream>
Button::Button() {
	initializeButton(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f));
	isTheButtonActive = false;
}

Button::Button(std::string buttonName, sf::Vector2f buttonSize, sf::Vector2f buttonPosition) {
	initializeButton(buttonSize, buttonPosition);
	loadText(buttonName);
	isTheButtonActive = false;

}

void Button::initializeButton(sf::Vector2f buttonSize, sf::Vector2f buttonPosition) {
	button = sf::RectangleShape(buttonSize);
	button.setPosition(buttonPosition);
	button.setFillColor(sf::Color::Black);
}

void Button::loadText(std::string ButtonName) {
	buttonFont.loadFromFile("font.ttf");
	buttonName = sf::Text(sf::String(ButtonName), buttonFont, 50);
	buttonName.setFillColor(sf::Color::White);
	buttonName.setOrigin(buttonName.getGlobalBounds().width / 2, buttonName.getGlobalBounds().height / 2);
	buttonName.setPosition(button.getPosition().x + button.getGlobalBounds().width / 2, button.getPosition().y + button.getGlobalBounds().height / 2.5);
}

Button::~Button() {

}

void Button::displayButton(sf::RenderWindow& window) {
	window.draw(button);
	window.draw(buttonName);
}

bool Button::getStatus() {
	return isTheButtonActive;
}

void Button::setStatus(bool status) {
	isTheButtonActive = status;
}

sf::RectangleShape Button::getButton() {
	return button;
}