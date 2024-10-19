#include "point.h"


Point::Point(sf::Vector2f newPosition, sf::Color newColor) {
	pointPosition = newPosition;
	pointColor = newColor;
	initializePoint();
}

Point::~Point() {

}

void Point::initializePoint() {
	point = sf::CircleShape(10.f);
	point.setFillColor(pointColor);
	point.setPosition(pointPosition);
}

void Point::SetColor(sf::Color newColor) {
	pointColor = newColor;
}

sf::CircleShape Point:: getPoint() {
	return point;
}