#include "Point.h"
Point::Point(sf::Vector2f pointPosition, int pointColor[]) {
	point = new sf::CircleShape(10.f);
	next = nullptr;
	prev = nullptr;
	for (int i = 0; i < 3; i++) {
		this->pointColor[i] = pointColor[i];
	}
	this->pointPosition = pointPosition;

	point->setPosition(this->pointPosition);
	point->setOrigin(point->getRadius(), point->getRadius());
	point->setFillColor(sf::Color(this->pointColor[0], this->pointColor[1], this->pointColor[2]));
}

Point::Point() {
	point = nullptr;
	next = nullptr;
	prev = nullptr;
	for (int i = 0; i < 3; i++) {
		pointColor[i] = 0;
	}
	pointPosition.x = 0;
	pointPosition.y = 0;

}

Point::~Point() {
}

void Point::setNext(Point* newPoint) {
	next = newPoint;
}

void Point::setPrev(Point* newPoint) {
	prev = newPoint;
}

Point* Point::getNext() {
	return next;
}

Point* Point::getPrev() {
	return prev;
}

sf::Vector2f Point::getPosition() {
	return point->getPosition();
}

void Point::drawPoint(sf::RenderWindow* window) {
	window->draw(*point);
}