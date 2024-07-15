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

	std::cout << "�÷��̾� ����" << std::endl;

	info.hp = 100;
	info.attack = 10;
	info.defence = 2;
	
	return info;
}

Statinfo* CreatePlayer2()	// �ſ� ����!!!!!
{
	Statinfo info;

	std::cout << "�÷��̾� ����" << std::endl;

	info.hp = 100;
	info.attack = 10;
	info.defence = 2;

	return &info;
}

void CreateMonster(Statinfo* info)
{
	std::cout << "���� ����" << std::endl;

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

		std::cout << "���� HP : " << monster->hp << std::endl;
		
		if (monster->hp == 0)
			return;

		damage = monster->attack - player->defence;
		if (damage < 0)
			damage = 0;

		std::cout << "�÷��̾� HP : " << player->hp << std::endl;

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
	// CreatePlayer2() �Լ��� ������,
	// �����Ͱ� ����Ű�� �����Ͱ� �����(���� ������)!!!!!!!
	// �׷��� �ſ�ſ� �����ؾ� �Ѵ�.
	// �ʱ� ���迡 ��û ���� ���´�...

	Statinfo monster;
	CreateMonster(&monster);

	Battle(&player, &monster);
	//Battle(player2, &monster);
}