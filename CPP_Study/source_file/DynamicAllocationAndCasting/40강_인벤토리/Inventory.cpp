#include "Inventory.h"

Inventory* Inventory::s_instance = nullptr;

Inventory::Inventory()
{
	for (int i = 0; i < MAX_SLOT; ++i)
	{
		_items[i] = nullptr;
	}
}

Inventory::~Inventory()
{

}

bool Inventory::AddItem(Item* item)
{
	if (item == nullptr)	// 넘겨준 아이템이 없다면..	
	// 서버에서는 필수적임!! 무조건 꼼꼼하게 체크하는 습관 들이기
		return false;

	int emptySlot = FindEmptySlot();
	if (emptySlot < 0)	// 빈 공간이 없으면
		return false;

	_items[emptySlot] = item;
	_itemCount++;
	return true;

}

bool Inventory::RemoveItem(Item* item)
{
	if (item == nullptr)
		return false;

	int slot = FindItemSlot(item);
	if (slot < 0)
		return false;

	_items[slot] = nullptr;
	_itemCount--;
	
// delete item	? 크래시가 안 나도록! 심사숙고하자.

}

Item* Inventory::GetItemAtSlot(int slot)
{
	if (slot < 0 || slot >= MAX_SLOT)
		return nullptr;

	return _items[slot];
}

Inventory* Inventory::GetInstance() 
{
	if (s_instance == nullptr)
		s_instance = new Inventory();

	return s_instance;
}
int Inventory::FindEmptySlot()
{
	for (int i = 0; i < MAX_SLOT; ++i)
	{
		if (_items[i] == nullptr)
			return i;
	}
	return -1;	// 못찾으면 -1 반환
}

int Inventory::FindItemSlot(Item* item)
{
	for (int i = 0; i < MAX_SLOT; ++i)
	{
		if (_items[i] == item)
			return i;
	}
	return -1;
}