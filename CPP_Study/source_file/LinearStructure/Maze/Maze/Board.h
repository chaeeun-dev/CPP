#pragma once
#include "ConsoleHelper.h"

enum
{
	BOARD_MAX_SIZE = 100	// #define은 중요한 것 아니면 지양하기
};

enum class TileType
{
	NONE = 0,
	EMPTY,
	WALL
};

class Board
{
public:
	Board();
	~Board();

	// 가장 핵심 함수는 Init과 Rende 함수!
	void Init(int32 size);	// 초기화 함수
	void Render();

	void GenerateMap();
	TileType GetTileType(Pos pos);
	ConsoleColor GetTileColor(Pos pos);

	Pos GetEnterPos() { return Pos(1, 1); }		// 입장할 때
	Pos GetExitPos() { return Pos(_size - 2, _size - 2); }	// 나갈 때

private:
	TileType	_tile[BOARD_MAX_SIZE][BOARD_MAX_SIZE];
	int32		_size = 0;
};

