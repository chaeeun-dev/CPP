#pragma once

class Object;	// 전방선언

class ObjectManager
{
public:
	DECLARE_SINGLE(ObjectManager);

	~ObjectManager();

	void Add(Object* object);
	void Remove(Object* object);
	void Clear();

	const vector<Object*>& GetObjects() { return _objects; }

	template<typename T>
	T* CreateObject()
	{
		// type trait
		static_assert(std::is_convertible_v<T*, Object*>);	// type이 내가 원하는 조건이어야 할 때, 예외 체크하는 코드

		T* object = new T();
		object->Init();

		return object;
	}

private:
	vector<Object*> _objects;
};

