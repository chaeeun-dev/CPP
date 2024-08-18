#pragma once
// 최상위 클래스

enum class ObjectType
{
	None, 
	Player,
	Monster,
	Projectile,
};

class Object
{
public:
	Object(ObjectType type);
	virtual ~Object();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;
	// abstract - 여기서 구현 말고 상속받은 클래스에서 구현

public:
	ObjectType		GetObjectType() { return _type; }
	Pos				GetPos() { return _pos; }
	void			SetPos(Pos pos) { _pos = pos; }

protected:
	ObjectType	_type = ObjectType::None;
	Stat		_stat = {};
	Pos			_pos = {};
};

