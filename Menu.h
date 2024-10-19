#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Button.h"
class Menu
{
private:
	sf::RenderWindow* window;

	sf::Event evnt;

	sf::Texture mapTexture;

	sf::RectangleShape map;

	Button* AddPoints;

	Button* deletePoints;

	Button* loadPoints;

	Button* Palette;

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

	void initializeColorPalette();

	void displayColorPalette();

	void eventScenarios();

	void pressAddButton(sf::Vector2i mousePosition);

	void pressDeleteButton(sf::Vector2i mousePosition);

	void pressLoadButton(sf::Vector2i mousePosition);

};