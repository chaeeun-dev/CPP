#include <iostream>
#include "save.h"
#include "Item.h"

// 저번까지 배운 내용이 이해는 안 가고 어렴풋이 알 것 같은 게 당연!
// 앞으로 실습을 통해 알아가면 된다

Item* DropItem()    // 함수의 타입을 부모 클래스로 뭉뚱그릴 수 있다
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

        // 아이템의 정보를 찍어보자.
        // Weapon, Armor 타입에 따라서 정보를 출력하려면? virtual 함수 사용
        item->PrintInfo();
    }

    save("RPGGAME.cpp");
}