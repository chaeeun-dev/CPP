#pragma once

// Item <= 부모 클래스
// - Weapon
// - Armor
// - Consumable

enum ItemRarity
{
	IR_None,
	IR_Normal,
	IR_Rare,
	IR_Unique,
};

// tip) 헤더에 선언한 함수를 cpp에 정의할 때 
// 함수 선택 후 ctrl + . + enter


// tip) 이렇게 정리하면 편함
// ************************
//			Item
// ************************
class Item
{
public:
	Item();
	virtual ~Item();	// 부모 클래스이면, virtual 소멸자로 만들어야 함.
	
	virtual void PrintInfo();
protected:
	int _itemid = 0;
	int _itenCount = 0;
	ItemRarity _rarity = IR_Normal;	// 희귀도
};

// ************************
//			Weapon
// ************************
class Weapon : public Item
{
public:
	Weapon();
	virtual ~Weapon();

	virtual void PrintInfo() override;

	void SetDamage(int damage) { _damage = damage; }
	int GetDamage() { return _damage; } 

private:
	int _damage = 0;	// private으로 막아놨으니, get set으로 접근하자

};

// ************************
//			Armor
// ************************
class Armor : public Item
{
public:
	Armor();
	virtual ~Armor();

	virtual void PrintInfo() override;

	void SetDefence(int defence) { _defence = defence; }
	int GetDefence() { return _defence; }

private:
	int _defence = 0;
};