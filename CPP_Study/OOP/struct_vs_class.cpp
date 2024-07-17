#include <iostream>

struct Knight1
{
public:		
	int hp;
};

class Knight2
{
//private:
	int hp;
};

// 둘의 차이점
// 거의 비슷하지만,
// 앞에 아무것도 안 붙이면 struct는 public, class는 private이 디폴트
// 그래도 struct는 자료 관리용, class는 객체 지향 용도로 사용하자

int main()
{
	Knight1 k1;
	k1.hp = 10;

	Knight2 k2;
	k2.hp = 10;
	// 엑세스 위반 오류
	// => public으로 설정하지 않았는지 체크!!!
}