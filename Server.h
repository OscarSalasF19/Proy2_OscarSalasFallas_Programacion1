#pragma once
#include"Route.h"
#include<iostream>
#include<fstream>
#include<string>
class Server
{
private:
	Route* Header;

	std::ofstream outFile;
	std::ifstream inFile;

public:
	Server() : Header(nullptr) {}
	void addRoute(Route* newRoute);
	void deleteRoute(std::string routeName);
	bool IsTheRouteOnTheList(std::string routeName);
	std::string serialize();
	void saveRoutes();
	void loadRoutes();
	std::string getRouteNames();

	Route* getSpecificRoute(std::string routeName);
	Route* getHeader();

};

