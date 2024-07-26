#pragma once

class Node
{
	// typedef int T;	// ���� ����
	using T = int;
public:
	Node(int data) : data(data), prev(nullptr), next(nullptr) { }
public:
	T data;
	Node* prev;
	Node* next;
};

class List
{
public:
	List()
	{

	}

	~List()
	{

	}

	Node* AddAtHead(int data)
	{
		Node* node = new Node(data);

		if (_head == nullptr)
		{
			_head = node;
			_tail = node;
		}
		else
		{
			// �� �׸� �׸��鼭 �ڵ� �ۼ��ϱ�!
			Node* next_node = _head;
			node->next = next_node;
			next_node->prev = node;
			_head = node;
		}
	}

private:
	Node* _head = nullptr;
	Node* _tail = nullptr;
};

