#include <iostream>

// - 다형성 << polymorphism (poly + morphism)

// 오버로딩(overloading) = 함수의 이름 재사용 (변수 타입이나 개수에 따라)
// 오버라이딩(overriding)

// 상속 관계 이해하기
// Player는 Knight이다 - X
// Knight는 Player이다 - O
// 동물은 개이다 - X
// 개는 동물이다 - O

// virtual을 붙이면 상속 받은 class의 같은 함수에도 virtual이 붙게 됨
// 그래서 상속 받은 class의 함수에도 꼼꼼하게 virtual 붙이자

// virtual function table
// vftable [주소1|주소2|주소3]
// 어떤 타입의 함수를 실행할지

// 추상 클래스 - 직접 사용하지 않고 상속만 하는 클래스(Knight, Archer 등이 상속)
class Player
{
public:
	//virtual void Move() { std::cout << "Player Move()" << std::endl; }
	
	virtual void Move() = 0;	// 순수 가상 함수
	// virtual void Move() abstract;	// 구식
public:
	int _hp;
};

class Knight : public Player
{
public:
	virtual void Move() override { std::cout << "Knight Move()" << std::endl; }

public:
	int _stamina;
};

// 바인딩(Binding) = 묶는다
// - 정적 바인딩 (static binding = 컴파일 시점 결정)
// - 동적 바인딩 (dynamic binding = 실행 시점 결정)

void MovePlayer(Player* player)
{
	player->Move();
}

int main()
{
	Knight k1;
	
	k1.Move();
	// KnightMove()

	MovePlayer(&k1);	// Knight가 Player를 상속 받았기 때문에 실행됨
	// PlayerMove()
	// virtual void Move()로 만들었더니 KnightMove()로 출력됨
}
