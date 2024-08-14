#include "pch.h"
#include "Game.h"
#include "TimeManager.h"
#include "InputManager.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;			// 윈도우 번호
	_hdc = ::GetDC(hwnd);	// 그리는 도화지 번호

	GET_SINGLE(TimeManager)->Init();	// 싱글톤임을 명시
	GET_SINGLE(InputManager)->Init(hwnd);
}

void Game::Update()
{
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(InputManager)->Update();
}

void Game::Render()
{
	uint32 fps = GET_SINGLE(TimeManager)->GetFps();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();
		wstring str = std::format(L"Mouse({0}), ({1})", mousePos.x, mousePos.y);
		::TextOut(_hdc, 20, 10, str.c_str(), static_cast<int32>(str.size()));

	}

	{
		wstring str = std::format(L"FPS({0}), DT({1} ms)", fps, static_cast<int32>(deltaTime * 1000));
		::TextOut(_hdc, 600, 10, str.c_str(), static_cast<int32>(str.size()));
	}

	::Rectangle(_hdc, 200, 200, 400, 400);
}
