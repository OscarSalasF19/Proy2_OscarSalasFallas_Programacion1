#pragma once
#include"Point.h"
#include <iostream>
class Route
{
private:
	std::string routeName;
	Point* header;
	Route* next;
	Route* prev;
public:
	Route();
	Route(std::string newName);
	~Route();
	void addPoint(sf::Vector2f pointPosition, int pointColor[]);
	void setNext(Route* newRoute);
	void setprev(Route* newRoute);
	Route* getNext();
	Route* getPrev();
	std::string getName();
	Point* getHeader();
	void deletePoint(Point* pointToDelete);
	void setName(std::string newName);

	void drawPoints(sf::RenderWindow* window);

	void coutPoints();

	void checkClick(sf::Vector2f mouseClick);
	
	std::string serialize();

};