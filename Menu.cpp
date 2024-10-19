#include"Menu.h"


Menu::Menu() {
	initializeWindow();
	intializeMap();
	intializeAddButton();
	intializeDeleteButton();
	intializeLoadButton();
	initializeColorPalette();
	initializePoint();
	displayWindow();
}

Menu::~Menu() {

}

void Menu::displayWindow() {
	while (window->isOpen()) {
		while (window->pollEvent(evnt)) {
			eventScenarios();
		}
		window->clear(sf::Color::White);
		window->draw(map);
		window->draw(AddPoints->displayButton());
		window->draw(deletePoints->displayButton());
		window->draw(loadPoints->displayButton());
		if (AddPoints->getStatus() == true) {
			displayColorPalette();
		}
		window->draw(point->getPoint());
		window->display();
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
	AddPoints = new Button("add_points.png", sf::Vector2f(300, 100), sf::Vector2f(850, 100));
}

void Menu::intializeDeleteButton() {
	deletePoints = new Button("Delete_Button.png", sf::Vector2f(300, 100), sf::Vector2f(850, 300));

}
void Menu::intializeLoadButton() {
	loadPoints = new Button("Load_Button.png", sf::Vector2f(300, 100), sf::Vector2f(850, 500));

}

void Menu::initializeColorPalette() {
	Palette = new Button("color_palette.png", sf::Vector2f(300.f, 300.f), sf::Vector2f(830.f, 668.f));
}

void Menu::displayColorPalette() {
	window->draw(Palette->displayButton());
}

void Menu::eventScenarios() {
	switch (evnt.type) {
	case sf::Event::Closed:
		window->close();
		break;
	case sf::Event::MouseButtonPressed:
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
			pressAddButton(mousePosition);
			pressDeleteButton(mousePosition);
			pressLoadButton(mousePosition);
		}
	}
}

void Menu::pressAddButton(sf::Vector2i mousePosition) {
	if (((mousePosition.x >= 860) && (mousePosition.x <= 1145)) && ((mousePosition.y >= 100) && (mousePosition.y <= 195))) {
		AddPoints->setStatus(true);
		deletePoints->setStatus(false);
		std::cout << "add Button" << std::endl;
	}
	std::cout << "( " << mousePosition.x << ", " << mousePosition.y << ")\n";
}

void Menu::pressDeleteButton(sf::Vector2i mousePosition) {
	if (((mousePosition.x >= 850) && (mousePosition.x <= 1145)) && ((mousePosition.y >= 300) && (mousePosition.y <= 400))) {
		AddPoints->setStatus(false);
		deletePoints->setStatus(true);
		std::cout << "deleting button\n";
	}
}

void Menu::pressLoadButton(sf::Vector2i mousePosition) {
	if (((mousePosition.x >= 850) && (mousePosition.x <= 1145)) && ((mousePosition.y >= 500) && (mousePosition.y <= 600))) {
		std::cout << "loading Route\n";
	}
}

void Menu::initializePoint() {
	point = new Point(sf::Vector2f(386.f, 100.f), sf::Color(22, 24, 152));
}
