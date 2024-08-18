#pragma once

#include "Object.h"

class Player : public Object
{
public:
	Player();
	virtual ~Player() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

protected:
	// Object* _target;		이렇게 target을 설정했을 때의 문제점은 target 객체가 삭제될 때 crash
	// 대안 - 아이디 사용
};

