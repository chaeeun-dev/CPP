#include "pch.h"
#include "GameScene.h"
#include "Player.h"
#include "Monster.h"
#include "ObjectManager.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	//_player = new Player();
	//_player->Init();

	// 플레이어만
	{
		Player* player = GET_SINGLE(ObjectManager)->CreateObject<Player>();
		player->SetPos(Pos{ 400, 400 });
		GET_SINGLE(ObjectManager)->Add(player);
	}

	// 몬스터 객체 5개 생성
	for (int32 i = 0; i < 5; i++)
	{
		Monster* monster = GET_SINGLE(ObjectManager)->CreateObject<Monster>();
		monster->SetPos(Pos{ static_cast<float>(i + 1) * 100, 100});	// float->int로 축소 변환이 안 되어 float로 캐스팅
		GET_SINGLE(ObjectManager)->Add(monster);
	}
}

void GameScene::Update()
{
	//if (_player)
	//	_player->Update();


	// *중요 - for문을 순회할 때 &로 원본 벡터에 값을 추가(Update에서 Missile 객체가 Add되고 있음)해서 에러 발생 -> 복사로 바꾸자(vector<Object*>& objects에 &를 떼자)
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		object->Update();
	}
}

void GameScene::Render(HDC hdc)
{
	//if (_player)
	//	_player->Render(hdc);

	const vector<Object*>& objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		object->Render(hdc);
	}
}
