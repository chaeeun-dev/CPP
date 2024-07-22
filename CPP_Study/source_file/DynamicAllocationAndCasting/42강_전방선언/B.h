#pragma once

class A;	

class B
{
public:
	int hp;
	int defence;
	int attack;

	A* a;
	// 전방선언 - 나중에 등장할 것을 예고하는 것! B 생성자에 a->mp = 10; 이런 코드는 안 됨
	// A가 포인터 형태로 있어야 함.
	// 포인터를 쓰지 않고 모든 데이터를 받아오려면, 전방선언 대신 헤더 파일을 include해야함!
	// 근데 헤더 파일을 include하는 형식으로 사용하면, 꼬일 수 있어서 굉장히 위험함!
	// 어지간해선 헤더 파일에는 헤더 파일을 include하지 말자.
	// 사용할 때는 cpp에서 include하기
};

