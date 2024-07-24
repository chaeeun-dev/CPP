#include <iostream>
using namespace std;
#include "Knight.h"

// [Bug Report #2]
// Bug Report #1이 잘 해결 되었는지 확인하기 위해
// 기사 10명 생성해서 정보를 출력하고자 합니다.
// 그런데 정보를 출력하다 프로그램이 뻗는 문제가 발생하고 있습니다.
// 크래시 원인을 분석하고 알맞게 고쳐주세요!

// 내가 해결한 방법
// PrintInfo()에서 오류가 발생했는데,
// for (int i = 0; i <= KNIGHT_COUNT; i++)에서 <=로 인해
// 배열의 크기 이상으로 메모리에 접근했기 때문에 엑세스 위반이 발생했다는 걸 발견했다.
// 따라서 for ( int i = 0; i < KNIGHT_COUNT; i++)로 코드를 수정했다.

const int KNIGHT_COUNT = 10;

int main()
{
	Knight* knights[KNIGHT_COUNT];

	for (int i = 0; i < KNIGHT_COUNT; i++)
	{
		knights[i] = new Knight();
	}

	for (int i = 0; i < KNIGHT_COUNT; i++)
	{
		knights[i]->PrintInfo();
		delete knights[i];
	}
}
