#include <iostream>

struct Statinfo
{
	int hp;
	int attack;
	int defence;
};

Statinfo CreatePlayer()
{
	Statinfo info;

	std::cout << "플레이어 생성" << std::endl;

	info.hp = 100;
	info.attack = 10;
	info.defence = 2;
	
	return info;
}

Statinfo* CreatePlayer2()	// 매우 주의!!!!!
{
	Statinfo info;

	std::cout << "플레이어 생성" << std::endl;

	info.hp = 100;
	info.attack = 10;
	info.defence = 2;

	return &info;
}

void CreateMonster(Statinfo* info)
{
	std::cout << "몬스터 생성" << std::endl;

	info->hp = 40;
	info->attack = 8;
	info->defence = 1;

}

void Battle(Statinfo* player, Statinfo* monster)
{
	while (true)
	{
		int damage = player->attack - monster->attack;
		if (damage < 0)
			damage = 0;

		monster->hp -= damage;
		if (monster->hp < 0)
			monster->hp = 0;

		std::cout << "몬스터 HP : " << monster->hp << std::endl;
		
		if (monster->hp == 0)
			return;

		damage = monster->attack - player->defence;
		if (damage < 0)
			damage = 0;

		std::cout << "플레이어 HP : " << player->hp << std::endl;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		if (player->hp == 0)
			return;
	}
}

int main()
{
	Statinfo player;
	player = CreatePlayer();
	
	//Statinfo* player2;
	//player2 = CreatePlayer2();
	// CreatePlayer2() 함수가 끝나면,
	// 포인터가 가리키는 데이터가 사라짐(스택 프레임)!!!!!!!
	// 그래서 매우매우 주의해야 한다.
	// 필기 시험에 엄청 많이 나온다...

	Statinfo monster;
	CreateMonster(&monster);

	Battle(&player, &monster);
	//Battle(player2, &monster);
}