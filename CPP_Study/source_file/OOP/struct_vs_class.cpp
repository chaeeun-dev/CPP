#include <iostream>

struct Knight1
{
public:		
	int hp;
};

class Knight2
{
//private:
	int hp;
};

// ���� ������
// ���� ���������,
// �տ� �ƹ��͵� �� ���̸� struct�� public, class�� private�� ����Ʈ
// �׷��� struct�� �ڷ� ������, class�� ��ü ���� �뵵�� �������

int main()
{
	Knight1 k1;
	k1.hp = 10;

	Knight2 k2;
	k2.hp = 10;
	// ������ ���� ����
	// => public���� �������� �ʾҴ��� üũ!!!
}