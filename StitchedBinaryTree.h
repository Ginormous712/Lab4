#pragma once
class StitchedBinaryTree
{
	class Node
	{
	public:
		int data;
		Node* pLeft;
		Node* pRight;
		bool chLeft, chRight;
		Node(int data = 0, Node* pLeft = nullptr, Node* pRight = nullptr, bool chLeft = false, bool chRight = false)
		{
			this->data = data;
			this->pLeft = pLeft;
			this->pRight = pRight;
			this->chLeft = chLeft;
			this->chRight = chRight;
		}
	};
	Node* root;
	void _add(Node* el, int data,Node* pLeft,Node*pRight,bool LIsChild,bool RIsChild);
	void _print(Node* el);
public:
	void add(int data);
	void print();
	StitchedBinaryTree(int data) :root(new Node(data))
	{

	}
	StitchedBinaryTree() :root(nullptr)
	{

	}
};

