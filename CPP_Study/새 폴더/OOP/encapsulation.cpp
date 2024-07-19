#include <iostream>

// OOP 3�� ��� (�������� �� ���� ������ �˰� �־�� ��)
// 1) ��Ӽ� << inheritance
// 2) ���м� << data hiding (ĸ��ȭ encapsulation)
// 3) ������

// �ڵ���
// - �ڵ�/���/����/��/���⼱/�ֹ���
// ������ ���忡�� ��� : �ڵ�/���/��
// ���� ��(����� ��!) : ����, ���⼱, �ֹ���


// ���� ������
// public(������?) vs protected(��ȣ �޴�?) vs private(������?)

class Car
{
public:
	void MoveHandle() { }
	void PushPedal() { }
	void OpenDoor() { }
	void TurnKey()
	{
		// ...
		PutFuellenEngine();
		// ...
	}

protected:	// ��ӹ��� �ڼյ��� ����� �� �ֵ���
	// ������ �۾���... -> ������ �ؼ��� �� �Ǵ� �Լ�
	void Disassemble() { }	// ���� ���ؽ�Ų��(?)
	void PutFuellenEngine() { }
	void ConnectCircuit() { }

public:
	// �ڵ�
	// ���
	// ����
	// ��
	// ���⼱
};

// ��� ���� ������ : ���� �������� �θ���� ������ ��� ��������?
// public :	������ ���?
// protected : ��ȣ �޴� ���? �� �ڼյ����׸� �����ٰž� (public -> protected)
// private : �������� �ܺ��� (public, protected -> private)
class SuperCar : public Car
{
public:
	void Test()
	{
		MoveHandle();
		Disassemble();	// private�� �ƴ� protected�� ��ӵǾ� ��� ����
	}
};

class Knight
{
public:
	void SetHp(int hp)	// ��� ������ ������ ���� �̷��� ���!
	{
		_hp = 40;
		if (_hp <= 50)
		{
			// TODO
		}
	}
	int GetHp()
	{
		return _hp;
	}
public:
	int _hp = 100;
};

int main()
{
	Car c;
	// c.Disassemble();		=> private ������ �Լ��̹Ƿ� ������ ����
	
	Knight k1;
	// k1._hp = 200;	// �̷��� ��� ������ �ۿ��� ��ġ�� ���� ����
	k1.SetHp(100);
}