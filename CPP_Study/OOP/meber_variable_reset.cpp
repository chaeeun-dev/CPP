#include <iostream>

// 객체지향 (Object Oriented Programming)
// 데이터 + 로직

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
	Knight() : _hp(0), _inventory(100)	// 위에다가 초기화하기
	/*
		선처리 영역
		Player()
		_inventory = Inventory
	*/
	{
		// 위에 초기화 하지 않고 여기서 초기화하면 불필요한 동작이 있을 수 있음(참고로만..)
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