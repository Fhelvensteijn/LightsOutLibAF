#include <iostream>
#include <cstdlib>
#include "LightsOutLibAF.cpp"

using namespace std;

//Made by Ferdi Helvensteijn for the personal project: 4x4 handheld w/ Yves Kersten

//This is a software implementation of the game LightsOut using the provided LightsOut library
//It is a bit rough around the edges as it only serves as a proof of concept for the 4x4 handheld implementation

int main() {
	int width;
	int height;
	int mod;
	int selWidth;
	int selHeight;

	cout << "\nchoose board width: ";
	cin >> width;
	cout << "\nchoose board height: ";
	cin >> height;

	cout << "\nchoose light state amount: ";
	cin >> mod;

	LightsOut game = LightsOut(width, height, mod);
	while (!game.checkWin()) {
		cout << "\n";
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				cout << game.board[i][j];
			}
			cout << "\n";
		}

		cout << "\n";

		cout << "choose row: ";
		cin >> selWidth;
		cout << "\nchoose column: ";
		cin >> selHeight;

		game.flipLight(selWidth, selHeight);
	}
	cout << "\nyou win!!\n";
	return 0;
}
