#pragma once

enum class keyType
{
	LeftMouse = VK_LBUTTON,
	RightMouse = VK_RBUTTON,

	Up = VK_UP,
	Down = VK_DOWN,
	Left = VK_LEFT,
	Right = VK_RIGHT,
	SpaceBar = VK_SPACE,

	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D'
};

enum class keyState
{
	None,
	Press,
	Down,
	Up,

	End
};

enum
{
	KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX) + 1, 
	KEY_STATE_COUNT = static_cast<int32>(keyState::End)
};



class InputManager
{
	DECLARE_SINGLE(InputManager);

public:
	void Init(HWND hwnd);
	void Update();

	// 누르고 있을 때
	bool GetButton(keyType key) { return GetState(key) == keyState::Press; }

	// 맨 처음 눌렀을 때
	bool GetButtonDown(keyType key) { return GetState(key) == keyState::Down; }

	// 맨 처음 눌렀다가 뗄 때
	bool GetButtonUp(keyType key) { return GetState(key) == keyState::Up; }

	POINT GetMousePos() { return _mousePos; }

private:
	keyState GetState(keyType key) { return _states[static_cast<uint8>(key)]; }
private:
	HWND _hwnd = 0;
	vector<keyState> _states;	// 키보드 뭐가 눌렸는지?
	POINT _mousePos;	// 마우스 위치 int x, int y
};

