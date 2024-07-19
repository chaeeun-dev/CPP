#include <iostream>

// 낯선 문법 많이 나왔으니 꼭 정리해보기!
// 낯설어도 나중에 익숙해지면 된다
// OOP를 사용하는 이유를 이해하는 것이 가장 중요!

// class는 설계도
class Object	// * 상속성 - 상위 클래스를 만들어 상속
{
	//virtual void Shout() = 0;	// 순수 가상 함수 - 독단적으로 사용할 수 없음
	void Move() {  }
};

class IFly	// 인터페이스 구현하는 느낌
{
	virtual void Fly() = 0;
	virtual void Land() = 0;	
	// 상속 받은 class에서 구현을 꼭 하도록(구현 안 하면 오류남)
};

class Player : public Object, public IFly	// Player가 IFly 인터페이스를 구현
{
public:
	Player() {	}
	~Player() {  }

	virtual void Fly() override {};
	virtual void Land() override {};

	virtual void Shout() {  }	
	// * 다형성 - virtual, 런타임에 어떤 함수 실행할건지 결정됨(동적 바인딩 개념)
	
	void SetHp(int hp) { this->hp = hp; }
	void Move() {  }

private:	// * 은닉성(캡슐화) - 숨겨야 하는 데이터를 숨김
	int hp = 10;
};

void AddObject(Player* player)
{
	player->Shout();
}

void FlyTest(IFly* fly)
{

}

int main()
{
	Player p;
	FlyTest(&p);
}