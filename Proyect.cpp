#include <iostream>
#include"Menu.h"

int main() {
	Menu* mainMenu = new Menu();
	mainMenu->~Menu();
	return 0;
}