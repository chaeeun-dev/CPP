#include <iostream>
#include <vector>
#include "save.h"

class Node
{
public:
	Node(const char* data) : data(data) { }

public:
	const char* data;
	std::vector<Node*> children;
};

Node* CreateTree()
{
	Node* root = new Node("R1 ���߽�");
	{
		Node* node = new Node("������");
		root->children.push_back(node);
		{
			Node* leaf = new Node("����");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("����");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("���丮");
			node->children.push_back(leaf);
		}
	}
	{
		Node* node = new Node("���α׷���");
		root->children.push_back(node);
		{
			Node* leaf = new Node("Ŭ��");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("����");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("����");
			node->children.push_back(leaf);
		}
	}{
		Node* node = new Node("��Ʈ");
		root->children.push_back(node);
		{
			Node* leaf = new Node("���");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("ĳ����");
			node->children.push_back(leaf);
		}
	}

	return root;
}

void PrintTree(Node* root)
{
	std::cout << root->data << std::endl;	// root ����� R1 ���߽� ���

	int size = root->children.size();	// �ڽĵ��� �� ��?
	for (int i = 0; i < size; ++i)	// root ����� child�� ������, ���α׷���, ��Ʈ ���
	{
		Node* node = root->children[i];
		PrintTree(node);
	}	
}

int main()
{
	Node* root = CreateTree();
	PrintTree(root);

	save("cpp.cpp");
}