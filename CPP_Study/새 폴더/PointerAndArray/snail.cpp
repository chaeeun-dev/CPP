#include <iostream>
#include <iomanip>	// 출력 정렬하기

const int MAX = 100;
int board[MAX][MAX];
int N;

int count = 1;

int x_pos = 0;
int y_pos = 0;

enum DIR
{
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3,
};


void PrintBoard()
{
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			std::cout << std::setfill('0') << std::setw(2) << board[y][x] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


int main()
{
	std::cin >> N;

	PrintBoard();
}