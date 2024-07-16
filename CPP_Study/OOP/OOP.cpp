#include <iostream>
#include "Player.h"

// 객체지향 (Object Oriented Programming)
// 데이터 + 로직

// 절차지향과의 차이점

// 객체? 플레이어, 몬스터, GameRoom, Lobby

// 설계도


int main()
{
	// 객체 (Instance)
	Player k1;

	k1._hp = 100;
	k1._attack = 10;

	k1.Attack();
	k1.Die();
}