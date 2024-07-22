#include <iostream>

// ��ü���� (Object Oriented Programming)
// ������ + ����

// ����������� ������

// ��ü? �÷��̾�, ����, GameRoom, Lobby

// ���赵
class Knight
{
public:
	// �⺻ ������ (constructor)
	//Knight()	// �ʱⰪ ���� �߿�
	//{
	//	_hp = 0;
	//	_attack = 0;
	//	_defence = 0;

	//	std::cout << "Knight()" << std::endl;
	//}
	
	// ���� ������ 
	Knight(const Knight& other)
	{
		this->_hp = other._hp;
		this->_attack = other._attack;
		this->_defence = other._defence;
		std::cout << "Knight(const Knight& other)" << std::endl;
	}

	// ��Ÿ ������ - ���� ���� �� ä������ ��
	Knight(int hp, int attack, int defence)
	{
		this->_hp = hp;
		this->_attack = attack;
		this->_defence = defence;
		std::cout << "Knight()" << std::endl;
	}
	// �Ҹ���
	~Knight()
	{
		std::cout << "~knight()" << std::endl;
	}
	// ��� �Լ�
	void Attack() { std::cout << "ATTACK" << std::endl; }
	void Die() { std::cout << "DIE" << std::endl; }
	void HealMe(int Value) {
		_hp += 10;
	}

public:
	// ��� ����
	int _hp;
	int _attack;
	int _defence;
};


int main()
{
	// ��ü (Instance)
	Knight k1(100, 10, 1);

	Knight k2(k1);		// ���� ������
	std::cout << k1._hp << std::endl;
}