#include "pch.h"
#include "DevScene.h"
#include "Utils.h"
#include "InputManager.h"
#include "TimeManager.h"

DevScene::DevScene()
{
}

DevScene::~DevScene()
{
}

void DevScene::Init()
{
}

void DevScene::Update()
{
	
}

void DevScene::Render(HDC hdc)
{
	// ::Rectangle(hdc, 200, 200, 400, 400);
	Utils::DrawCircle(hdc, _playerPos, 50);
}
