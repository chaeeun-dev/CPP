#include <iostream>

// OOP 3대 요소 (면접에서 꼭 나옴 무조건 알고 있어야 함)
// 1) 상속성 << inheritance
// 2) 은닉성 << data hiding (캡슐화 encapsulation)
// 3) 다형성

// 자동차
// - 핸들/페달/엔진/문/전기선/휘발유
// 구매자 입장에서 사용 : 핸들/페달/문
// 몰라도 됨(몰라야 됨!) : 엔진, 전기선, 휘발유


// 접근 지정자
// public(공개적?) vs protected(보호 받는?) vs private(개인적?)

class Car
{
public:
	void MoveHandle() { }
	void PushPedal() { }
	void OpenDoor() { }
	void TurnKey()
	{
		// ...
		PutFuellenEngine();
		// ...
	}

protected:	// 상속받은 자손들이 사용할 수 있도록
	// 위험한 작업들... -> 공개를 해서는 안 되는 함수
	void Disassemble() { }	// 차를 분해시킨다(?)
	void PutFuellenEngine() { }
	void ConnectCircuit() { }

public:
	// 핸들
	// 페달
	// 엔진
	// 문
	// 전기선
};

// 상속 접근 지정자 : 다음 세대한테 부모님의 유산을 어떻게 물려줄지?
// public :	공개적 상속?
// protected : 보호 받는 상속? 내 자손들한테만 물려줄거야 (public -> protected)
// private : 나까지만 꿀빤다 (public, protected -> private)
class SuperCar : public Car
{
public:
	void Test()
	{
		MoveHandle();
		Disassemble();	// private이 아닌 protected로 상속되어 사용 가능
	}
};

class Knight
{
public:
	void SetHp(int hp)	// 멤버 변수에 접근할 때는 이렇게 묶어서!
	{
		_hp = 40;
		if (_hp <= 50)
		{
			// TODO
		}
	}
	int GetHp()
	{
		return _hp;
	}
public:
	int _hp = 100;
};

int main()
{
	Car c;
	// c.Disassemble();		=> private 영역의 함수이므로 엑세스 위반
	
	Knight k1;
	// k1._hp = 200;	// 이렇게 멤버 변수를 밖에서 고치는 것은 위험
	k1.SetHp(100);
}