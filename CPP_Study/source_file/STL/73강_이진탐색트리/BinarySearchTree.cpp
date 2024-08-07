#include "BinarySearchTree.h"
#include <iostream>
#include <windows.h>

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	if (_root == nullptr)	// ������ �� �� ������ ��
	{
		_root = newNode;
		return;
	}

	// �߰��� ��ġ�� ã��
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
	if (node->right)	// ����� right�� ������
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
	// u�� �������� �� ������ v�� ����
	if (u->parent == nullptr)	// root�����
		_root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;

	if (v)	// null üũ �ϴ� ����? � ��� v�� null�� ���� ���� �ֱ� ����
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

	if (!node->left)	// �ڽ� ��尡 ���� ��
	{
		Replace(node, node->right);
	}
	else if (!node->right)		// ���� �ڽ� ��常 ���� ��
	{
		Replace(node, node->left);
	}
	else	// �ڽ��� ���� �� ���� ��(�־��� ���̽�)	
	{
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}
}
