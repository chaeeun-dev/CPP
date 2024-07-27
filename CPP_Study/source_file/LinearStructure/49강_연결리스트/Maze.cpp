#include <iostream>
#include "List.h"

int main()
{
    List li;
    
    li.AddAtTail(1);
    Node* node = li.AddAtTail(2);
    li.AddAtTail(3);

    li.Remove(node);    // 노드의 위치를 알고 있을 때가 빠름!
    // 노드의 위치를 찾아야 할 때는 전혀 빠르지 않은 것(꼭 암기)
    li.Print();
}
