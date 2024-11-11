#pragma once
#include<SFML/Graphics.hpp>
class Point
{
private:
	sf::CircleShape* point;

	sf::Vector2f pointPosition;

	Point* next;

	Point* prev;

	int pointColor[3];
public:
	Point(sf::Vector2f pointPosition, int pointColor[]);
	Point();
	~Point();
	void setNext(Point* newPoint);
	void setPrev(Point* newPoint);
	Point* getNext();
	Point* getPrev();
	sf::Vector2f getPosition();

	void drawPoint(sf::RenderWindow* window);

	std::string serialize();
};

