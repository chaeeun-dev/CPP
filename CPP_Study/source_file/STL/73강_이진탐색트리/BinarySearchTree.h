#pragma once

struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int key = 0;
};

// Ÿ�Ӿ������� �����ϴ� �� ����, 
// �ð� ���� �־����� �� ������ �� ������ ��!
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

