#include <iostream>

// 로또 번호 생성기
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// bubble sort
// {1, 42, 3, 15, 5, 6}
// {1, 3, 42, 15, 5, 6}
// {1, 3, 15, 42, 5, 6}
// {1, 3, 15, 5, 42, 6}
// {1, 3, 15, 5, 6, 42}
// ...
// => {1, 3, 5, 6, 15, 42}
void Sort(int* numbers, int count)
{
	for (int i = 0; i < count; ++i) 
	{
		for (int j = 0; j < count - 1; ++j)
		{
			if (numbers[j] > numbers[j + 1])
				Swap(numbers[j], numbers[j + 1]);
		}
	}

	
}

void Print(int* numbers, int count)
{
	for (int i = 0; i < count; ++i) {
		std::cout << numbers[i] << std::endl;
	}
}

void ChooseLotto(int* numbers)
{
	int count = 0;

	while (count != 6)		// 중복된 숫자가 나오지 않도록
	{
		// 1~45
		int randValue = 1 + rand() % 45;

		// 이미 찾은 값인지?
		bool found = false;

		for (int i = 0; i < count; ++i)
		{
			if (numbers[i] == randValue)
			{
				found = true;
				break;
			}
		}

		if (found == false)
		{
			numbers[count] = randValue;
			count++;
		}
	}

	Sort(numbers, 6);
}

int main()
{
	srand((unsigned)time(0));

	int lotto[6];
	ChooseLotto(lotto);

	Print(lotto, 6);
}

