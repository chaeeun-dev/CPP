#include <iostream>
#include <windows.h>
#include "Helper.h"
#include "Map.h"
#include "Player.h"


 
int main()
{
	SetCursorOnOff(false);

	MovePlayer(3, 2);

	while (true)
	{
		// �Է�
		HandleKeyInput();

		// ����
		HandleMove();

		// ���
		PrintMap1D();
		std::cout << std::endl;
		//PrintMap2D();
	}
	
}