#pragma once

struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int key = 0;
};

// 타임어택으로 구현하는 것 말고, 
// 시간 많이 주어졌을 때 구현할 수 있으면 됨!
class BinarySearchTree
{
public:
	void Insert(int key);

	Node* Search(Node* node, int key);

	Node* Min(Node* node);
	Node* Max(Node* node);
	Node* Next(Node* node);

private:
	Node* _root = nullptr;
};

