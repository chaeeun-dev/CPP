#include "pch.h"
#include "Board.h"

const char* TILE = "■";

Board::Board()
{
}

Board::~Board()
{
}

void Board::Init(int32 size)
{
	_size = size;
	GenerateMap();
}

void Board::Render()
{
	ConsoleHelper::SetCursorPosition(0, 0);
	ConsoleHelper::ShowConsoleCursor(false);

	for (int32 y = 0; y < 25; ++y)
	{
		for (int32 x = 0; x < 25; ++x)
		{
			ConsoleColor color = GetTileColor(Pos(y, x));
			ConsoleHelper::SetCursorColor(color);
			std::cout << TILE;
		}
		std::cout << std::endl;
	}
}

// Binary Tree 미로 생성 알고리즘
// - 책 Mazes For Programmers
void Board::GenerateMap()
{
	for (int32 y = 0; y < 25; ++y)
	{
		for (int32 x = 0; x < 25; ++x)
		{
			if (x % 2 == 0 || y % 2 == 0)
				_tile[y][x] = TileType::WALL;
			else
				_tile[y][x] = TileType::EMPTY;
		}
	}
}

TileType Board::GetTileType(Pos pos)
{
	if (pos.x < 0 || pos.x >= _size)	// 갈 수 없는 곳
		return TileType::NONE;
	if (pos.y < 0 || pos.y >= _size)	// 갈 수 없는 곳
		return TileType::NONE;

	return _tile[pos.y][pos.x];
}

ConsoleColor Board::GetTileColor(Pos pos)
{
	if (GetExitPos() == pos)
		return ConsoleColor::BLUE;

	TileType tileType = GetTileType(pos);

	switch (tileType)
	{
	case TileType::EMPTY:
		return ConsoleColor::GREEN;
	case TileType::WALL:
			return ConsoleColor::RED;
	}
	return ConsoleColor::WHITE;
}
