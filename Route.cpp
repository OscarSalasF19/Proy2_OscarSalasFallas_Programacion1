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
		std::cout << "guarde 1" << std::endl;
	}
	else {
		newPoint->setNext(header);
		header->setPrev(newPoint);
		header = newPoint;
		std::cout << "guardo el punto " << header->getPosition().x << " , " << header->getPosition().y << std::endl;
		if (header->getNext()) {
			std::cout << "guardo el punto " << header->getNext()->getPosition().x << " , " << header->getNext()->getPosition().y << std::endl;

		}


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
			current = current->getNext();
		}

	}

}

void Route::coutPoints() {
	Point* current = header;

	while (current->getNext() != NULL) {
		std::cout << "the point is (" << current->getPosition().x << " , " << current->getPosition().y << ") \n";
		current = current->getNext();
	}
}

void Route::checkClick(sf::Vector2f mouseClick) {
	Point* current = header;
	bool isThePointInTheList = false;
	std::cout << "entre a comprobacion" << std::endl;
	while (current != nullptr && !isThePointInTheList) {
		std::cout << "entre al while" << std::endl;
		float dx = mouseClick.x - current->getPosition().x;
		float dy = mouseClick.y - current->getPosition().y;
		float distance = sqrt(dx * dx + dy * dy);

		if (distance <= 10) {
			isThePointInTheList = true;
			std::cout << "entre al primer if" << std::endl;
		}
		else {
			current = current->getNext();
			std::cout << "entre al segundo if" << std::endl;

		}
	}

	if (isThePointInTheList) {
		std::cout << "empiezo a borrar";
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