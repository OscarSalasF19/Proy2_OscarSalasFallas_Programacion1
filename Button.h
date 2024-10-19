#pragma once
#include<SFML/Graphics.hpp>
class Button
{
private:
	sf::RectangleShape button;
	sf::Texture buttonTexture;
	bool isTheButtonActive;

public:
	Button();

	~Button();

	Button(std::string textureLocation, sf::Vector2f buttonSize, sf::Vector2f buttonPosition);

	void initializeButton(sf::Vector2f buttonSize, sf::Vector2f buttonPosition);

	void loadTexture(std::string textureLocation);

	sf::RectangleShape displayButton();

	bool getStatus();

	void setStatus(bool status);
};