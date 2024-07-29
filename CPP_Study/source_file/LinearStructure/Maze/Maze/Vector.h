#pragma once
#include <assert.h>

template<typename T>	// 템플릿 문법
class Vector
{
	
public:
	//  총 용량을 할당
	explicit Vector()
	{
		//_buffer = new T[capacity];
	}
	
	void clear()	
	{
		// TODO
		if (_buffer)
		{
			delete[] _buffer;
			_buffer = new T[_capacity];	// clear해도 capacity는 그대로임
		}
	}

	~Vector()
	{
		if (_buffer)
			delete[] _buffer;
	}

	// 데이터를 밀어 넣기
	void push_back(const T& data)	// 가장 중요한 함수!!!
	{
		// TODO

		if (_size == _capacity)		// 가장 핵심! 꽉 찼을 때 어떻게 할 것인가?
		{
			// 증설 작업 - 1.5배
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)	// capacity가 1이나 0이라 같아진다면 인위적으로 늘려줌
				newCapacity++;

			reserve(newCapacity);
		}
		
		// 데이터 저장
		_buffer[_size] = data;

		// 데이터 개수 증가
		_size++;
	}
	
	void pop_back()
	{
		// TODO : 소멸
		_size--;
	}

	T& back()
	{
		return _buffer[_size - 1];
	}
	
	void resize(int size)	// 간단하게 구현함
	{
		// TODO
		reserve(size);
		_size = size;
	}
	
	void reserve(int capacity)
	{
		if (_capacity >= capacity)	// 이전의 용량이 더 크거나 같으면
			return;

		_capacity = capacity;

		// 더 큰 영역을 만들기
		T* newData = new T[_capacity];

		// 원래 있던 데이터를 복사 - 나중에는 복사 이동 등으로 구현할 것
		for (int i = 0; i < _size; ++i)
		{
			newData[i] = _buffer[i];
		}

		if (_buffer)
			delete[] _buffer;

		_buffer = newData;
	}

	// 데이터를 임의로 접근
	T& operator[](int index)	
	{
		assert(index >= 0 && index < _size);	// 이 조건이 맞지 않으면 크래시를 냄
		return _buffer[index];
	}

public:
	int size() { return _size; }
	int capacity() { return _capacity; }

private:
	T* _buffer = nullptr;
	int _size = 0;
	int _capacity = 0;
};

