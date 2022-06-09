#include "StitchedBinaryTree.h"
#include <iostream>
using namespace std;


void StitchedBinaryTree::_add(Node* el, int data,Node* pLeft, Node* pRight, bool LIsChild, bool RIsChild)
{
	if (data < el->data)
	{
		pRight = el;
		if (el->pLeft == nullptr || (el->pLeft != nullptr && el->chLeft == false))
		{
			el->chLeft = true;
			el->pLeft = new Node(data, pLeft, pRight, LIsChild, RIsChild);
			return;
		}
		this->_add(el->pLeft,data, pLeft, pRight, LIsChild, RIsChild);
		return;
	}
	pLeft = el;
	if (el->pRight == nullptr || (el->pRight != nullptr && el->chRight == false))
	{
		el->chRight = true;
		el->pRight = new Node(data, pLeft, pRight, LIsChild, RIsChild);
		return;
	}
	this->_add(el->pRight, data, pLeft, pRight, LIsChild, RIsChild);
	return;
}

void StitchedBinaryTree::add(int data)
{
	if (this->root == nullptr)
	{
		this->root = new Node(data);
		return;
	}
	Node* pLeft, * pRight;
	pLeft = pRight = nullptr;
	bool LIsCh, RIsCh;
	LIsCh = RIsCh = false;
	this->_add(this->root, data, pLeft, pRight, LIsCh, RIsCh);
	
}

void StitchedBinaryTree::_print(Node* el)
{
	cout << el->data << "[(лівий вказівник:(адреса) " << el->pLeft
		<< ",(чи має піддерево)" << el->chLeft
		<< "),(правий вказівник:(адреса) " << el->pRight
		<<
		", (чи має піддерево)" << el->chRight << ")]";
	if ((el->pLeft != nullptr && el->chLeft) || (el->pRight != nullptr && el->chRight))
	{
		cout << " (";
		if (el->pLeft != nullptr && el->chLeft)
			_print(el->pLeft);
		else
			cout << "empty";
		cout << ",";
		if (el->pRight != nullptr && el->chRight)
			_print(el->pRight);
		else
			cout << "empty";
		cout << ")";
	}
}

void StitchedBinaryTree::print()
{
	if (this->root == nullptr)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	cout << this->root->data<< "[(лівий вказівник:(адреса) " << this->root->pLeft
		<<",(чи має піддерево)" << this->root->chLeft
		<< "),(правий вказівник:(адреса) " << this->root->pRight 
		<< 
		", (чи має піддерево)"<< this->root->chRight <<")](";
	if (this->root->pLeft != nullptr && this->root->chLeft)
		_print(this->root->pLeft);
	else
		cout << "empty";
	cout << ", ";
	if (this->root->pRight != nullptr && this->root->chRight)
		_print(this->root->pRight);
	else cout << "empty";
	cout << ")";
}
