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
		return nullptr;

	while (node->left)
		node = node->left;

	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	if (!node)
		return nullptr;

	while (node->right)
		node = node->right;

	return node;
}

Node* BinarySearchTree::Next(Node* node)
{
	if (node->right)	// 노드의 right가 있으면
		return Min(node->right);

	Node* parent = node->parent;

	while (parent && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}

	return parent;
}

void BinarySearchTree::Replace(Node* u, Node* v)
{
	// u를 삭제했을 때 끊어진 v를 연결
	if (u->parent == nullptr)	// root노드라면
		_root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;

	if (v)	// null 체크 하는 이유? 어떤 경우 v를 null로 넣을 수도 있기 때문
		v->parent = u->parent;

	delete u;
}

void BinarySearchTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

void BinarySearchTree::Delete(Node* node)
{
	if (!node)
		return;

	if (!node->left)	// 자식 노드가 없을 때
	{
		Replace(node, node->right);
	}
	else if (!node->right)		// 왼쪽 자식 노드만 있을 때
	{
		Replace(node, node->left);
	}
	else	// 자식이 양쪽 다 있을 때(최악의 케이스)	
	{
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}
}
