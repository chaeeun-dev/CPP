#include <iostream>
using namespace std;
#include "Knight.h"

// [Bug Report #6]
// 반격 시스템이 도입되어,
// 기사는 자신을 공격한 대상을 똑같이 공격합니다.
// 기사 2을 생성해서 위 사양을 테스트하는데...
// 바로 크래시가 나고 있습니다.
// 또 뭐가 문제인지 원인을 찾아주세요!

// 내가 해결한 방법
// 재귀 함수 때문에 액세스 위반이 발생하는 것 같아 반격 함수를 따로 작성했다.
// 해결은 됐는데 재귀함수를 썼을 때 왜 엑세스 위반이 일어나는지 모르겠다.
// 똑같이 포인터를 쓰는건데..?

// 답안
// 호출 스택을 확인하면 OnDamage() 함수가 계속 호출 됐음을 알 수 있음
// 함수를 계속 실행하다보니 스택 메모리가 고갈되어 Stack Overflow 문제가 발생함
// 재귀함수를 계속 호출하는 것이 문제!
// 해결 방법 - OnDamage() 함수 안에 if (IsDead) return; 조건문을 넣어 해결함

int main()
{ 
	Knight* k1 = new Knight();
	k1->_hp = 100;
	k1->_maxHp = 100;
	k1->_attack = 100;

	Knight* k2 = new Knight();
	k2->_hp = 100;
	k2->_maxHp = 100;
	k2->_attack = 100;

	k1->OnDamaged(k2);

	delete k1;
	delete k2;
}
