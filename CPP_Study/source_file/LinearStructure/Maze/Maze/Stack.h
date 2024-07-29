#pragma once
#include "vector.h"

template<typename T>
class Stack
{
public:

	void push(const T& value)
	{
		_container.push_back(value);
	}

	// 2) pop 함
	void pop()
	{
		_container.pop_back();
	}

	// 1) 먼저 데이터를 꺼내서 읽어오고
	T& top()
	{
		return _container.back();
	}

	bool empty() { return _container.size() > 0; }
	int size() { return _container.size(); }
private:
	Vector<T> _container;
};

