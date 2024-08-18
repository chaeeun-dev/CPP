#include "pch.h"
#include "InputManager.h"

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_states.resize(KEY_TYPE_COUNT, keyState::None);
}

void InputManager::Update()
{
	// ::GetAsyncKeyState(); <- 속도가 좀 느려짐
	
	BYTE asciiKeys[KEY_TYPE_COUNT] = {};	// 256 크기만큼 배열 만들어서 모든 키보드
	if (::GetKeyboardState(asciiKeys) == false)	// 모든 키보드 상태를 다 긁어옴
		return;

	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++)
	{
		// 키가 눌려 있으면 true
		if (asciiKeys[key] & 0x80)
		{
			keyState& state = _states[key];

			// 이전 프레임에 키를 누른 상태라면 PRESS
			if (state == keyState::Press || state == keyState::Down)
				state = keyState::Press;
			else
				state = keyState::Down;
		}
		// 키보드를 뗐을 때 
		else
		{
			keyState& state = _states[key];

			// 이전 프레임에 키를 누른 상태라면 UP
			if (state == keyState::Press || state == keyState::Down)
				state = keyState::Up;
			else
				state = keyState::None;
		}
	}
	 
	// Mouse
	::GetCursorPos(&_mousePos);	// 커서의 좌표를 알아온다
	::ScreenToClient(_hwnd, &_mousePos);
}
