#include <iostream>
using namespace std;
#include "Knight.h"

// [Bug Report #5]
// 최대 체력(MaxHP)의 개념이 추가되었습니다.
// 아울러 짜릿한 역전의 희망을 주기 위해
// 체력이 50% 이하로 떨어지면 공격 데미지를 2배로 적용합니다.
// 테스트를 위해 기사 두마리를 생성하고 한대씩 데미지를 주고 받습니다.
// 그런데 또 프로그램이 크래시나는 문제가 발생하고 있습니다.
// 원인을 파악하고 의도대로 동작하게 수정해주세요!

// 내가 해결한 방법
// int ratio =_maxHp / _hp; 코드에서 _maxHp와 _hp 모두 int 값이기 때문에
// 몫이 제대로 나오지 않게 되므로, int 값을 double로 변환하도록 코드를 수정헸다.
// int ratio =_maxHp / (double)_hp;

// 답안
// int percentage 변수를 사용
// int percentage = _hp / (float)_maxHp * 100;
// percentage가 50보다 작거나 같으면 damage 2배로 설정
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

	int damage = k1->GetAttackDamage();
	k2->AddHp(-damage);

	int damage2 = k2->GetAttackDamage();
	k1->AddHp(-damage2);
	
	delete k1;
	delete k2;
}
