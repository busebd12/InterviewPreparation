#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <random>
#include "BinaryTree.h"
using namespace std;

/*
The logic of the function is as follows:
We use two counting variables which keeps track of the number of nodes in the current level (nodesInCurrentLevel) and the next level (nodesInNextLevel). 
First, we enqueue the root of the tree so we know where to start. 
Then, we add the front node of the queue to the linked list that represents that level of the tree
When we pop a node off the queue, we decrement nodesInCurrentLevel by one. 
When we push its child nodes to the queue, we increment nodesInNextLevel by two. 
When nodesInCurrentLevel reaches 0, we know that the current level has ended and we can add the linked list to the list of linked lists (nodesAtEachLevel)
Then we clear the linked list to prepare for inserting the next level of the tree
*/

template <typename T>
void createListOfDepths(BinaryTreeNode<T> *Root)
{
	list<list<BinaryTreeNode<T>*>> nodesAtEachLevel;

	list<BinaryTreeNode<T>*> level;

	queue<BinaryTreeNode<T>*> nodesQueue;

	int nodesInCurrentLevel=1;

	int nodesInNextLevel=0;

	nodesQueue.push(Root);

	while(nodesQueue.size()!=0)
	{
		auto currentNode=nodesQueue.front();

		nodesQueue.pop();

		nodesInCurrentLevel--;

		if(currentNode!=nullptr)
		{
			//cout << currentNode->getData() << " ";

			level.emplace_back(currentNode);

			nodesQueue.push(currentNode->getLeftChild());

			nodesQueue.push(currentNode->getRightChild());

			nodesInNextLevel+=2;
		}

		if(nodesInCurrentLevel==0)
		{
			nodesAtEachLevel.emplace_back(level);

			level.clear();

			//cout << endl;

			nodesInCurrentLevel=nodesInNextLevel;

			nodesInNextLevel=0;
		}
	}

	cout << "The linked list representation of the nodes at each level:" << endl;

	for(const auto & level : nodesAtEachLevel)
	{
		for(const auto & node : level)
		{
			cout << node->getData() << " ";
		}

		cout << endl;
	}
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

	for(int i=0;i<15;++i)
	{
		root=tree.insert(root, dis(gen));
	}
	
	createListOfDepths(root);
}