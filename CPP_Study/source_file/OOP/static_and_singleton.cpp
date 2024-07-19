#include <iostream>

// static
// Ư�� ��ü�� ���������� �ʵ��� ����� ��

// singleton
// �ڷᱸ�� & �˰���
// ������ ���� 
// - �̱���, ������, ������Ʈ, ... 

// ���� �� 1���� �����ϰ� ��𼭵� ����� �� �ִ� [�Ŵ���] Ŭ����

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
	// Ư�� ���� ��ü�� ����
	int hp = 40;
	
	// static => Ư�� ���� ��ü�� ����
	//int attack = 6;
	// �̷��� ����, ���� �ٸ� attack�� ������ Marine�� 1000���� ������� ��
	// ���ʿ��� �۾��� 1000�� �ϴ� ��(��û�� �޸� ����)
	// => static ���
	static int attack;	// �̸��� ������ ��. ���� ���� �� ��.
	// ���⼭ �ʱ�ȭ �ϸ� �� ��
};                                                                        

int Marine::attack = 6;		// ��ü �ϳ��ϳ��� �������� �����Ͱ� �ƴ�

///////////////////////////////////////////////////////////////////////

// e.g) static �̿��ؼ� �÷��̾� ���̵� �����ϱ�
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
	// �̱���
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