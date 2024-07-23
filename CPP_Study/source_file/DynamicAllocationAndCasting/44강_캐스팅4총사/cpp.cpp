#include <iostream>
#include "save.h"

// 캐스팅 4총사(앞 두개가 핵심이지만, 면접에 자주 나옴)
// static_cast << 
// dynamic_cast <<
// const_cast
// reinterpret_cast

// C 스타일 캐스팅
// 동일한 문법인데도 어디서 사용하냐에 따라 완전히 달라지기 때문에 위험!

class Player
{

};

class Knight : public Player
{

};

int main()
{
	// static_cast : 타입 원칙에 비춰볼 때 상식적인 캐스팅만 허용해준다
	// 1) int <-> float
	// 2) Player* -> Knight

	int hp = 100;
	int maxHp = 200;
	//float ratio = hp / maxHp;	// 결과는 0, 오른쪽 / 연산부터 처리하기 때문에
	float ratio = (float)hp / maxHp;	// 이렇게 하면 0.5

	Knight* k = new Knight();
	Player* p = k;

	Knight* k2 = p;

	save("cpp.cpp");
}
