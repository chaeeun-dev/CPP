#pragma once

#include "Item.h"		// ������ �̷��� �ϸ� �� ��! ���漱���� ����ؾ� ��.

enum
{
	MAX_SLOT = 100
};

class Inventory
{
public:
	Inventory();
	~Inventory();

	bool AddItem(Item* item);		// �������� �ۿ��� ���� �Ѱ� �޴� ������ ������.
	bool RemoveItem(Item* item);

	Item* GetItemAtSlot(int slot);	// ������ ��ȣ�� �Է��ϸ� �������� ã��

	static Inventory* GetInstance();

private:
	int FindEmptySlot();	// �� ������ ã���� AddItem()�ϱ� ����
	int FindItemSlot(Item* item);

private:
	//int hp;		
	// �� �����ʹ� ��� ������ �����ɱ�? 
	// Inventory�� main �Լ��� �����ϸ� STACK, �����Ҵ��ϸ� HEAP, ���� �����ϸ� DATA
	
	Item* _items[MAX_SLOT];		// Item _items[MAX_SLOT]�� �޸� ���� ����
	int _itemCount = 0;		// ������ ���Կ� �� ������ ��
	static Inventory* s_instance;
};

