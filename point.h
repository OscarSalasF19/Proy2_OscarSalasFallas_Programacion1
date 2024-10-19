#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
class Point
{
private:
	sf::CircleShape point;
	sf::Color pointColor;
	sf::Vector2f pointPosition;

public:
	Point(sf::Vector2f newPosition, sf::Color newColor);

	~Point();

	void SetColor(sf::Color newColor);

	void initializePoint();

	sf::CircleShape getPoint();


};

