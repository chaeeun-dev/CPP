#include <iostream>

// static
// 특정 객체에 종속적이지 않도록 만드는 것

// singleton
// 자료구조 & 알고리즘
// 디자인 패턴 
// - 싱글톤, 옵저버, 콤포넌트, ... 

// 정말 딱 1개만 존재하고 어디서든 사용할 수 있는 [매니저] 클래스

class UserManager
{
public:
	static UserManager* GetInstance()
	{
		static UserManager um;
		return &um;
	}
public:
	void AddUser() { _userCount++; }
	int GetUserCount() { return _userCount; }
private:
	int _userCount = 0;
};

class Marine
{
public:
	void TakeDamage(int damage)
	{
		hp -= damage;
	}

public:
	// 특정 마린 객체와 연관
	int hp = 40;
	
	// static => 특정 마린 객체와 무관
	//int attack = 6;
	// 이렇게 쓰면, 각자 다른 attack을 가지는 Marine을 1000마리 만들었을 때
	// 불필요한 작업을 1000번 하는 것(엄청난 메모리 낭비)
	// => static 사용
	static int attack;	// 이름만 빌리는 것. 공간 차지 안 함.
	// 여기서 초기화 하면 안 됨
};                                                                        

int Marine::attack = 6;		// 객체 하나하나에 종속적인 데이터가 아님

///////////////////////////////////////////////////////////////////////

// e.g) static 이용해서 플레이어 아이디 생성하기
class Player
{
public:
	Player()
	{
		id = s_idGeneraotr++;
	}

public:
	int id;
	static int s_idGeneraotr;
};

int Player::s_idGeneraotr = 1;

int main()
{
	// 싱글톤
	for (int i = 0; i < 10; ++i)
		UserManager::GetInstance()->AddUser();
////////////////////////////////////////////////////////////////
	Marine m1;
	m1.hp = 40;

	Marine m2;
	m2.hp = 10;

/////////////////////////////////////////////////////////////////
	Player p1;
	Player p2;
	Player p3;
}