#include"Menu.h"


Menu::Menu() {
	for (int i = 0; i < 3; i++) {
		currentColor[i] = 0;
	}
	server = new Server();
	server->loadRoutes();
	currentEvent = 0;
	initializeWindow();
	intializeMap();
	intializeAddButton();
	intializeLoadButton();
	intializeExitButton();
	initializeDeleteRouteButton();
	displayWindow();
}

Menu::~Menu() {

}

void Menu::displayWindow() {
	while (window->isOpen()) {
		while (window->pollEvent(evnt)) {
			eventScenarios();
		}
		displayMainMenu();
		displayRouteMenu();
		window->display();
	}
}

void Menu::displayMainMenu() {
	if (createRoute->getStatus() == false && loadRoutes->getStatus() == false) {
		window->clear(sf::Color::White);
		window->draw(map);
		createRoute->displayButton(*window);
		loadRoutes->displayButton(*window);
		exit->displayButton(*window);
		deleteRoute->displayButton(*window);


	}

}

void Menu::loadTexture() {
	mapTexture.loadFromFile("Map_Of_Proy.jpeg");
	map.setTexture(&mapTexture);
	map.setScale(1.f, 0.79f);
}

void Menu::initializeWindow() {
	window = new sf::RenderWindow(sf::VideoMode(1200, 1000), "Route Desinger", sf::Style::Titlebar | sf::Style::Close);
}

void Menu::intializeMap() {
	map = sf::RectangleShape(sf::Vector2f(800.f, 1280.f));
	loadTexture();
}
void Menu::intializeAddButton() {
	createRoute = new Button("Create Route", sf::Vector2f(300, 100), sf::Vector2f(850, 100));
}

void Menu::intializeLoadButton() {
	loadRoutes = new Button("Load Routes", sf::Vector2f(300, 100), sf::Vector2f(850, 300));

}
void Menu::intializeExitButton() {
	exit = new Button("Exit", sf::Vector2f(300, 100), sf::Vector2f(850, 500));

}


void Menu::displayRouteMenu() {
	addPoints = new Button("add Points", sf::Vector2f(300, 100), sf::Vector2f(850, 30));
	deletePoints = new Button("delete Points", sf::Vector2f(300, 100), sf::Vector2f(850, 230));
	SaveRoute = new Button("Save Points", sf::Vector2f(300, 100), sf::Vector2f(850, 430));
	palette = new Palette("color_palette.png", sf::Vector2f(300.f, 300.f), sf::Vector2f(850.f, 568.f));
	exitRouteMenu = new Button("Exit", sf::Vector2f(300.f, 100), sf::Vector2f(850, 890));
	if (createRoute->getStatus()) {
		window->clear(sf::Color::White);
		window->draw(map);
		addPoints->displayButton(*window);
		deletePoints->displayButton(*window);
		SaveRoute->displayButton(*window);
		window->draw(palette->displayButton());
		exitRouteMenu->displayButton(*window);
		currentRoute->drawPoints(window);
	}
	delete addPoints;
	delete deletePoints;
	delete SaveRoute;
	delete palette;
	delete exitRouteMenu;



}

void Menu::eventScenarios() {
	switch (evnt.type) {
	case sf::Event::Closed:
		window->close();
		break;
	case sf::Event::MouseButtonReleased:
		if (evnt.key.code == sf::Mouse::Left) {
			sf::Vector2f mousePosition;
			mousePosition.x = sf::Mouse::getPosition(*window).x;
			mousePosition.y = sf::Mouse::getPosition(*window).y;
			std::cout << "( " << mousePosition.x << ", " << mousePosition.y << ")\n";
			pressAddButton(mousePosition);
			pressLoadButton(mousePosition);
			pressDeleteRouteButton(mousePosition);
			pressExitButton(mousePosition);
			if (createRoute->getStatus() == true) {
				checkMouseRouteMenu(mousePosition);
			}
			if (currentEvent == 1 && mousePosition.x < 760.f) {
				std::cout << "llegue a aqui" << std::endl;
				currentRoute->addPoint(mousePosition, currentColor);
			}
			if (currentEvent == 2 && mousePosition.x < 760.f) {
				std::cout << "empieza comprobacion" << std::endl;
				currentRoute->checkClick(mousePosition);
			}


		}
		break;
	case sf::Event::KeyReleased:
		if (evnt.key.code == sf::Keyboard::C) {
			std::cout << server->serialize();
		}
	}
}

void Menu::pressAddButton(sf::Vector2f mousePosition) {
	if (((mousePosition.x >= 860.f) && (mousePosition.x <= 1145.f)) && ((mousePosition.y >= 100.f) && (mousePosition.y <= 195.f)) && !createRoute->getStatus()) {
		createRoute->setStatus(true);
		loadRoutes->setStatus(false);
		currentRoute = new Route();
		std::cout << "Route Menu" << std::endl;
	}
}

void Menu::pressLoadButton(sf::Vector2f mousePosition) {
	if (((mousePosition.x >= 850.f) && (mousePosition.x <= 1145.f)) && ((mousePosition.y >= 300.f) && (mousePosition.y <= 400.f)) && !createRoute->getStatus()) {
		createRoute->setStatus(false);
		displayRouteNames();
		std::cout << "loading route\n";
	}
}

void Menu::pressExitButton(sf::Vector2f mousePosition) {
	if (((mousePosition.x >= 850.f) && (mousePosition.x <= 1145.f)) && ((mousePosition.y >= 500.f) && (mousePosition.y <= 600.f)) && !createRoute->getStatus()) {
		std::cout << "Closing program. \n";
		window->close();
	}
}


void Menu::checkMouseRouteMenu(sf::Vector2f mousePosition) {
	if (mousePosition.x >= ((mousePosition.x >= 850) && (mousePosition.x <= 1150)) && ((mousePosition.y >= 25) && (mousePosition.y <= 125))) {
		currentEvent = 1;
		std::cout << "Add Points" << std::endl << currentEvent << std::endl;
	}
	if (((mousePosition.x >= 850) && (mousePosition.x <= 1150)) && ((mousePosition.y >= 230) && (mousePosition.y <= 330))) {
		currentEvent = 2;
		std::cout << "Delete Points" << std::endl << currentEvent << std::endl;
	}
	if (((mousePosition.x >= 850) && (mousePosition.x <= 1150)) && ((mousePosition.y >= 430) && (mousePosition.y <= 530))) {
		std::cout << "saving Route" << std::endl;
		currentEvent = 0;
		if (currentRoute->getName() == "") {
			std::string routeName = displayNewWindow();
			while (routeName == "" || server->IsTheRouteOnTheList(routeName))
			{
				routeName = displayNewWindow();
			}
			currentRoute->setName(routeName);
			server->addRoute(currentRoute);
			currentRoute = nullptr;
			std::cout << "ruta guardada" << std::endl;
			server->saveRoutes();
		}
		else {
			currentRoute = nullptr;
		}
			createRoute->setStatus(false);
	}
	if (((mousePosition.x >= 850) && (mousePosition.x <= 1150)) && ((mousePosition.y >= 890) && (mousePosition.y <= 985))) {
		createRoute->setStatus(false);
		std::cout << "closing route menu" << std::endl;
		currentEvent = 0;
	}
	checkColorsClicks(mousePosition);
}

void Menu::checkColorsClicks(sf::Vector2f mousePosition) {
	if (((mousePosition.x >= 850) && (mousePosition.x < 950)) && ((mousePosition.y >= 540) && (mousePosition.y <= 715))) {
		std::cout << "Orange" << std::endl;
		currentColor[0] = 240;
		currentColor[1] = 150;
		currentColor[2] = 130;
		for (int i = 0; i < 3; i++) {
			std::cout << currentColor[i] << " , ";
		}
		std::cout << std::endl;
	}
	if (((mousePosition.x >= 951) && (mousePosition.x <= 1050)) && ((mousePosition.y >= 540) && (mousePosition.y <= 715))) {
		std::cout << "Pink" << std::endl;
		currentColor[0] = 238;
		currentColor[1] = 163;
		currentColor[2] = 225;

		for (int i = 0; i < 3; i++) {
			std::cout << currentColor[i] << " , ";
		}
		std::cout << std::endl;
	}
	if (((mousePosition.x >= 1051) && (mousePosition.x <= 1150)) && ((mousePosition.y >= 540) && (mousePosition.y <= 715))) {
		std::cout << "Cyan" << std::endl;
		currentColor[0] = 105;
		currentColor[1] = 194;
		currentColor[2] = 193;
		for (int i = 0; i < 3; i++) {
			std::cout << currentColor[i] << " , ";
		}
		std::cout << std::endl;
	}
	if (((mousePosition.x >= 850) && (mousePosition.x <= 950)) && ((mousePosition.y >= 721) && (mousePosition.y <= 868))) {
		std::cout << "Blue" << std::endl;
		currentColor[0] = 22;
		currentColor[1] = 24;
		currentColor[2] = 152;
		for (int i = 0; i < 3; i++) {
			std::cout << currentColor[i] << " , ";
		}
		std::cout << std::endl;
	}
	if (((mousePosition.x >= 951) && (mousePosition.x <= 1050)) && ((mousePosition.y >= 721) && (mousePosition.y <= 868))) {
		std::cout << "Yellow" << std::endl;
		currentColor[0] = 244;
		currentColor[1] = 245;
		currentColor[2] = 154;
		for (int i = 0; i < 3; i++) {
			std::cout << currentColor[i] << " , ";
		}
		std::cout << std::endl;
	}
	if (((mousePosition.x >= 1051) && (mousePosition.x <= 1150)) && ((mousePosition.y >= 721) && (mousePosition.y <= 868))) {
		std::cout << "Black" << std::endl;
		currentColor[0] = 0;
		currentColor[1] = 0;
		currentColor[2] = 0;
		for (int i = 0; i < 3; i++) {
			std::cout << currentColor[i] << " , ";
		}
		std::cout << std::endl;
	}
}

std::string Menu::displayNewWindow() {
	sf::RenderWindow* newWindow = new sf::RenderWindow(sf::VideoMode(700, 400), "Type Route Name", sf::Style::Close);
	sf::RectangleShape* box = new sf::RectangleShape(sf::Vector2f(400, 50));
	box->setFillColor(sf::Color(91,91,91));
	box->setPosition(sf::Vector2f(130, 50));
	box->setOutlineThickness(4);
	box->setOutlineColor(sf::Color::Black);
	sf::RectangleShape* sqr = new sf::RectangleShape(sf::Vector2f(600, 50));
	sqr->setFillColor(sf::Color(91, 91, 91));
	sqr->setPosition(sf::Vector2f(50, 200));
	sqr->setOutlineThickness(4);
	sqr->setOutlineColor(sf::Color::Black);
	newWindow->setFramerateLimit(20);
	newWindow->setPosition(sf::Vector2i(500, 400));
	sf::Font font;
	font.loadFromFile("font.ttf");
	sf::Text topWindow("Type the route Name", font);
	sf::Text text("", font);
	text.setPosition(100, 200);
	text.setFillColor(sf::Color::White);
	topWindow.setFillColor(sf::Color::White);
	topWindow.setPosition(200, 50);
	sf::Event newEvent;
	std::string input;

	while (newWindow->isOpen()) {
		while (newWindow->pollEvent(newEvent)) {
			if (newEvent.type == sf::Event::KeyPressed) {
				if (newEvent.key.code == sf::Keyboard::Enter) {
					newWindow->close();
				}
			}
			if (newEvent.type == sf::Event::TextEntered) {
				if (newEvent.text.unicode == '\b' && !input.empty()) {
					input.pop_back();
				}
				else if (newEvent.text.unicode < 128 && newEvent.text.unicode != '\b') {
					input += static_cast<char>(newEvent.text.unicode);
				}
				text.setString(input);
			}
			if (newEvent.type == sf::Event::Closed) {
				newWindow->close();
			}
		}

		newWindow->clear(sf::Color::White);
		newWindow->draw(*box);
		newWindow->draw(*sqr);
		newWindow->draw(topWindow);
		newWindow->draw(text);
		newWindow->display();
	}


	return input;
}

void Menu::displayRouteNames() {
	if (server->getHeader() != nullptr) {
		sf::Font font;
		font.loadFromFile("font.ttf");
		sf::Text Names(server->getRouteNames(), font);
		Names.setFillColor(sf::Color::Black);
		Names.setPosition(sf::Vector2f(850, 100));
		std::string RouteName = "";
		window->clear(sf::Color::White);
		window->draw(map);
		window->draw(Names);
		window->display();

		RouteName = displayNewWindow();
		while (!server->IsTheRouteOnTheList(RouteName) || RouteName == "") {
			RouteName = displayNewWindow();
		}

		currentRoute = server->getSpecificRoute(RouteName);
		createRoute->setStatus(true);
		loadRoutes->setStatus(false);
		return;
	}
	std::cerr << "The list Is Empty" << std::endl;
}

void Menu:: initializeDeleteRouteButton() {
	deleteRoute = new Button("delete Route", sf::Vector2f(300, 100), sf::Vector2f(850, 700));
}

void Menu::pressDeleteRouteButton(sf::Vector2f mousePosition) {
	if (((mousePosition.x >= 850.f) && (mousePosition.x <= 1145.f)) && ((mousePosition.y >= 700.f) && (mousePosition.y <= 800.f)) && !createRoute->getStatus()) {
		createRoute->setStatus(false);
		displayRouteNamesToDelete();
		std::cout << "deleting Route\n";
	}
}

void Menu::displayRouteNamesToDelete() {
	if (server->getHeader() != nullptr) {
		sf::Font font;
		font.loadFromFile("font.ttf");
		sf::Text Names(server->getRouteNames(), font);
		Names.setFillColor(sf::Color::Black);
		Names.setPosition(sf::Vector2f(850, 100));
		std::string RouteName = "";
		window->clear(sf::Color::White);
		window->draw(map);
		window->draw(Names);
		window->display();

		RouteName = displayNewWindow();
		while (!server->IsTheRouteOnTheList(RouteName) || RouteName == "") {
			RouteName = displayNewWindow();
		}
		server->deleteRoute(RouteName);
		server->saveRoutes();
		std::cout << "cai despues de guardar";
	}
	std::cerr << "The list Is Empty" << std::endl;
}
