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
//		_head = new Node<T>(0);	// 여기서 data는 중요하지 않음
//		_tail = new Node<T>(0);
//		_head->next = _tail;
//		_tail->prev = _head;
//	}
//
//	~List()	// 노드 지워주는 부분
//	{
//		Node<T>* node = _head;
//		while (node)
//		{
//			Node<T>* deleteNode = node;
//			node = node->next;	// 노드를 한 칸씩 이동
//			delete deleteNode;
//		}
//	}
//
//	Node<T>* GetNode(int index)
//	{
//		Node<T>* node = _head->next;
//		if (node == _tail)	// 연결리스트가 비었을 때
//			return nullptr;
//		
//		// 이렇게 찾는 과정은 느린데, 중간 삽입 삭제가 빠르다고 하는 이유?
//		// 면접에서 질문하면 다 낚임..
//		// 특정 노드를 알고 있으면 빠르다!
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
//		// dummy 노드가 없을 때
//		//Node* node = new Node(data);
//		//if (_head == nullptr)
//		//{
//		//	_head = node;
//		//	_tail = node;
//		//}
//		//else
//		//{
//		//	// 꼭 그림 그리면서 코드 작성하기!
//		//	Node* next_node = _head;
//		//	node->next = next_node;
//		//	next_node->prev = node;
//		//	_head = node;
//		//}
//
//		// dummy 노드 사용 - if else문을 안 써도 돼서 깔끔함
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
//	// 삽입 삭제가 항상 빠른 건 아니다.
//	// 특정 위치를 기억하고 있을 때 빠른 것!
//	// 연결리스트에서 가장 핵심은 remove와 add
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
//	// [prev]<->[node]<->[next] 여기서 prev와 next를 이어주면 됨 
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
