#pragma once
class BinaryTree
{
	class Node
	{
	public:
		int data;
		Node* pLeft;
		Node* pRight;
		Node(int data = 0)
		{
			this->data = data;
			pLeft = nullptr;
			pRight = nullptr;
		}
	};
	Node* root;
	void _print(Node* el);
public:
	void add(int data);
	void print();
	BinaryTree(int data):root(new Node(data))
	{

	}
	BinaryTree() :root(nullptr)
	{

	}
};

