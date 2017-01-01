#include "BinaryTree.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <functional>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;

template <typename T>
int getMaximumValue(BinaryTreeNode<T> *Root)
{
	if(Root==nullptr)
	{
		return 0;
	}

	/*get the data of the root*/
	int rootResult=Root->getData();

	/*recursively get the max of the left subtree*/
	int leftChildResult=getMaximumValue(Root->getLeftChild());

	/*recursively get the max of the right subtree*/
	int rightChildResult=getMaximumValue(Root->getRightChild());

	/*if the max of the left subtree is greater than the root*/
	if(leftChildResult > rootResult)
	{
		rootResult=leftChildResult;
	}
	/*if the max of the right subtree is greater than the root*/
	if(rightChildResult > rootResult)
	{
		rootResult=rightChildResult;
	}

	return rootResult;
}

template <typename T>
int getMinimumValue(BinaryTreeNode<T> *Root)
{
	/*Same idea as with the maximum function above (see comments), just with the minimum instead (so, reverse logic)*/

	if(Root==nullptr)
	{
		return 0;
	}

	int rootResult=Root->getData();

	int leftChildResult=getMinimumValue(Root->getLeftChild());

	int rightChildResult=getMinimumValue(Root->getRightChild());

	if(leftChildResult > rootResult)
	{
		rootResult=leftChildResult;
	}
	if(rightChildResult > rootResult)
	{
		rootResult=rightChildResult;
	}

	return rootResult;
}

template <typename T>
bool isValidBinarySearchTree(BinaryTreeNode<T> *Root)
{
	if(Root==nullptr)
	{
		return false;
	}
	/*if the max of the left subtree is greater than the root, then we violate the property that the root is always greater than its left child*/
	else if( Root->getLeftChild()!=nullptr && getMaximumValue(Root->getLeftChild()) > Root->getData())
	{
		return false;
	}
	/*if the minimum of the right subtree is less than the root, then we voilate the property that the root is always less than its right child*/
	else if(Root->getRightChild()!=nullptr && getMinimumValue(Root->getRightChild()) < Root->getData())
	{
		return false;
	}
	else
	{
		return true;
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

	bool result=isValidBinarySearchTree(root);

	cout << "Is our binary tree a binary search tree: " << boolalpha << result << endl;
}