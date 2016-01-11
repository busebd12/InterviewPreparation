#include "BinaryTree.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <algorithm>
#include <numeric>
#include <random>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;

template <typename T>
int heightOfTree(BinaryTreeNode<T> *Root)
{
	/*if the root of the tree is null, then we know there is no height for the tree; return -1*/
	if(Root==nullptr)
	{
		return -1;
	}
	/*
	else, we recurse down the left side of the tree and calclulate the height.
	then, rescurse down the right side of the tree and calculate the height.
	finally, we have to add one since we are accounting for the root of the tree
	*/
	else
	{
		return max(heightOfTree(Root->getLeftChild()), heightOfTree(Root->getRightChild()))+1;
	}
}

template <typename T>
bool isBinaryTreeBalanced(BinaryTreeNode<T> *Root)
{
	/*
	if the root of the tree is null, then it is balanced since there is zero nodes in the tree
	*/
	if(Root==nullptr)
	{
		return true;
	}

	/*calculate the height of the left subtree*/
	int leftSubtreeHeight=heightOfTree(Root->getLeftChild());

	/*calculate the height of the right subtree*/
	int rightSubtreeHeight=heightOfTree(Root->getRightChild());

	int subtreesHeightDifference=leftSubtreeHeight-rightSubtreeHeight;

	/*
	if the height difference between the left and right subtrees are greater
	than one, then we know the tree is not balanced
	*/
	if(abs(subtreesHeightDifference) > 1)
	{
		return false;
	}
	/*
	recruse down the tree to check to make sure the subtrees are balanced
	*/
	else
	{
		return isBinaryTreeBalanced(Root->getLeftChild()) && isBinaryTreeBalanced(Root->getRightChild());
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

	for(int i=0;i<10;++i)
	{
		root=tree.insert(root, dis(gen));
	}

	bool result=isBinaryTreeBalanced(root);

	cout << boolalpha << "Is the binary tree balanced: " << result << endl;
}