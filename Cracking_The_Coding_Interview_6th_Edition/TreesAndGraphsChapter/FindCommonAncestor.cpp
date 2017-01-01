#include "BinaryTree.h"
#include <iostream>
#include <cstdlib>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <random>
#include <climits>
using namespace std;

template <typename T>
bool nodeExistsInTree(BinaryTreeNode<T> *Root, BinaryTreeNode<T> *Node)
{
	if(Root=nullptr)
	{
		return false;
	}

	if(Root->getData()==Node->getData())
	{
		return true;
	}

	return nodeExistsInTree(Root->getRightChild(), Node) || nodeExistsInTree(Root->getLeftChild(), Node)
}

template <typename T>
BinaryTreeNode<T>* ancestorHelper(BinaryTreeNode<T> *Root, BinaryTreeNode<T> *FirstNode, BinaryTreeNode<T> *SecondNode)
{
	if(Root=nullptr || Root->getData()==FirstNode->getData() || Root->getData()==SecondNode->getData())
	{
		return root;
	}

	bool FirstNodeIsOnLeft=nodeExistsInTree(Root->getLeftChild(), FirstNode);

	bool SecondNodeIsOnLeft=nodeExistsInTree(Root->getLeftChild(), SecondNode);

	/*nodes are on different sides*/
	if(FirstNodeIsOnLeft!=SecondNodeIsOnLeft)
	{
		return root;
	}

	auto childSide=FirstNodeIsOnLeft ? Root->getLeftChild() : Root->getRightChild();

	return ancestorHelper(childSide, FirstNode, SecondNode);
}

template <typename T>
void findCommonAncestor(BinaryTreeNode<T> *Root, BinaryTreeNode<T> *FirstNode, BinaryTreeNode<T> *SecondNode)
{
	/*If one of the nodes doesn't exist in the tree*/
	if(!nodeExistsInTree(Root, FirstNode) || !nodeExistsInTree(Root, SecondNode))
	{
		return nullptr;
	}

	return ancestorHelper(Root, FirstNode, SecondNode);
}