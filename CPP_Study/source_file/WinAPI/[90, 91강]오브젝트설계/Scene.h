#pragma once
class Scene	// 추상 클래스로써, Game Scene같은 클래스의 부모가 될 것
{
public:
	Scene();
	virtual ~Scene();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;
};

