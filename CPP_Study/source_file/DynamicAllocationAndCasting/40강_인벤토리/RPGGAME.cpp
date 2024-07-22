#include <iostream>
#include "Item.h"
#include "Inventory.h"
#include "save.h"

// [시스템] 몬스터를 잡을 때, 아이템을 떨군다
Item* DropItem()
{
    if (rand() % 2 == 0)
    {
        Weapon* weapon = new Weapon();
        return weapon;
    }
    else
    {
        Armor* armor = new Armor();
        return armor;
    }
}

int main()
{
    srand((unsigned)time(0));

    for (int i = 0; i < 100; ++i)
    {
        Item* item = DropItem();
        item->PrintInfo();
        
        if (Inventory::GetInstance()->AddItem(item))
        {
            std::cout << "Added Item to lnventory" << std::endl;
        }
        else
        {
            std::cout << "Failed to add Item" << std::endl;
            delete item; 
        }
        
        // PK 닿애서 랜덤으로 일부 아이템 드랍
        for (int i = 0; i < 20; ++i)
        {
            int randIndex = rand() % MAX_SLOT;
            Item* item = Inventory::GetInstance()->GetItemAtSlot(randIndex);
            if (item)   // if (item != nullptr) 과 같은 코드
            {
                if (Inventory::GetInstance()->RemoveItem(item));
                    std::cout << "Removed Item" << std::endl;
            }
        }
    }
    //save("RPGGAME.cpp");
}
