#pragma once
#include <iostream>

class Player
{
public:
	// ��� �Լ�
	void Attack();		// ���� �κ� ����Ű - ctrl + . + enter
	void Die();
	void HealMe(int Value);
public:
	// ��� ���� (�������� _ or _m ��...)
	int _hp;
	int _attack;
	int _defence;
};

