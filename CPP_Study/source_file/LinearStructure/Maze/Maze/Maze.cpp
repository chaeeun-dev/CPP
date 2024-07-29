#include "pch.h"
#include "Vector.h"
#include "Board.h"
#include "Player.h"

Board board;
Player player;

#include "Stack.h"
// 면접에서 스택과 큐 질문은 잘 안 나오고 사용도 잘 안 하지만,
// 현업에서 유용하게 쓰이는 경우? UI 팝업창, 돌아가기 기능 등
// 기본적으로 벡터가 핵심 역할을 함!

int main()
{
	Stack<int> st;

	st.push(1);
	st.push(2);
	st.push(3);

	int a = st.top();
	st.pop();

	::srand(static_cast<uint32>(time(nullptr)));

	board.Init(25, &player);
	player.Init(&board);

	uint64 lastTick = 0;
	while (true)
	{
#pragma region	프레임 관리
		const uint64 currentTick = ::GetTickCount64();		// 시간 재는 용도
		const uint64 deltaTick = currentTick - lastTick;
		lastTick = currentTick;
#pragma endregion

		// 입력

		// 로직
		player.Update(deltaTick); 

		// 렌더링
		board.Render();
	}
}
