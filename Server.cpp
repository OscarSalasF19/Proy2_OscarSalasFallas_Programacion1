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
	