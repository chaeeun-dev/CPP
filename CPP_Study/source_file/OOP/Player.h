#pragma once
#include <iostream>

class Player
{
public:
	// 멤버 함수
	void Attack();		// 정의 부분 단축키 - ctrl + . + enter
	void Die();
	void HealMe(int Value);
public:
	// 멤버 변수 (컨벤션은 _ or _m 등...)
	int _hp;
	int _attack;
	int _defence;
};

