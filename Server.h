#pragma once
#include"Route.h"
class Server
{
private:
	Route* Header;

public:
	Server() : Header(nullptr) {}
	void addRoute(Route* newRoute);
	void deleteRoute(std::string routeName);
	bool IsTheRouteOnTheList(std::string routeName);
};

