#pragma once

#include "Item.h"		// 원래는 이렇게 하면 안 됨! 전방선언을 사용해야 함.

enum
{
	MAX_SLOT = 100
};

class Inventory
{
public:
	Inventory();
	~Inventory();

	bool AddItem(Item* item);		// 아이템을 밖에서 만들어서 넘겨 받는 식으로 만들자.
	bool RemoveItem(Item* item);

	Item* GetItemAtSlot(int slot);	// 아이템 번호를 입력하면 아이템을 찾아

	static Inventory* GetInstance();

private:
	int FindEmptySlot();	// 빈 슬롯을 찾으면 AddItem()하기 위해
	int FindItemSlot(Item* item);

private:
	//int hp;		
	// 이 데이터는 어느 영역에 생성될까? 
	// Inventory를 main 함수에 선언하면 STACK, 동적할당하면 HEAP, 전역 선언하면 DATA
	
	Item* _items[MAX_SLOT];		// Item _items[MAX_SLOT]과 메모리 구조 차이
	int _itemCount = 0;		// 아이템 슬롯에 찬 아이템 수
	static Inventory* s_instance;
};

