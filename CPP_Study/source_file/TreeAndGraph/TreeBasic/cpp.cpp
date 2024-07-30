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
	Node* root = new Node("R1 개발실");
	{
		Node* node = new Node("디자인");
		root->children.push_back(node);
		{
			Node* leaf = new Node("전투");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("경제");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("스토리");
			node->children.push_back(leaf);
		}
	}
	{
		Node* node = new Node("프로그래밍");
		root->children.push_back(node);
		{
			Node* leaf = new Node("클라");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("서버");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("엔진");
			node->children.push_back(leaf);
		}
	}{
		Node* node = new Node("아트");
		root->children.push_back(node);
		{
			Node* leaf = new Node("배경");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("캐릭터");
			node->children.push_back(leaf);
		}
	}

	return root;
}

void PrintTree(Node* root)
{
	std::cout << root->data << std::endl;	// root 노드인 R1 개발실 출력

	int size = root->children.size();	// 자식들이 몇 개?
	for (int i = 0; i < size; ++i)	// root 노드의 child인 디자인, 프로그래밍, 아트 출력
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