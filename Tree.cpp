#include "Tree.h"
#include <vector>
#include <iostream>
using namespace std;
bool Tree::recPath(Node el, vector<int>& path, int data)
{
	for (int i = 0; i < el.pChild.size(); i++)
	{
		if (el.pChild[i]->data == data)
		{
			path.push_back(i);
			return true;
		}
		if (el.pChild[i]->pChild.size() != 0)
		{
			path.push_back(i);
			bool chek = recPath(*(el.pChild[i]), path, data);
			if (chek) return true;
			else path.pop_back();

		}
	}
	return false;
}

vector<int> Tree::getPath(int data)
{
	vector<int> err = vector<int>(0);
	err.push_back(-1);
	if (this->root == nullptr)
	{
		cout << "getPath() error: tree is empty" << endl;
		return err;
	}
	vector<int> path = vector<int>(0);
	if(this->root->data == data)
		return vector<int>(0);
	if (this->root->pChild.size() != 0)
	{
		bool check = recPath(*(this->root), path, data);
		if (check) return path;
	}
	cout << "getPath() error: tree is empty" << endl;
	return err;
}

int Tree::getElement(vector<int> arr)
{
	if (arr.size() == 0)
	{
		cout << "getElement error." << endl;
		return -1;
	}
	if (arr.size() == 1 && arr[0] < 0)
	{
		cout << "getElement error." << endl;
		return -1;
	}
	Node* current = this->root;
	for (int i = 0; i < arr.size(); i++)
	{
		current = current->pChild[arr[i]];
	}
	return current->data;
}

bool Tree::addElement(int data, vector<int> arr)
{
	if (this->root == nullptr)
	{
		this->root = new Node(data);
		return true;
	}
	if (arr.size() == 0)
	{
		this->root->pChild.push_back(new Node(data));
		return true;
	}
	if (arr.size() == 1 && arr[0] < 0)
	{
		return false;
	}
	Node* current = this->root;
	for (int i = 0; i < arr.size(); i++)
	{
		current = current->pChild[arr[i]];
	}
	current->pChild.push_back(new Node(data));
	return true;
}
void Tree::recPrint(Node* el)
{
	cout << "(";
	for (int i = 0; i < el->pChild.size(); i++)
	{
		cout << el->pChild[i]->data;
		if (el->pChild[i]->pChild.size() != 0)
			recPrint(el->pChild[i]);
		if (i != el->pChild.size() - 1)
			cout << ", ";
	}
	cout << ")";
}
void Tree::print()
{
	if (this->root == nullptr)
	{
		cout << "Tree is empty." << endl;
		return;
	}
	cout << this->root->data << " ";
	if (this->root->pChild.size() != 0)
	{
		recPrint(this->root);
		cout << endl;
	}
	else return;

}

Tree Tree::remove(int data)
{
	vector<int> path = this->getPath(data);
	Tree remTree;
	Node* curNode = this->root;
	int i;
	for (i = 0; i < path.size() - 1; i++)
	{
		curNode = curNode->pChild[path[i]];
	}
	remTree = Tree(curNode->pChild[path[i]]);
	auto iter = curNode->pChild.cbegin();
	curNode->pChild.erase(iter+path[i]);
	return remTree;
}




