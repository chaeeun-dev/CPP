#pragma once
class Scene	// �߻� Ŭ�����ν�, Game Scene���� Ŭ������ �θ� �� ��
{
public:
	Scene();
	virtual ~Scene();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;
};

