#include <iostream>
#include <iomanip>

const int MAX = 100;
int board[MAX][MAX];
int N;

int x = 0;
int y = 0;

int count = 1;

enum DIR
{
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3,
};

DIR playerdir = RIGHT;

void PrintBoard()
{
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			std::cout << std::setfill('0') << std::setw(2) << board[y][x] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

void DirSet()
{
	switch (playerdir)
	{
	case RIGHT:
		if (y + 1 < N && board[x][y+1]==0)
			playerdir = RIGHT;
		else if (y + 1 == N or board[x][y+1]!=0)
			playerdir = DOWN;
		break;
	case DOWN:
		if (x + 1 < N && board[x+1][y] == 0)
			playerdir = DOWN;
		else if (x + 1 == N or board[x+1][y]!=0)
			playerdir = LEFT;
		break;
	case LEFT:
		if (y - 1 > -1 && board[x][y - 1] == 0)
			playerdir = LEFT;
		else if (y - 1 == -1 or board[x][y-1]!=0)
			playerdir = UP;
		break;
	case UP:
		if (x - 1 > -1 && board[x-1][y] == 0)
			playerdir = UP;
		else if (x - 1 == -1 or board[x-1][y]!=0)
			playerdir = RIGHT;
		break;
	}
}

void MovePlayer()
{
	switch (playerdir)
	{
	case RIGHT:
		y++;
		board[x][y] = count;
		count++;
		break;
	case DOWN:
		x++;
		board[x][y] = count;
		count++;
		break;
	case LEFT:
		y--;
		board[x][y] = count;
		count++;
		break;
	case UP:
		x--;
		board[x][y] = count;
		count++;
		break;
	}
}

void Snail()
{
	board[x][y] = count;
	count++;

	while (1) {
		// �迭�� �� ä�������� Ȯ��
			{
				int center_x, center_y;

				// N�� Ȧ���� ��
				if (N % 2 != 0) {
					center_x = N / 2;
					center_y = N / 2;
				}
				// N�� ¦���� ��
				else {
					center_x = N / 2;
					center_y = N / 2 - 1;
				}
		
				if (board[center_x][center_y] != 0) {
					std::cout << "�����̰� �����..." << std::endl;
					return;
				}
					
			}

			// �÷��̾��� ���� ���� 
			DirSet();

			// �÷��̾� �̵��ϰ� ���� �����
			MovePlayer();
	}
	

}

int main()
{
	std::cout << "���ڸ� �Է��ϼ��� : ";
	std::cin >> N;

	std::cout << "=========������ �ʱ� ����=========" << std::endl;
	PrintBoard();
	
	Snail();
	std::cout << "=========������.......=========" << std::endl;
	PrintBoard();
}