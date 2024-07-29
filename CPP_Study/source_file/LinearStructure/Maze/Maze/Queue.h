#pragma once
#include "Vector.h"

// [front/back][][][][][][][]
// [front][][][back][][][][]
// 두 개의 커서를 이용해서 
template<typename T>
class Queue
{
public:
	Queue()
	{
		_continer.resize(100);	// 사이즈를 원하는 크기로 지정
	}

	void push(const T& value)
	{
		// TODO : 다 찾는지 체크
		if (_size == _container.size())
		{

		}

		_container[_back] = value;
		_back = (_back + 1) % _container.size();
		//_back = (_back + 1);
		// 문제점 - back이 다 찼는데 계속 더하면, overflow 발생
		// 해결 - 원 모양으로 다 차면 앞으로 가야함 -> 나머지 연산!
	}

	void pop()
	{
		_front = (_front + 1);
		_size--;
	}

	T& front()
	{
		return _container[_front];
	}
	
	bool empty() { return _size == 0; }
	int size() { return _size; }
private:
	Vector<T> _container;

	int _front = 0;
	int _back = 0;
	int _size = 0
};

