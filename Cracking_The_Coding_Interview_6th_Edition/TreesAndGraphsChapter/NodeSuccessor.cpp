#include "BinaryTree.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <array>
#include <map>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

template <typename T>
vector<int> levelOrderTraversal(BinaryTreeNode<T> *Root)
{
	vector<int> nodes;

	queue<BinaryTreeNode<T>*> nodeQueue;

	nodeQueue.push(Root);

	int nodesAtCurrentLevel=1;

	int nodesAtNextLevel=0;

	while(nodeQueue.size()!=0)
	{
		auto frontNode=nodeQueue.front();

		nodeQueue.pop();

		nodesAtCurrentLevel--;

		if(frontNode!=nullptr)
		{
			//cout << frontNode->getData() << endl;

			nodes.emplace_back(frontNode->getData());

			nodeQueue.push(frontNode->getLeftChild());

			nodeQueue.push(frontNode->getRightChild());

			nodesAtNextLevel+=2;
		}
		if(nodesAtCurrentLevel==0)
		{
			nodesAtCurrentLevel=nodesAtNextLevel;

			nodesAtNextLevel=0;
		}
	}

	return nodes;
}

template <typename T>
void findInOrderSuccessor(vector<T> Nodes)
{
	int choice;

	cout << "Please choose a node from the following list to find its successor:" << endl;

	for(const auto & node :  Nodes)
	{
		cout << node << " ";
	}

	cout << endl;

	cin >> choice;

	sort(Nodes.begin(), Nodes.end());

	auto position=find_if(Nodes.begin(), Nodes.end(), [choice] (const auto & element) {return element==choice;});

	cout << *(++position) << endl;
}


int main()
{
	BinaryTree<int> tree;

	auto root=tree.getRoot();

	/*random number generator since c++11*/
	random_device rd;

	/*initialize the random number generator*/
	mt19937 gen(rd());

	/*set the range of numbers that we will be using*/
	uniform_int_distribution<> dis(1,100);

	for(int i=0;i<7;++i)
	{
		root=tree.insert(root, dis(gen));
	}

	/*
	root=tree.insert(root, 10);

	root=tree.insert(root, 9);

	root=tree.insert(root, 15);

	root=tree.insert(root, 8);

	root=tree.insert(root, 11);

	root=tree.insert(root, 14);

	root=tree.insert(root, 16);
	*/

	auto Nodes=levelOrderTraversal(root);

	findInOrderSuccessor(Nodes);
}