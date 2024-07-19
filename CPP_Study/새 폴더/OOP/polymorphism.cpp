#include <iostream>

// - ������ << polymorphism (poly + morphism)

// �����ε�(overloading) = �Լ��� �̸� ���� (���� Ÿ���̳� ������ ����)
// �������̵�(overriding)

// ��� ���� �����ϱ�
// Player�� Knight�̴� - X
// Knight�� Player�̴� - O
// ������ ���̴� - X
// ���� �����̴� - O

// virtual�� ���̸� ��� ���� class�� ���� �Լ����� virtual�� �ٰ� ��
// �׷��� ��� ���� class�� �Լ����� �Ĳ��ϰ� virtual ������

// virtual function table
// vftable [�ּ�1|�ּ�2|�ּ�3]
// � Ÿ���� �Լ��� ��������

// �߻� Ŭ���� - ���� ������� �ʰ� ��Ӹ� �ϴ� Ŭ����(Knight, Archer ���� ���)
class Player
{
public:
	//virtual void Move() { std::cout << "Player Move()" << std::endl; }
	
	virtual void Move() = 0;	// ���� ���� �Լ�
	// virtual void Move() abstract;	// ����
public:
	int _hp;
};

class Knight : public Player
{
public:
	virtual void Move() override { std::cout << "Knight Move()" << std::endl; }

public:
	int _stamina;
};

// ���ε�(Binding) = ���´�
// - ���� ���ε� (static binding = ������ ���� ����)
// - ���� ���ε� (dynamic binding = ���� ���� ����)

void MovePlayer(Player* player)
{
	player->Move();
}

int main()
{
	Knight k1;
	
	k1.Move();
	// KnightMove()

	MovePlayer(&k1);	// Knight�� Player�� ��� �޾ұ� ������ �����
	// PlayerMove()
	// virtual void Move()�� ��������� KnightMove()�� ��µ�
}
