#include <iostream>

// ������ �����ε�

// - ��� ������ �Լ� ����
// -- a operation b ���¿��� ������ �������� ����

// - ���� ������ �Լ� ����
// -- a operation b ���¶��, a/b ��θ� ������ �Լ��� �ǿ����ڷ� ���


// ��� - ���� �����ڴ� �� ������� ������ �ʿ��� �� �˻��ؼ� 
// ������ �ʹ� ��� ���� �ʴ� �ɷ�!
// �����ڸ� ���� ���� ����Ѵٴ� �� �����ϴ� �� �߿���
class Pos
{
public:
	Pos()
	{

	}

	// explict ���� ���� ������ ����!

	Pos(int b)
	{
		x = b;
		y = b;
	}

	Pos operator+(const Pos& b)
	{
		Pos pos;
		pos.x = x + b.x;
		pos.y = y + b.y;

		return pos;
	}

	Pos operator+(int b)
	{
		Pos pos;
		pos.x = x + b;
		pos.y = y + b;

		return pos;
	}

	bool operator==(const Pos& b)
	{
		return x == b.x && y == b.x;
	}

	// ���� ������
	void operator=(int b)
	{
		x = b;
		y = b;
	}

	int x;
	int y;
};

Pos operator+(int a, const Pos& b)
{
	Pos pos;
	pos.x = a + b.x;
	pos.y = a + b.y;
	return pos;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = a + b;

	// Pos pos1(10) vs Pos pos1 = 10 <- �̷��� �� �ǵ���
	
	// Pos pos1;
	// pos1 = 10	// ����
	Pos pos1(10);
	Pos pos2(20);


	//Pos pos1;
	//Pos pos2;


	//Pos pos3 = pos1 + pos2;
	// pos3 = pos1.operator+(pos2);

	//Pos pos4 = pos3 + 10;	// int Ÿ��
	//pos4 = 10 + pos3;	
}