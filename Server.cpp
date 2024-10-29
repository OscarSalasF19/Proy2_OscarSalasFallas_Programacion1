#include "Server.h"


void Server::addRoute(Route* newRoute) {
	if (!Header) {
		Header = newRoute;
	}
	else {
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
	