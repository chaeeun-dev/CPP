#include <iostream>

// ���� ���� ���� �������� �� �����غ���!
// ����� ���߿� �ͼ������� �ȴ�
// OOP�� ����ϴ� ������ �����ϴ� ���� ���� �߿�!

// class�� ���赵
class Object	// * ��Ӽ� - ���� Ŭ������ ����� ���
{
	//virtual void Shout() = 0;	// ���� ���� �Լ� - ���������� ����� �� ����
	void Move() {  }
};

class IFly	// �������̽� �����ϴ� ����
{
	virtual void Fly() = 0;
	virtual void Land() = 0;	
	// ��� ���� class���� ������ �� �ϵ���(���� �� �ϸ� ������)
};

class Player : public Object, public IFly	// Player�� IFly �������̽��� ����
{
public:
	Player() {	}
	~Player() {  }

	virtual void Fly() override {};
	virtual void Land() override {};

	virtual void Shout() {  }	
	// * ������ - virtual, ��Ÿ�ӿ� � �Լ� �����Ұ��� ������(���� ���ε� ����)
	
	void SetHp(int hp) { this->hp = hp; }
	void Move() {  }

private:	// * ���м�(ĸ��ȭ) - ���ܾ� �ϴ� �����͸� ����
	int hp = 10;
};

void AddObject(Player* player)
{
	player->Shout();
}

void FlyTest(IFly* fly)
{

}

int main()
{
	Player p;
	FlyTest(&p);
}