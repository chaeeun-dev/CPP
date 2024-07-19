// �� ��ü���� Ŭ������ �����? 
// �ڵ��� ������ �� �� ��ȿ������
// Knight, Archer ���� Ŭ������ �ϳ��ϳ� �� ������ ��


// OOP 3�� ��� (�������� �� ���� ������ �˰� �־�� ��)
// 1) ��Ӽ� << inheritance
// 2) ���м� 
// 3) ������

// cf)
// Is-A vs Has-A
// Knight is a Player - O (��ӿ� ����)
// Knight has a Player - X (���X)


// �̷� ������ ��� ������ ���� «
// GameObject
// - Creature
// -- Player, Monster, NPC, Pet
// - Projectile
// -- Arrow, Fireball
// - Env

// Item
// -- Sword, Bow, Lance
// - Armor
// -- Helmet, Boots, Armor, Glove
// - Consumable
// -- Potion, Scroll

class Player
{
public: 
	void Move(){ }
	void Attack() { }
	void Die() { }
public:
	int _hp;
	int _attack;
	int _defence;
};

class Knight : public Player
{
public:

public:
};

class Archer : public Player
{
public:

public:

};

class Mage : public Player
{
public:

public:
	int _mp;
};

void Fight(Player* p1, Player* p2)		// ����� ���� ����������! �Լ��� ���� �� ������ �ʾƵ� ��
{
	p1->_hp -= p2->_attack;
}
int main()
{
	Knight k1;
	
	Mage m1;
	
	Fight(&k1, &m1);
}