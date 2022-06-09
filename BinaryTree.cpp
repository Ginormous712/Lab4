#include "BinaryTree.h"
#include <iostream>
using namespace std;


void BinaryTree::add(int data)
{
	if (this->root == nullptr)
	{
		this->root = new Node(data);
		return;
	}
	Node* current = this->root;
	while (true)
	{
		if(data < this->root->data)
		{
			if (current->pLeft != nullptr)
				current = current->pLeft;
			else
			{
				current->pLeft = new Node(data);
				return;
			}
		}
		else
		{
			if (current->pRight != nullptr)
				current = current->pRight;
			else
			{
				current->pRight = new Node(data);
				return;
			}
		}
	}
}
void BinaryTree::_print(Node* el)
{
	if (el == nullptr) return;
	cout << el->data;
	if (el->pLeft != nullptr || el->pRight != nullptr)
	{
		cout << " (";
		if (el->pLeft != nullptr)
			_print(el->pLeft);
		else
			cout << "empty";
		cout << ",";
		if (el->pRight != nullptr)
			_print(el->pRight);
		else
			cout << "empty";
		cout << ")";
	}
	
}
void BinaryTree::print()
{
	if (this->root == nullptr)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	cout << this->root->data << " (";
	if (this->root->pLeft != nullptr)
		_print(this->root->pLeft);
	else
		cout << "empty";
	cout << ", ";
	_print(this->root->pRight);
	cout << ")";
}
