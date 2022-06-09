#include <iostream>
#include <vector>
#include <Windows.h>
#include "Tree.h"
#include "BinaryTree.h"
#include "StitchedBinaryTree.h";
#include <conio.h>
using namespace std;

// Tasks: 1,2,3,7,14,18,20
void prPath(vector<int> path)
{
	std::cout << "шлях:";
	if (path.size() == 0)
	{
		std::cout << "корень." << endl;
	}
	for (int i = 0; i < path.size(); i++)
	{
		std::cout << path[i] << " ";
	}
	std::cout << endl;
}
void test(bool num);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int r = 0;

	while (1)
	{
		std::cout << "Режими роботи:\n";
		std::cout << "1.	Інтерактивний діалоговий режим\n";
		std::cout << "2.	Демонстраційний режим\n";
		std::cout << "3.	Вихід із программи\n";
		r = _getch() - 48;
		if (r == 1)
		{
			test(true);
		
		}
		else if (r == 2)
		{
			test(false);
		}
		else if (r == 3)
			break;
		else continue;
	}
}

void test(bool num)
{
	int r = 0;
	int data = 0;
	vector<int> path;
	Tree MyTree = Tree();
	BinaryTree MyBinaryTree = BinaryTree();
	StitchedBinaryTree MyStitchedBinaryTree = StitchedBinaryTree();
	while (1)
	{
		if (num)
		{
			std::cout << "\n\t1.	операції с деревом\n";
			while (1)
			{
				std::cout << "\n\t\t1.	додати елемент за шляхом\n";
				std::cout << "\t\t2.	отримати елемент за шляхом\n";
				std::cout << "\t\t3.	отримати шлях до елемента\n";
				std::cout << "\t\t4.	видалити елемент\n";
				std::cout << "\t\t5.	друкувати дерево\n";
				std::cout << "\t\t6.	наступний пункт\n";

				r = _getch() - 48;
				if (r == 1)
				{
					prPath(path);
					std::cout << "cin data: ";
					cin >> data;
					bool ch = MyTree.addElement(data, path);
					if (ch) std::cout << "елемент додано.";
					else std::cout << "елемент не додано.";

				}
				else if (r == 2)
				{
					prPath(path);
					std::cout << MyTree.getElement(path);
				}
				else if (r == 3)
				{
					std::cout << "cin data: ";
					cin >> data;
					path = MyTree.getPath(data);
					prPath(path);

				}
				else if (r == 4)
				{
					std::cout << "cin data: ";
					cin >> data;
					Tree delTree = MyTree.remove(data);
					cout << "MyTree:"; MyTree.print();
					cout << "delTree:"; delTree.print();
				}
				else if (r == 5)
				{
					MyTree.print();
				}
				else if (r == 6)
				{
					break;
				}
				else continue;
			}
			std::cout << "\n\t2.	операції с бінарним деревом\n";
			while (1)
			{
				std::cout << "\n\n\t\t1.	додати елемент\n";
				std::cout << "\t\t2.	друкувати дерево\n";
				std::cout << "\t\t3.	наступний пункт\n";
				r = _getch() - 48;
				if (r == 1)
				{
					std::cout << "cin data: ";
					cin >> data;
					MyBinaryTree.add(data);
				}
				if (r == 2)
				{
					std::cout << "print: ";
					MyBinaryTree.print();
				}
				if (r == 3)
				{
					break;
				}
				else continue;

			}
			std::cout << "\n\t3.	операції с прошитим деревом\n";
			while (1)
			{
				std::cout << "\n\t\t1.	додати елемент\n";
				std::cout << "\t\t2.	друкувати дерево\n";
				std::cout << "\t\t3.	вихід\n";
				r = _getch() - 48;
				if (r == 1)
				{
					std::cout << "cin data: ";
					cin >> data;
					MyStitchedBinaryTree.add(data);
				}
				if (r == 2)
				{
					std::cout << "print: ";
					MyStitchedBinaryTree.print();
				}
				if (r == 3)
				{
					goto end_;
				}
				else continue;
			}
		end_:break;
		}
		else
		{
		std::cout << "\t1.	операції с деревом\n";
		std::cout << "\t\t1.	додати елемент за шляхом\n";
		cout << "add 0 in root:";
		MyTree.addElement(0, path);
		cout << "add 1,2,3 in root child:";
		MyTree.addElement(1, path);
		MyTree.addElement(2, path);
		MyTree.addElement(3, path);
		cout << "add 5,6,7 in 0/add 8,9,10 in 1/add 11,12,13 in 2:";
		path.push_back(0);
		MyTree.addElement(5, path);
		MyTree.addElement(6, path);
		MyTree.addElement(7, path);
		path.pop_back();
		path.push_back(1);
		MyTree.addElement(8, path);
		MyTree.addElement(9, path);
		MyTree.addElement(10, path);
		path.pop_back();
		path.push_back(2);
		MyTree.addElement(11, path);
		MyTree.addElement(12, path);
		MyTree.addElement(13, path);
		std::cout << "\t\t2.	отримати елемент за шляхом\n";
		cout << "get 0 1" << MyTree.getElement({0,1});
		cout << "get 1 1" << MyTree.getElement({ 1,1 });
		std::cout << "\t\t3.	отримати шлях до елемента\n";
		cout << "get path to 12"; MyTree.getPath(12);
		std::cout << "\t\t4.	видалити елемент\n";
		cout << "remove 3"; 
		Tree delTree = MyTree.remove(3);
		std::cout << "\t\t5.	друкувати дерево\n";
		cout << "delTree";
		delTree.print();
		MyTree.print();

		std::cout << "\t2.	операції с бінарним деревом\n";
		std::cout << "\n\t\t1.	додати елемент\n";
		cout << "add 5,1,4,2,3,11,12,10";
		int arr[] = { 5,1,4,2,3,11,12,10 };
		for(int i= 0; i < 8;i++)
		MyBinaryTree.add(arr[i]);
		std::cout << "\t\t2.	друкувати дерево\n";
		MyBinaryTree.print();

		std::cout << "\n\t3.	операції с прошитим деревом\n";
			std::cout << "\n\t\t1.	додати елемент\n";
			cout << "add 5,2,4";
			MyStitchedBinaryTree.add(5);
			MyStitchedBinaryTree.add(2);
			MyStitchedBinaryTree.add(4);
			std::cout << "\t\t2.	друкувати дерево\n";
			MyStitchedBinaryTree.print();
			break;
		}
		
	}
	
}
