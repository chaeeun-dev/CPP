#include <iostream>
#include "save.h"

// ĳ���� 4�ѻ�(�� �ΰ��� �ٽ�������, ������ ���� ����)
// static_cast << 
// dynamic_cast <<
// const_cast
// reinterpret_cast

// C ��Ÿ�� ĳ����
// ������ �����ε��� ��� ����ϳĿ� ���� ������ �޶����� ������ ����!

class Player
{

};

class Knight : public Player
{

};

int main()
{
	// static_cast : Ÿ�� ��Ģ�� ���纼 �� ������� ĳ���ø� ������ش�
	// 1) int <-> float
	// 2) Player* -> Knight

	int hp = 100;
	int maxHp = 200;
	//float ratio = hp / maxHp;	// ����� 0, ������ / ������� ó���ϱ� ������
	float ratio = (float)hp / maxHp;	// �̷��� �ϸ� 0.5

	Knight* k = new Knight();
	Player* p = k;

	Knight* k2 = p;

	save("cpp.cpp");
}
