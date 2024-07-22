#include "Item.h"
#include <iostream>

// ************************
//			Item
// ************************
Item::Item(ItemType itemType) : _itemType(itemType)
{         
	int randValue = rand() % 100;

	if (randValue < 50)
	{
		_rarity = IR_Normal;
	}
	else if (randValue < 80)
	{
		_rarity = IR_Rare;
	}
	else
	{
		_rarity = IR_Unique;
	}
}

Item::~Item()
{

}

void Item::PrintInfo()
{
	switch (_rarity)
	{
	case IR_Normal:
		std::cout << "[희귀도] 일반" << std::endl;
		break;
	case IR_Rare:
		std::cout << "[희귀도] 레어" << std::endl;
		break;
	case IR_Unique:
		std::cout << "[희귀도] 유니크" << std::endl;
		break;
	default:
		break;
	}
}

// ************************
//			Weapon
// ************************
Weapon::Weapon() : Item(IT_Weapon)
/*
	원래는 이 영역에
	Item(); 코드가 자동으로 들어가는데(부모 클래스의 생성자)
	Item()생성자를 Item(ItemType itemType)로 바꿨으니,
	Weapon::Weapon() 생성자도 오류가 발생하는 것이다
	
	해결 방법 -> Weapon::Weapon() 코드 옆에  : Item(IT_Weapon)를 붙임
*/
{
	switch (_rarity)
	{
	case IR_Normal:
		_damage = 1 + rand() % 5;
		break;
	case IR_Rare:
		_damage = 10 + rand() % 5;
		break;
	case IR_Unique:
		_damage = 50 + rand() % 5;
		break;
	}
}

Weapon::~Weapon()
{
}

void Weapon::PrintInfo()
{
	std::cout << "*************************" << std::endl;
	std::cout << "[아이템 타입] : 무기" << std::endl;
	std::cout << "[공격력] : " << _damage << std::endl;
	Item::PrintInfo();
	std::cout << "*************************" << std::endl;
}
 
// ************************
//			Armor
// ************************
Armor::Armor() : Item(IT_Armor)
{
	switch (_rarity)
	{
	case IR_Normal:
		_defence = 1 + rand() % 5;
		break;
	case IR_Rare:
		_defence = 2 + rand() % 5;
		break;
	case IR_Unique:
		_defence = 3 + rand() % 5;
		break;
	}
}

Armor::~Armor()
{
}

void Armor::PrintInfo()
{
	std::cout << "*************************" << std::endl;
	std::cout << "[아이템 타입] : 방어구" << std::endl;
	std::cout << "[방어력] : " << _defence << std::endl;
	Item::PrintInfo();
	std::cout << "*************************" << std::endl;
}