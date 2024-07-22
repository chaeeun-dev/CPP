#include <iostream>

// 객체지향 (Object Oriented Programming)
// 데이터 + 로직

// 절차지향과의 차이점

// 객체? 플레이어, 몬스터, GameRoom, Lobby

// 설계도
class Knight
{
public:
	// 기본 생성자 (constructor)
	//Knight()	// 초기값 설정 중요
	//{
	//	_hp = 0;
	//	_attack = 0;
	//	_defence = 0;

	//	std::cout << "Knight()" << std::endl;
	//}
	
	// 복사 생성자 
	Knight(const Knight& other)
	{
		this->_hp = other._hp;
		this->_attack = other._attack;
		this->_defence = other._defence;
		std::cout << "Knight(const Knight& other)" << std::endl;
	}

	// 기타 생성자 - 변수 값을 다 채워야할 때
	Knight(int hp, int attack, int defence)
	{
		this->_hp = hp;
		this->_attack = attack;
		this->_defence = defence;
		std::cout << "Knight()" << std::endl;
	}
	// 소멸자
	~Knight()
	{
		std::cout << "~knight()" << std::endl;
	}
	// 멤버 함수
	void Attack() { std::cout << "ATTACK" << std::endl; }
	void Die() { std::cout << "DIE" << std::endl; }
	void HealMe(int Value) {
		_hp += 10;
	}

public:
	// 멤버 변수
	int _hp;
	int _attack;
	int _defence;
};


int main()
{
	// 객체 (Instance)
	Knight k1(100, 10, 1);

	Knight k2(k1);		// 복사 생성자
	std::cout << k1._hp << std::endl;
}