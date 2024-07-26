#pragma once
#include <iostream>

class Node
{
	// typedef int T;	// 옛날 문법
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
		_head = new Node(0);	// 여기서 data는 중요하지 않음
		_tail = new Node(0);
		_head->next = _tail;
		_tail->prev = _head;
	}

	~List()	// 노드 지워주는 부분
	{
		Node* node = _head;
		while (node)
		{
			Node* deleteNode = node;
			node = node->next;	// 노드를 한 칸씩 이동
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
		// dummy 노드가 없을 때
		//Node* node = new Node(data);
		//if (_head == nullptr)
		//{
		//	_head = node;
		//	_tail = node;
		//}
		//else
		//{
		//	// 꼭 그림 그리면서 코드 작성하기!
		//	Node* next_node = _head;
		//	node->next = next_node;
		//	next_node->prev = node;
		//	_head = node;
		//}

		// dummy 노드 사용 - if else문을 안 써도 돼서 깔끔함
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

