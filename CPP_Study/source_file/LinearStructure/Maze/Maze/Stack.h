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

	// 2) pop ��
	void pop()
	{
		_container.pop_back();
	}

	// 1) ���� �����͸� ������ �о����
	T& top()
	{
		return _container.back();
	}

	bool empty() { return _container.size() > 0; }
	int size() { return _container.size(); }
private:
	Vector<T> _container;
};

