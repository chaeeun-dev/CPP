#include "pch.h"
#include "InputManager.h"

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_states.resize(KEY_TYPE_COUNT, keyState::None);
}

void InputManager::Update()
{
	// ::GetAsyncKeyState(); <- �ӵ��� �� ������
	
	BYTE asciiKeys[KEY_TYPE_COUNT] = {};	// 256 ũ�⸸ŭ �迭 ���� ��� Ű����
	if (::GetKeyboardState(asciiKeys) == false)	// ��� Ű���� ���¸� �� �ܾ��
		return;

	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++)
	{
		// Ű�� ���� ������ true
		if (asciiKeys[key] & 0x80)
		{
			keyState& state = _states[key];

			// ���� �����ӿ� Ű�� ���� ���¶�� PRESS
			if (state == keyState::Press || state == keyState::Down)
				state = keyState::Press;
			else
				state = keyState::Down;
		}
		// Ű���带 ���� �� 
		else
		{
			keyState& state = _states[key];

			// ���� �����ӿ� Ű�� ���� ���¶�� UP
			if (state == keyState::Press || state == keyState::Down)
				state = keyState::Up;
			else
				state = keyState::None;
		}
	}
	 
	// Mouse
	::GetCursorPos(&_mousePos);	// Ŀ���� ��ǥ�� �˾ƿ´�
	::ScreenToClient(_hwnd, &_mousePos);
}
