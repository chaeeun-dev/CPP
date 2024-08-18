#include "pch.h"
#include "Missile.h"
#include "TimeManager.h"
#include "ObjectManager.h"

Missile::Missile() : Object(ObjectType::Projectile)
{
}

Missile::~Missile()
{
}

void Missile::Init()
{
	// TODO : Data
	_stat.hp = 1;
	_stat.maxHp = 1;
	_stat.speed = 600;
}

void Missile::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

 	_pos.y -= deltaTime * _stat.speed;

	// 충돌 - 복사 방식으로
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		if (object == this)	// 자신은 넘어감
			continue;

		if (object->GetObjectType() != ObjectType::Monster)	// 몬스터가 아니면 넘어감
			continue;

		Pos p1 = GetPos();	// 내 위치
		Pos p2 = object->GetPos();	// 상대방 위치

		const float dx = p1.x - p2.x;
		const float dy = p1.y - p2.y;
		float dist = sqrt(dx * dx + dy * dy);

		if (dist < 25)
		{
			GET_SINGLE(ObjectManager)->Remove(object);	// 괜찮을..까?
			GET_SINGLE(ObjectManager)->Remove(this);	// 괜찮을..까?
			return;
		}
	}


	// TODO
	// 삭제 - 이렇게 해도 될까?
	if (_pos.y < -100)
	{
 		GET_SINGLE(ObjectManager)->Remove(this);	// 자폭 하자마자 return 때려야함!
		return;
	}
}

void Missile::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 25);
}
