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

	Route* current = Header;
	
	while (current->getName() != routeName && current) {
		current = current->getNext();
	}
	if (current->getName() == routeName) {
		if (current == Header) {
			if (current->getNext() == nullptr && current->getPrev() == nullptr) {
				Header = nullptr;
				delete current;
				return;
			}
			current->getNext()->setprev(nullptr);
			Header = current->getNext();
			delete current;
			return;
		}
		else if (current->getNext() == nullptr) {
			current->getPrev()->setNext(current->getNext());
			current->setprev(nullptr);
			current->setNext(nullptr);
			delete current;
			return;
		}else{
			current->getPrev()->setNext(current->getNext());
			current->getNext()->setprev(current->getPrev());
			current->setNext(nullptr);
			current->setprev(nullptr);
			delete current;
			return;
		}
	}	
}

bool Server::IsTheRouteOnTheList(std::string routeName) {
	Route* current = Header;

	while (current) {
		if (current->getName() == routeName) {
			return true;
		}
		current = current->getNext();
	}
	return false;
}

std::string Server::serialize() {
	std::string line = "";
	Route* current = Header;

	while (current) {
		line += current->serialize();
		current = current->getNext();
	}

	return line;

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

std::string Server::getRouteNames() {
	Route* current = Header;
	std::string line = "";
	while (current) {
		line += current->getName() + "\n";
		current = current->getNext();
	}

	return line;
}
	
Route* Server::getSpecificRoute(std::string routeName) {
	Route* current = Header;

	while (current) {
		if (current->getName() == routeName) {
			return current;
		}
		current = current->getNext();
	}
	return nullptr;
}

Route* Server::getHeader() {
	return Header;
}
