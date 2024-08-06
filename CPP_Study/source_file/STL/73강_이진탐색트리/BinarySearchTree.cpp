#include "BinarySearchTree.h"
#include <iostream>
#include <windows.h>

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	if (_root == nullptr)	// 생성이 안 된 상태일 때
	{
		_root = newNode;
		return;
	}

	// 추가할 위치를 찾기
	Node* node = _root;
	Node* parent = nullptr;

	while (node)
	{
		parent = node;
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	newNode->parent = parent;

	if (key < parent->key)
		parent->left = newNode;
	else
		parent->right;
}

Node* BinarySearchTree::Search(Node* node, int key)
{
	if (node == nullptr || key == node->key)
		return node;

	if (key < node->key)
		return Search(node->left, key);
	else
		return Search(node->right, key);
}

Node* BinarySearchTree::Min(Node* node)
{ 
	if (!node)
		return;

	while (node->left)
		node = node->left;

	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	if (!node)
		return;

	while (node->right)
		node = node->right;

	return node;
}

Node* BinarySearchTree::Next(Node* node)
{
	return nullptr;
}
