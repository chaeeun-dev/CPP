// 각 객체마다 클래스를 만들면? 
// 코드의 재사용이 안 돼 비효율적임
// Knight, Archer 등의 클래스를 하나하나 다 만들어야 함


// OOP 3대 요소 (면접에서 꼭 나옴 무조건 알고 있어야 함)
// 1) 상속성 << inheritance
// 2) 은닉성 
// 3) 다형성

// cf)
// Is-A vs Has-A
// Knight is a Player - O (상속에 적합)
// Knight has a Player - X (상속X)


// 이런 식으로 상속 구조를 먼저 짬
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

void Fight(Player* p1, Player* p2)		// 상속을 통해 공통적으로! 함수를 여러 개 만들지 않아도 됨
{
	p1->_hp -= p2->_attack;
}
int main()
{
	Knight k1;
	
	Mage m1;
	
	Fight(&k1, &m1);
}