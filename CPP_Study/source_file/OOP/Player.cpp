#include "Player.h"

void Player::Attack()
{
	std::cout << "Attack" << std::endl;
}

void Player::Die()
{
	std::cout << "Die" << std::endl;
}

void Player::HealMe(int Value)
{
	_hp += Value;
}

