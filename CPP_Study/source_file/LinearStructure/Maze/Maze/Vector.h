#pragma once
#include <assert.h>

template<typename T>	// ���ø� ����
class Vector
{
	
public:
	//  �� �뷮�� �Ҵ�
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
			_buffer = new T[_capacity];	// clear�ص� capacity�� �״����
		}
	}

	~Vector()
	{
		if (_buffer)
			delete[] _buffer;
	}

	// �����͸� �о� �ֱ�
	void push_back(const T& data)	// ���� �߿��� �Լ�!!!
	{
		// TODO

		if (_size == _capacity)		// ���� �ٽ�! �� á�� �� ��� �� ���ΰ�?
		{
			// ���� �۾� - 1.5��
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)	// capacity�� 1�̳� 0�̶� �������ٸ� ���������� �÷���
				newCapacity++;

			reserve(newCapacity);
		}
		
		// ������ ����
		_buffer[_size] = data;

		// ������ ���� ����
		_size++;
	}
	
	void pop_back()
	{
		// TODO : �Ҹ�
		_size--;
	}

	T& back()
	{
		return _buffer[_size - 1];
	}
	
	void resize(int size)	// �����ϰ� ������
	{
		// TODO
		reserve(size);
		_size = size;
	}
	
	void reserve(int capacity)
	{
		if (_capacity >= capacity)	// ������ �뷮�� �� ũ�ų� ������
			return;

		_capacity = capacity;

		// �� ū ������ �����
		T* newData = new T[_capacity];

		// ���� �ִ� �����͸� ���� - ���߿��� ���� �̵� ������ ������ ��
		for (int i = 0; i < _size; ++i)
		{
			newData[i] = _buffer[i];
		}

		if (_buffer)
			delete[] _buffer;

		_buffer = newData;
	}

	// �����͸� ���Ƿ� ����
	T& operator[](int index)	
	{
		assert(index >= 0 && index < _size);	// �� ������ ���� ������ ũ���ø� ��
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

