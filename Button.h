#pragma once
#include<SFML/Graphics.hpp>
class Button
{
private:
	sf::RectangleShape button;
	bool isTheButtonActive;
	sf::Font buttonFont;
	sf::Text buttonName;

public:
	Button();

	~Button();

	Button(std::string buttonName, sf::Vector2f buttonSize, sf::Vector2f buttonPosition);

	void initializeButton(sf::Vector2f buttonSize, sf::Vector2f buttonPosition);

	void loadText(std::string buttonName);

	void displayButton(sf::RenderWindow& window);

	bool getStatus();

	void setStatus(bool status);

	sf::RectangleShape getButton();
};

