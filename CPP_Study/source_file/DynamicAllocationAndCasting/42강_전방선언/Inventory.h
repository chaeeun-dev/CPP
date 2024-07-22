#pragma once

enum
{
	MAX_SLOT = 100
};

// ���漱��		#include "Item.h"�� ������� ����
// ������� �Ʒ�ó�� �ۼ�, cpp ���Ͽ� Item.hf�� include�ϱ�!
class Item;		// ���߿� Item�� ���� ���赵�� �������״�, �˾Ƽ� �����غ���! �̷� ����
// ������� �浹�ϴ� ���� �����ϴ�!

class Inventory
{
public:
	Inventory();
	~Inventory();

	bool AddItem(Item* item);		// �������� �ۿ��� ���� �Ѱ� �޴� ������ ������.
	bool RemoveItem(Item* item);
	Item* GetItemAtSlot(int slot);	// ������ ��ȣ�� �Է��ϸ� �������� ã��

	void Clear();

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

