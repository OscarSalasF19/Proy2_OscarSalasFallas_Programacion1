#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Button.h"
#include"Palette.h"
#include"Route.h"
#include"Server.h"
class Menu
{
private:
	sf::RenderWindow* window;

	sf::Event evnt;

	sf::Texture mapTexture;

	sf::RectangleShape map;

	Button* createRoute;

	Button* loadRoutes;

	Button* exit;

	Button* addPoints;

	Button* deletePoints;

	Button* SaveRoute;

	Palette* palette;

	Button* exitRouteMenu;

	Route* currentRoute;

	int currentColor[3];

	int currentEvent;

	Server* server;


public:
	Menu();

	~Menu();

	void displayWindow();

	void loadTexture();

	void initializeWindow();

	void intializeMap();

	void intializeAddButton();

	void intializeLoadButton();

	void intializeExitButton();

	void displayRouteMenu();

	void eventScenarios();

	void pressAddButton(sf::Vector2f mousePosition);

	void pressLoadButton(sf::Vector2f mousePosition);

	void pressExitButton(sf::Vector2f mousePosition);

	void displayMainMenu();

	void checkMouseRouteMenu(sf::Vector2f mousePosition);

	void checkColorsClicks(sf::Vector2f mousePosition);

	std::string displayNewWindow();
};