#pragma once

class Array
{
	using T = int;

public:
	explicit Array(int capacity = 100) : _capacity(capacity)
	{
		_buffer = new T[capacity];
	}

	~Array()
	{
		if (_buffer)
			delete[] _buffer;
	}

	void push_back(const T& data)
	{
		if (_size == _capacity)
		{
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		_buffer[_size] = data;
		_size++;
	}

	void reserve(int capacity)
	{
		if (_capacity >= capacity)
			return;

		T* newData = new T[capacity];

		for (int i = 0; i < _size; ++i)
		{
			newData[i] = _buffer[i];
		}

		if (_buffer)
			delete[] _buffer;

		_buffer = newData;
	}
public:
	int size() { return _size; }
	int capacity() { return _capacity; }
	
private:
	T* _buffer = nullptr;
	int _size = 0;
	int _capacity = 0;
};

