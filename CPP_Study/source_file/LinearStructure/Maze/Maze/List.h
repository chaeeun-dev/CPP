//#pragma once
//#include <iostream>
//
//template<typename T>
//class Node
//{
//public:
//	Node<T>(int data) : data(data), prev(nullptr), next(nullptr) { }
//public:
//	T data;
//	Node<T>* prev;
//	Node<T>* next;
//};
//
//template<typename T>
//class List
//{
//public:
//	List()
//	{
//		_head = new Node<T>(0);	// ���⼭ data�� �߿����� ����
//		_tail = new Node<T>(0);
//		_head->next = _tail;
//		_tail->prev = _head;
//	}
//
//	~List()	// ��� �����ִ� �κ�
//	{
//		Node<T>* node = _head;
//		while (node)
//		{
//			Node<T>* deleteNode = node;
//			node = node->next;	// ��带 �� ĭ�� �̵�
//			delete deleteNode;
//		}
//	}
//
//	Node<T>* GetNode(int index)
//	{
//		Node<T>* node = _head->next;
//		if (node == _tail)	// ���Ḯ��Ʈ�� ����� ��
//			return nullptr;
//		
//		// �̷��� ã�� ������ ������, �߰� ���� ������ �����ٰ� �ϴ� ����?
//		// �������� �����ϸ� �� ����..
//		// Ư�� ��带 �˰� ������ ������!
//		for (int i = 0; i < index; ++i)
//		{
//			if (node == _tail->prev)
//				return nullptr;
//
//			node = node->next;
//		}
//	}
//
//	void Print()
//	{
//		Node<T>* node = _head->next;
//		while (node != _tail)
//		{
//			std::cout << node->data << std::endl;
//			node = node->next;
//		}
//		std::cout << std::endl;
//	}
//
//	//	[dummy] <->[1]<->[2]<->[3]<-> [dummy]
//	//  [head]						   [tail]
//	Node<T>* AddAtHead(int data)
//	{
//		// dummy ��尡 ���� ��
//		//Node* node = new Node(data);
//		//if (_head == nullptr)
//		//{
//		//	_head = node;
//		//	_tail = node;
//		//}
//		//else
//		//{
//		//	// �� �׸� �׸��鼭 �ڵ� �ۼ��ϱ�!
//		//	Node* next_node = _head;
//		//	node->next = next_node;
//		//	next_node->prev = node;
//		//	_head = node;
//		//}
//
//		// dummy ��� ��� - if else���� �� �ᵵ �ż� �����
//		Node<T>* node = new Node(data);
//		Node<T>* nextNode = _head->next;
//
//		node->next = nextNode;
//		nextNode->prev = node;
//		_head->prev = node;
//		node->next = _head;
//
//		return node;
//	}
//
//	Node<T>* AddAtTail(int data)
//	{
//		Node<T>* node = new Node(data);
//		Node<T>* prevNode = _tail->prev;
//
//		prevNode->next = node;
//		node->prev = prevNode;
//		node->next = _tail;
//		_tail->prev = node;
//
//		return node;
//	}
//
//
//	// ���� ������ �׻� ���� �� �ƴϴ�.
//	// Ư�� ��ġ�� ����ϰ� ���� �� ���� ��!
//	// ���Ḯ��Ʈ���� ���� �ٽ��� remove�� add
//	
//	//		[node]
//	// [prev]<->[pos]  
//	void Insert(Node<T>* posNode, int data)
//	{
//		Node<T>* node = new Node(data);
//		Node<T>* prevNode = posNode->prev;
//
//		prevNode->next = node;
//		node->prev = prevNode;
//		node->next = posNode;
//		posNode->prev = node;
//	}
//
//	// [prev]<->[node]<->[next] ���⼭ prev�� next�� �̾��ָ� �� 
//	void Remove(Node<T>* node)
//	{
//		Node<T>* prevNode = node->prev;
//		Node<T>* nextNode = node->next;
//		prevNode->next = nextNode;
//		nextNode->prev = prevNode;
//	}
//private:
//	Node<T>* _head = nullptr;
//	Node<T>* _tail = nullptr;
//};
//
