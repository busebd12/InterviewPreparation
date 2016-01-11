#include "BinaryTree.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
using namespace std;

template <typename T>
bool areIdentical(BinaryTreeNode<T> *RootOne, BinaryTreeNode<T> *RootTwo)
{
	/*If the two roots are null, then they are identical*/
	if(RootOne==nullptr && RootTwo==nullptr)
	{
		return true;
	}

	/*if one of the roots is null but the other is not*/
	if(RootOne==nullptr || RootTwo==nullptr)
	{
		return false;
	}

	return RootOne->getData()==RootTwo->getData() && areIdentical(RootOne->getLeftChild(), RootTwo->getLeftChild()) && areIdentical(RootOne->getRightChild(), RootTwo->getRightChild());
}

template <typename T>
bool isSubtree(BinaryTreeNode<T> *Tree, BinaryTreeNode<T> *Subtree)
{
	/*If the subtree is null, then the subtree is part of the larger since it is the empty tree*/
	if(Subtree==nullptr)
	{
		return true;
	}

	/*If the larger tree is empty, then, obviously, it can't contain another tree*/
	if(Tree==nullptr)
	{
		return false;
	}

	/*if the root of the two trees are the same*/
	if(areIdentical(Tree, Subtree)==true)
	{
		return true;
	}

	/*recurse down the left and right children of the larger tree to see if the nodes match the nodes in the subtree*/
	return isSubtree(Tree->getLeftChild(), Subtree) || isSubtree(Tree->getRightChild(), Subtree);
}

int main()
{
	BinaryTree<int> tree;

	BinaryTree<int> tree2;

	auto root=tree.getRoot();

	auto root2=tree2.getRoot();

	/*random number generator since c++11*/
	//random_device rd;

	/*initialize the random number generator*/
	//mt19937 gen(rd());

	/*set the range of numbers that we will be using*/
	//uniform_int_distribution<> dis(1,100);

	/*
	for(int i=0;i<7;++i)
	{
		root=tree.insert(root, dis(gen));
	}
	*/

	root=tree.insert(root, 100);

	root=tree.insert(root, 50);

	root=tree.insert(root, 200);

	root=tree.insert(root, 25);

	root=tree.insert(root, 60);

	root=tree.insert(root, 150);

	root=tree.insert(root, 300);

	root2=tree2.insert(root2, 200);

	root2=tree2.insert(root2, 150);

	root2=tree2.insert(root2, 300);

	bool result=isSubtree(root, root2);

	cout << "Is the smaller tree a subtree of the larger tree?: " << boolalpha << result << endl;
}