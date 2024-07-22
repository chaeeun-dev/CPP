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
Weapon::Weapon() : Item(IT_Weapon)
/*
	������ �� ������
	Item(); �ڵ尡 �ڵ����� ���µ�(�θ� Ŭ������ ������)
	Item()�����ڸ� Item(ItemType itemType)�� �ٲ�����,
	Weapon::Weapon() �����ڵ� ������ �߻��ϴ� ���̴�
	
	�ذ� ��� -> Weapon::Weapon() �ڵ� ����  : Item(IT_Weapon)�� ����
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
	std::cout << "[������ Ÿ��] : ����" << std::endl;
	std::cout << "[���ݷ�] : " << _damage << std::endl;
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
	std::cout << "[������ Ÿ��] : ��" << std::endl;
	std::cout << "[����] : " << _defence << std::endl;
	Item::PrintInfo();
	std::cout << "*************************" << std::endl;
}