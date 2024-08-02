#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	//CalculatePath_RightHand();
	CalculatePath_BFS();
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;
	
	_sumTick += deltaTick;
	if (_sumTick >= 100)
	{
		_sumTick = 0;

		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}

void Player::CalculatePath_RightHand()
{
	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);

	// 목적지
	Pos dest = _board->GetExitPos();

	Pos front[4] =
	{
		Pos(-1, 0), // UP
		Pos(0, -1), // LEFT
		Pos(1, 0), // DOWN
		Pos(0, 1), // RIGHT
	};

	while (pos != dest)
	{
		// 1. 현재 바라보는 방향을 기준으로, 오른쪽으로 갈 수 있는지 확인
		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;
		if (CanGo(pos + front[newDir]))
		{
			// 오른쪽 방향으로 90도 회전
			_dir = newDir;

			// 앞으로 한 보 전진
			pos += front[_dir];

			// 기록
			_path.push_back(pos);
		}
		// 2. 현재 바라보는 방향을 기준으로 전진할 수 있는지 확인
		else if (CanGo(pos + front[_dir]))
		{
			// 앞으로 한 보 전진
			pos += front[_dir];

			// 기록
			_path.push_back(pos);
		}
		else
		{
			// 3. 왼쪽 방향으로 90도 회전
			_dir = (_dir + 1) % DIR_COUNT;
		}
	}

}

// 그래프 기반의 길 찾기인데, 간선에 대한 정보는?
// 초록색으로 연결된 것이 간선!
void Player::CalculatePath_BFS()
{
	Pos pos = _pos;
	Pos dest = _board->GetExitPos();	// 목적지

	Pos front[4] =
	{
		Pos(-1, 0), // UP
		Pos(0, -1), // LEFT
		Pos(1, 0), // DOWN
		Pos(0, 1), // RIGHT
	};

	const int32 size = _board->GetSize();
	vector<vector<bool>> discovered(size, vector<bool>(size, false));
	
	// extra)
	// parent[y][x] = pos -> (y, x)는 Pos에 의해 발견된다.
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	// 예약 시스템
	queue<Pos> q;
	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos.y][pos.x] = pos;	// 나에 의해 발견 되었다

	while (!q.empty())	// 큐가 안 비었으면
	{
		pos = q.front();
		q.pop();

		// 예외 - 목적지 도착했으면 빠져 나오기
		if (pos == dest)
			break;

		for (int32 dir = 0; dir < DIR_COUNT; dir++)
		{
			Pos nextPos = pos + front[dir];
			// 갈 수 있는 지역은 맞는지 확인
			if (!CanGo(nextPos))
				continue;
			// 이미 다른 경로에 의해 발견한 지역인지 확인
			if (discovered[nextPos.y][nextPos.x])
				continue;

			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;	// 이미 왔다고 표시
			parent[nextPos.y][nextPos.x] = pos;

		}
	}

	_path.clear();
	pos = dest;		// 마지막 위치 저장

	while (true)
	{
		_path.push_back(pos);

		// 시작점
		if (pos == parent[pos.y][pos.x])
			break;

		pos = parent[pos.y][pos.x];
	}

	std::reverse(_path.begin(), _path.end());
	//vector<Pos> temp(_path.size());
	//for (int i = 0; i < _path.size(); ++i)
	//{
	//	temp[i] = _path[_path.size() - 1 - i];
	//}
	//_path = temp;
}

// BFS의 특징 - 목적지가 없고, 아무 방향으로 퍼질 수 있다
// 한계 - 가중치를 보고 탐색하지 않는다. 
// 심심할 때 BFS 구현해보기(아마존 1시간 구현 문제)