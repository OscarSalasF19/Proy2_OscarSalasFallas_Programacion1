#include "Route.h"

Route::Route(std::string newName) {
	routeName = newName;
	next = nullptr;
	prev = nullptr;
	header = nullptr;
}

Route::Route() {
	routeName = "";
	next = nullptr;
	prev = nullptr;
	header = nullptr;
}

Route::~Route() {

}

void Route::addPoint(sf::Vector2f pointPosition, int pointColor[]) {
	Point* newPoint = new Point(pointPosition, pointColor);

	if (!header) {
		header = newPoint;
	}
	else {
		newPoint->setNext(header);
		header->setPrev(newPoint);
		header = newPoint;
	}
}

void Route::setNext(Route* newRoute) {
	next = newRoute;
}

void Route::setprev(Route* newRoute) {
	prev = newRoute;
}

Route* Route::getNext() {
	return next;
}

Route* Route::getPrev() {
	return prev;
}

Point* Route::getHeader() {
	return header;
}

void Route::deletePoint(Point* pointToDelete) {
	if (pointToDelete == header) {
		if (header->getNext() != nullptr) {
			header = header->getNext();
			header->setPrev(nullptr);
			pointToDelete->setNext(nullptr);
		}
		else {
			header = nullptr;
			pointToDelete = nullptr;
		}
		delete pointToDelete;
	}
	else if (pointToDelete->getNext() == nullptr) {
		pointToDelete->getPrev()->setNext(pointToDelete->getNext());
		pointToDelete->setPrev(nullptr);
		delete pointToDelete;
	}
	else
	{
		pointToDelete->getPrev()->setNext(pointToDelete->getNext());
		pointToDelete->getNext()->setPrev(pointToDelete->getPrev());
		pointToDelete->setPrev(nullptr);
		pointToDelete->setNext(nullptr);
		delete pointToDelete;

	}
}


std::string Route::getName() {
	return routeName;
}

void Route::setName(std::string newName) {
	routeName = newName;
}

void Route::drawPoints(sf::RenderWindow* window) {
	if (header) {
		Point* current = header;
		while (current)
		{
			current->drawPoint(window);
			if (current->getNext() != nullptr) {
				displayLine(window, current);
			}
			current = current->getNext();
		}

	}

}

void Route::coutPoints() {
	Point* current = header;

	while (current->getNext() != NULL) {
		current = current->getNext();
	}
}

void Route::checkClick(sf::Vector2f mouseClick) {
	Point* current = header;
	bool isThePointInTheList = false;
	while (current != nullptr && !isThePointInTheList) {
		float dx = mouseClick.x - current->getPosition().x;
		float dy = mouseClick.y - current->getPosition().y;
		float distance = sqrt(dx * dx + dy * dy);

		if (distance <= 10) {
			isThePointInTheList = true;
		}
		else {
			current = current->getNext();
		}
	}

	if (isThePointInTheList) {
		deletePoint(current);
	}
}

std::string Route::serialize() {
	std::string line = routeName + "\n";
	Point* current = header;
	while (current)
	{
		line += current->serialize();
		current = current->getNext();
	}
	return line;
}

sf::Vector2f Route::cubicBezier(float t, sf::Vector2f point1, sf::Vector2f midPoint1, sf::Vector2f midPoint2, sf::Vector2f point2) {
	float u = 1 - t;
	float tt = t * t;
	float uu = u* u;
	float uuu = uu * u;
	float ttt = tt * t;

	sf::Vector2f point = uuu * point1;
	point += 3 * uu * t * midPoint1;
	point += 3 * u * tt * midPoint2;
	point += ttt * point2;
	
	return point;
}

void Route::displayLine(sf::RenderWindow* window, Point* current) {
	sf::Vector2f Point1 = current->getPosition();
	sf::Vector2f Point2 = current->getNext()->getPosition();
	sf::Vector2f midPoint1(((Point1.x + Point2.x) / 2) + 50, ((Point1.y + Point2.y) / 2) + 50);
	sf::Vector2f midPoint2(((Point1.x + Point2.x) / 2) -50, ((Point1.y + Point2.y) / 2) - 50);

	

	sf::CircleShape curvedPoints[100];
	int size = 100;
	int amount = 0;

	for (float t = 0; t <= 1; t += 0.01f) {
		sf::Vector2f point = cubicBezier(t, Point1, midPoint1, midPoint2, Point2);
		if (amount < size) {
			curvedPoints[amount].setRadius(6);
			curvedPoints[amount].setOrigin(curvedPoints[amount].getRadius(), curvedPoints[amount].getRadius());
			curvedPoints[amount].setPosition(cubicBezier(t, Point1, midPoint1, midPoint2, Point2));
			curvedPoints[amount].setFillColor(sf::Color(current->getColor(0), current->getColor(1), current->getColor(2)));
			amount++;
		}

	}


	for (int i = 0; i < amount; i++) {
		window->draw(curvedPoints[i]);
	}
}

