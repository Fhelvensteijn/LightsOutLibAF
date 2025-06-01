#include <vector>
#include <time.h>

using namespace std;

//Made by Ferdi Helvensteijn for the personal project: 4x4 handheld w/ Yves Kersten

//This class and its methods can be used to create an implementation of the puzzle game LightsOut
//For an example of how to implement check out the in console implementation created in main.cpp

class LightsOut {
	public:
		vector<vector<int>> board;
		int width;
		int height;
		int modulo;

	LightsOut(int x, int y, int mod = 2) {
		//create initialization variables and set random seed
		vector<vector<int>> init(x, vector<int>(y));
		srand(time(NULL));

		//fill board with random numbers according to the modulo
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				init[i][j] = rand() % mod;
			}
		}

		//fill class values with set variables
		board = init;
		width = x;
		height = y;
		modulo = mod;
	}

	public: 
		void flipLightHelper(int x, int y) {
			//check if value to change is in bounds
			if (x < 0 || y < 0 || x >= this->width || y >= this->height) {
				return;
			}

			//change the state of light to the next one
			this->board[x][y] = (this->board[x][y] + 1) % modulo;
		}

		void flipLight(int x, int y) {
			//check if value is within bounds
			if (x < 0 || y < 0 || x > this->width || y > this->height) {
				return;
			}

			//shift position from real to array
			x--;
			y--;

			//Use helper function to flip lights
			flipLightHelper(x, y);
			flipLightHelper(x+1, y);
			flipLightHelper(x-1, y);
			flipLightHelper(x, y+1);
			flipLightHelper(x, y-1);
		}

		bool checkWin(int target = NULL) {
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

		void boardSolver(int target = 0) {
			//Turn all lights out or set them to TARGET state, used for testing
			for (int i = 0; i < width; i++) {
				for (int j = 0; j < height; j++) {
					this->board[i][j] = target;
				}
			}
		}
};
