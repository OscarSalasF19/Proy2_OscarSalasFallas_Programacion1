#include "Server.h"


void Server::addRoute(Route* newRoute) {
	std::cout << "cai al entrar a la funcion" << std::endl;
	if (!Header) {
		std::cout << "cai al entrar al primer if" << std::endl;

		Header = newRoute;
	}
	else {
		std::cout << "cai al entrar al segundo if" << std::endl;
		newRoute->setNext(Header);
		Header->setprev(newRoute);
		Header = newRoute;
	}
}

void Server::deleteRoute(std::string routeName) {

	Route* actual = Header;

	while (actual->getName() != routeName || actual->getNext() != nullptr) {
		actual = actual->getNext();
	}

	if (actual == Header) {
		Header = actual->getNext();
	}
	if (actual->getName() == routeName) {
		actual->getPrev()->setNext(actual->getNext());
		actual->getNext()->setprev(actual->getPrev());
		actual->setNext(nullptr);
		actual->setprev(nullptr);

	}
}

bool Server::IsTheRouteOnTheList(std::string routeName) {
	Route* current = Header;

	if (Header) {
		if (current->getNext() == nullptr) {
			if (current->getName() == routeName) {
				return true;
			}
		}
		else {
			while (current->getNext() != nullptr) {
				if (current->getName() == routeName) {
					return true;
				}
				current = current->getNext();
			}
		}
	}
	return false;
}

void Server::saveRoutes() {

	outFile.open("routes.txt");

	if (outFile.is_open()) {
		Route* current = Header;
		while (current) {
			outFile << current->serialize();
			current = current->getNext();
		}
		outFile.close();
	}
	else {
		std::cerr << "unable to open file" << "\n";
	}
}

void Server::loadRoutes() {
	inFile.open("routes.txt");
	Route* currentRoute = nullptr;
	if (inFile.is_open()) {
		std::string line = "";
		while (std::getline(inFile, line)) {
			if (line.find("|") == std::string::npos) {
				currentRoute = nullptr;
				currentRoute = new Route();
				addRoute(currentRoute);
				currentRoute->setName(line.substr(0, line.size()));
			}
			else {
				sf::Vector2f positionPoint;
				std::string position = "";
				std::string color = "";
				int PointColors[3];
				int pos = line.find("|");
				position = line.substr(0, pos);
				line = line.substr(pos + 1, line.size() - pos - 1);
				color = line.substr(0, line.size());
				pos = position.find(",");
				positionPoint.x = std::atof(position.substr(0, pos).c_str());
				position = position.substr(pos + 1, position.size() - pos - 1);
				pos = position.find(",");
				positionPoint.y = std::atof(position.substr(0, position.size()).c_str());
				for (int i = 0; i < 3; i++) {
					pos = color.find(",");
					PointColors[i] = atof(color.substr(0, pos).c_str());
					color = color.substr(pos + 1, line.size() - pos - 1);
				}
				currentRoute->addPoint(positionPoint, PointColors);
			}

		}
	}
	else {
		std::cerr << "unable to open file" << std::endl;
		return;
	}
	inFile.close();
}
	