#pragma once
#include <iostream>

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
		_head = new Node(0);	// ���⼭ data�� �߿����� ����
		_tail = new Node(0);
		_head->next = _tail;
		_tail->prev = _head;
	}

	~List()	// ��� �����ִ� �κ�
	{
		Node* node = _head;
		while (node)
		{
			Node* deleteNode = node;
			node = node->next;	// ��带 �� ĭ�� �̵�
			delete deleteNode;
		}
	}

	void Print()
	{
		Node* node = _head->next;
		while (node != _tail)
		{
			std::cout << node->data << std::endl;
			node = node->next;
		}
	}

	//	[dummy] <->[1]<->[2]<->[3]<-> [dummy]
	//  [head]						   [tail]
	Node* AddAtHead(int data)
	{
		// dummy ��尡 ���� ��
		//Node* node = new Node(data);
		//if (_head == nullptr)
		//{
		//	_head = node;
		//	_tail = node;
		//}
		//else
		//{
		//	// �� �׸� �׸��鼭 �ڵ� �ۼ��ϱ�!
		//	Node* next_node = _head;
		//	node->next = next_node;
		//	next_node->prev = node;
		//	_head = node;
		//}

		// dummy ��� ��� - if else���� �� �ᵵ �ż� �����
		Node* node = new Node(data);
		Node* nextNode = _head->next;

		node->next = nextNode;
		nextNode->prev = node;
		_head->prev = node;
		node->next = _head;

		return node;
	}

	Node* AddAtTail(int data)
	{
		Node* node = new Node(data);
		Node* prevNode = _tail->prev;

		prevNode->next = node;
		node->prev = prevNode;
		node->next = _tail;
		_tail->prev = node;

		return node;
	}

private:
	Node* _head = nullptr;
	Node* _tail = nullptr;
};

