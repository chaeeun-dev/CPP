#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Missile.h"
#include "ObjectManager.h"

Player::Player() : Object(ObjectType::Player)
{
}

Player::~Player()
{
}

void Player::Init()
{
	// 데이터 시트 : Excel, Json <- 모두가 공용으로 들고 있는 정보 e.g. 아이템 기본 정보, 다국어 처리
	// 데이터 베이스 : Oracle, MSSQL
	// TODO : Data
	_stat.hp = 100;
	_stat.maxHp = 100;
	_stat.speed = 500;

	_pos.x = 400;
	_pos.y = 500;
}

void Player::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	// 거리 = 시간 * 속도

	// GetButton - 계속 누르면 계속, GetButtonDown - 계속 눌러도 한 번만
	if (GET_SINGLE(InputManager)->GetButton(keyType::A))
	{
		_pos.x -= _stat.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButton(keyType::D))
	{
		_pos.x += _stat.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButton(keyType::W))
	{
		_pos.y -= _stat.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButton(keyType::S))
	{
		_pos.y += _stat.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButtonDown(keyType::SpaceBar))
	{
		// TODO : 미사일 발사
		// Missile* missile = new Missile();	object를 생성하는 것은 이렇게 하지 말고, 한 곳에서 모아서 하자(ObjectManager나 Object나 한 곳에다가)
		Missile* missile = GET_SINGLE(ObjectManager)->CreateObject<Missile>();
		missile->SetPos(_pos);
		GET_SINGLE(ObjectManager)->Add(missile);
	}
}

void Player::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 50);
}
