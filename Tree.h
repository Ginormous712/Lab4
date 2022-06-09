#ifndef BLOCK_0
#define BLOCK_0
#include <vector>
using namespace std;
class Tree
{

private:
	class Node
	{
	public:
		int data;
		vector<Node*>pChild;
		Node(int data = 0)
		{
			this->data = data;
			pChild.resize(0);
		}
		Node(int data, int countChild)
		{
			this->data = data;
			this->pChild.resize(countChild);
		}
	};
	Node* root;
	bool recPath(Node el, vector<int>& path, int data);
	void recPrint(Node* el);
public:
	Tree() :  root(nullptr)
	{
	}
	Tree(int data) 
	{
		this->root = new Node(data);
	}
	Tree(Node* node) :root(node)
	{

	}
	//block 1
	//task 2
	vector<int> getPath(int data);
	int getElement(vector<int> arr);
	//task 3
	bool addElement(int data, vector<int> arr);
	//block 2
	//task 7
	void print();
	//block 3
	//task 14
	Tree remove(int data);
	
};

#endif
