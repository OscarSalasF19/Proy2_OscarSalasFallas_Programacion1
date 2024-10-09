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
	displayColorPalette();

}

Menu::~Menu() {

}

void Menu::displayWindow() {
	while (window->isOpen()) {
		while (window->pollEvent(evnt)) {
			EventConditions();
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

void Menu::initializeColorPalette() {
	palette = new sf::RectangleShape(sf::Vector2f(300, 300));
	sf::Texture* paletteTexture = new sf::Texture;
	paletteTexture->loadFromFile("color_palette.png");
	palette->setTexture(paletteTexture);
	palette->setPosition(sf::Vector2f(830.f, 668.f));
}

void Menu::displayColorPalette() {
	while (isTheAddActive && !isTheDeleteActive) {
		window->clear(sf::Color::White);
		window->draw(map);
		window->draw(addPointButton);
		window->draw(deletePointButton);
		window->draw(loadRouteButton);
		window->draw(*palette);
		window->display();
	}
}

void Menu::pressAddButton(sf::Vector2i mousePosition) {
	if (((mousePosition.x >= 860) && (mousePosition.x <= 1145)) && ((mousePosition.y >= 100) && (mousePosition.y <= 195))) {
		isTheAddActive = true;
		isTheDeleteActive = false;
		std::cout << "adding button\n";
	}
}

void Menu::pressDeleteButton(sf::Vector2i mousePosition) {
	if (((mousePosition.x >= 850) && (mousePosition.x <= 1145)) && ((mousePosition.y >= 300) && (mousePosition.y <= 400))) {
		isTheAddActive = false;
		isTheDeleteActive = true;
		std::cout << "deleting button\n";
	}
}

void Menu::pressLoadButton(sf::Vector2i mousePosition) {
	if (((mousePosition.x >= 850) && (mousePosition.x <= 1145)) && ((mousePosition.y >= 500) && (mousePosition.y <= 600))) {
		std::cout << "loading Route\n";
	}
}

void Menu::EventConditions() {
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

			std::cout << "( " << mousePosition.x << ", " << mousePosition.y << ")\n";
		}
	}
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