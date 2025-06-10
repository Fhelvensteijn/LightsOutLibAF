#pragma once
#include <vector>

class LightsOut {
public:
	std::vector<std::vector<int>> board;
	int width;
	int height;
	int modulo;

	LightsOut(int x, int y, int mod = 2);

	bool boundsCheck(int x, int y);

	void flipLightHelper(int x, int y);

	void flipLight(int x, int y);

	bool checkWin(int target = NULL);

	void boardSolver(int target = 0);
};