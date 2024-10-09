#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
class Menu
{
private:
	sf::RenderWindow* window;
	sf::Event evnt;
	sf::Texture mapTexture;
	sf::RectangleShape map;
	sf::RectangleShape addPointButton;
	sf::RectangleShape deletePointButton;
	sf::RectangleShape loadRouteButton;
	sf::Texture addingPointsTexture;
	sf::Texture deletingPointsTexture;
	sf::Texture loadingPointsTexture;
	bool isTheAddActive;
	bool isTheDeleteActive;




public:
	Menu();
	~Menu();
	void displayWindow();
	void loadTexture();
	void initializeWindow();
	void intializeMap();
	void intializeAddButton();
	void intializeDeleteButton();
	void intializeLoadButton();
	void displayMenu();
};
