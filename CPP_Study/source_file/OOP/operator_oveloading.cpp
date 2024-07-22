#include <iostream>

// 연산자 오버로딩

// - 멤버 연산자 함수 버전
// -- a operation b 형태에서 왼쪽을 기준으로 실행

// - 전역 연산자 함수 버전
// -- a operation b 형태라면, a/b 모두를 연산자 함수의 피연산자로 사용


// 요약 - 대입 연산자는 잘 사용하지 않으니 필요할 때 검색해서 
// 지금은 너무 깊게 들어가지 않는 걸로!
// 연산자를 내가 만들어서 사용한다는 걸 이해하는 게 중요함
class Pos
{
public:
	Pos()
	{

	}

	// explict 개념 종종 면접에 나옴!

	Pos(int b)
	{
		x = b;
		y = b;
	}

	Pos operator+(const Pos& b)
	{
		Pos pos;
		pos.x = x + b.x;
		pos.y = y + b.y;

		return pos;
	}

	Pos operator+(int b)
	{
		Pos pos;
		pos.x = x + b;
		pos.y = y + b;

		return pos;
	}

	bool operator==(const Pos& b)
	{
		return x == b.x && y == b.x;
	}

	// 대입 연산자
	void operator=(int b)
	{
		x = b;
		y = b;
	}

	int x;
	int y;
};

Pos operator+(int a, const Pos& b)
{
	Pos pos;
	pos.x = a + b.x;
	pos.y = a + b.y;
	return pos;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = a + b;

	// Pos pos1(10) vs Pos pos1 = 10 <- 이렇게 안 되도록
	
	// Pos pos1;
	// pos1 = 10	// 대입
	Pos pos1(10);
	Pos pos2(20);


	//Pos pos1;
	//Pos pos2;


	//Pos pos3 = pos1 + pos2;
	// pos3 = pos1.operator+(pos2);

	//Pos pos4 = pos3 + 10;	// int 타입
	//pos4 = 10 + pos3;	
}