#include <vector>
#include <time.h>
#include <cstdlib>
#include "LightsOutLibAF.h"

//Made by Ferdi Helvensteijn for the personal project: 4x4 handheld w/ Yves Kersten

//This class and its methods can be used to create an implementation of the puzzle game LightsOut
//For an example of how to implement check out the in console implementation created in main.cpp


LightsOut::LightsOut(int x, int y, int mod) {
	//create initialization variables and set random seed
	std::vector<std::vector<int>> init(x, std::vector<int>(y, 0));
	srand(time(NULL));

	//fill init with info to create a board
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			init[i][j] = rand() % mod;
		}
	}

	//fill class values with set variables
	board = std::vector<std::vector<int>> (x, std::vector<int>(y, 0));
	width = x;
	height = y;
	modulo = mod;

	//use the init to create a board that is solveable, as flipping a light is always reversible
	int count;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			count = init[i][j];
			while (count > 0) {
				flipLight(i, j);
				count--;
			}
		}
	}
}

	 
bool LightsOut::boundsCheck(int x, int y) {
	return (x < 0 || y < 0 || x >= this->width || y >= this->height);
}

void LightsOut::flipLightHelper(int x, int y) {
	//check if value to change is in bounds
	if (boundsCheck(x, y)) {
		return;
	}

	//change the state of light to the next one
	this->board[x][y] = (this->board[x][y] + 1) % modulo;
}

void LightsOut::flipLight(int x, int y) {
	//shift position from real to array
	x--;
	y--;

	//check if value is within bounds
	if (boundsCheck(x, y)) {
		return;
	}

	//Use helper function to flip lights
	flipLightHelper(x, y);
	flipLightHelper(x+1, y);
	flipLightHelper(x-1, y);
	flipLightHelper(x, y+1);
	flipLightHelper(x, y-1);
}

bool LightsOut::checkWin(int target) {
	//Iterate over board to see if all lights are the same state or if they are the TARGET state
	if (target == NULL) {
		target = this->board[0][0];
	}

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (this->board[i][j] != target) {
				return false;
			}
		}
	}

	return true;
}

void LightsOut::boardSolver(int target) {
	//Turn all lights out or set them to TARGET state, used for testing
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			this->board[i][j] = target;
		}
	}
}