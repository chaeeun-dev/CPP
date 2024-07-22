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
		std::cout << "[��͵�] �Ϲ�" << std::endl;
		break;
	case IR_Rare:
		std::cout << "[��͵�] ����" << std::endl;
		break;
	case IR_Unique:
		std::cout << "[��͵�] ����ũ" << std::endl;
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
	std::cout << "[������ Ÿ��] : ����" << std::endl;
	std::cout << "[���ݷ�] : " << _damage << std::endl;
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
	std::cout << "[������ Ÿ��] : ��" << std::endl;
	std::cout << "[����] : " << _defence << std::endl;
	Item::PrintInfo();
	std::cout << "*************************" << std::endl;
}