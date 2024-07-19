#include <iostream>

// ��ü���� (Object Oriented Programming)
// ������ + ����

class Player
{
public:
	Player()
	{
		std::cout << "Player()" << std::endl;
	}

	~Player()
	{
		std::cout << "~Player()" << std::endl;
	}
};

class Inventory
{
public:
	Inventory()
	{
		std::cout << "Inventory()" << std::endl;
	}
	
	Inventory(int a)
	{
		_a = a;
		std::cout << "Inventory(int)" << std::endl;
	}
	~Inventory()
	{
		std::cout << "~Inventory()" << std::endl;
	}
public:
	int _a;
};

class Knight : public Player
{
public:
	Knight() : _hp(0), _inventory(100)	// �����ٰ� �ʱ�ȭ�ϱ�
	/*
		��ó�� ����
		Player()
		_inventory = Inventory
	*/
	{
		// ���� �ʱ�ȭ ���� �ʰ� ���⼭ �ʱ�ȭ�ϸ� ���ʿ��� ������ ���� �� ����(����θ�..)
		//_hp = 0;
		//_inventory = Inventory(100);
		std::cout << "Knight()" << std::endl;
	}  

	~Knight()
	{
		std::cout << "~Knight()" << std::endl;
	}
public: 
	int _hp;
	Inventory _inventory;
};

int main()
{
	Knight k1;
	//	Player()
	//	Knight()
	//	~Knight()
	//	~Player()

	//	Player()
	//	Inventory()
	//	Knight()
	//	~Knight()
	//	~Inventory()
	//	~Player()

	//	Player()
	//	Inventory()
	//	Inventory(int)
	//	~Inventory()
	//	Knight()
	//	~Knight()
	//	~Inventory()
	//	~Player()


}