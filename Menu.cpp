#include"Menu.h"
Menu::Menu() {
	isTheAddActive = false;
	isTheDeleteActive = false;
	initializeWindow();
	intializeMap();
	intializeAddButton();
	intializeDeleteButton();
	intializeLoadButton();
	displayWindow();

}

Menu::~Menu() {

}

void Menu::displayWindow() {
	while (window->isOpen()) {
		while (window->pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
					std::cout << "( " << mousePosition.x << ", " << mousePosition.y << ")\n";
				}
			}
		}
		displayMenu();

	}
}

void Menu::loadTexture() {
	mapTexture.loadFromFile("Map_Of_Proy.jpeg");
	map.setTexture(&mapTexture);
	map.setScale(1.0f, 0.79f);
}

void Menu::initializeWindow() {
	window = new sf::RenderWindow(sf::VideoMode(1200, 1000), "Route designer", sf::Style::Titlebar | sf::Style::Close);
}

void Menu::intializeMap() {
	map = sf::RectangleShape(sf::Vector2f(800.0f, 1280.0f));
	loadTexture();
}

void Menu::intializeAddButton() {
	addPointButton = sf::RectangleShape(sf::Vector2f(300, 100));
	addPointButton.setPosition(sf::Vector2f(850, 100));
	addingPointsTexture.loadFromFile("add_points.png");
	addPointButton.setTexture(&addingPointsTexture);
}

void Menu::intializeDeleteButton() {
	deletePointButton = sf::RectangleShape(sf::Vector2f(300, 100));
	deletePointButton.setPosition(sf::Vector2f(850, 300));
	deletingPointsTexture.loadFromFile("Delete_Button.png");
	deletePointButton.setTexture(&deletingPointsTexture);
}

void Menu::intializeLoadButton() {
	loadRouteButton = sf::RectangleShape(sf::Vector2f(300, 100));
	loadRouteButton.setPosition(sf::Vector2f(850, 500));
	loadingPointsTexture.loadFromFile("Load_button.png");
	loadRouteButton.setTexture(&loadingPointsTexture);

}

void Menu::displayMenu() {
	if (!isTheAddActive && !isTheDeleteActive) {
		window->clear(sf::Color::White);
		window->draw(map);
		window->draw(addPointButton);
		window->draw(deletePointButton);
		window->draw(loadRouteButton);
		window->display();
	}
}