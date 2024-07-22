#include "Item.h"
#include <iostream>

// ************************
//			Item
// ************************
Item::Item()
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
Weapon::Weapon()
{
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
Armor::Armor()
{
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