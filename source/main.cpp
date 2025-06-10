#include <iostream>
#include <cstdlib>
#include "LightsOutLibAF.h"

//Made by Ferdi Helvensteijn for the personal project: 4x4 handheld w/ Yves Kersten

//This is a software implementation of the game LightsOut using the provided LightsOut library
//It is a bit rough around the edges as it only serves as a proof of concept for the 4x4 handheld implementation

int main() {
	int width;
	int height;
	int mod;
	int selWidth;
	int selHeight;

	std::cout << "\nchoose board width: ";
	std::cin >> width;
	std::cout << "\nchoose board height: ";
	std::cin >> height;

	std::cout << "\nchoose light state amount: ";
	std::cin >> mod;

	LightsOut game = LightsOut(width, height, mod);
	while (!game.checkWin()) {
		std::cout << "\n";
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				std::cout << game.board[i][j];
			}
			std::cout << "\n";
		}

		std::cout << "\n";

		std::cout << "choose row: ";
		std::cin >> selWidth;
		std::cout << "\nchoose column: ";
		std::cin >> selHeight;

		game.flipLight(selWidth, selHeight);
		}
	std::cout << "\nyou win!!\n";
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
