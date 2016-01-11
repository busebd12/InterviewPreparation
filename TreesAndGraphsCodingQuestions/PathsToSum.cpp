#include "BinaryTree.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <array>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

template <typename T>
int countPathsWithSumFromNode(BinaryTreeNode<T> *Node, int TargetSum, int CurrentSum)
{
	if(Node==nullptr)
	{
		return 0;
	}

	CurrentSum+=Node->getData();

	int totalPaths=0;

	/*if we found a path from the node*/
	if(CurrentSum==TargetSum)
	{
		totalPaths++;
	}

	/*recurse down the left and right children*/
	totalPaths+=countPathsWithSumFromNode(Node->getLeftChild(), TargetSum, CurrentSum);

	totalPaths+=countPathsWithSumFromNode(Node->getRightChild(), TargetSum, CurrentSum);

	return totalPaths;
}

template <typename T>
int countPathsWithSum(BinaryTreeNode<T> *Root, int TargetSum)
{
	if(Root==nullptr)
	{
		return 0;
	}

	/*look at paths from the root and left and right children*/
	int pathsFromRoot=countPathsWithSumFromNode(Root, TargetSum, 0);

	int pathsOnLeft=countPathsWithSumFromNode(Root->getLeftChild(), TargetSum, 0);

	int pathsOnRight=countPathsWithSumFromNode(Root->getRightChild(), TargetSum, 0);

	return pathsFromRoot+pathsOnRight+pathsOnLeft;
}

int main()
{
	BinaryTree<int> tree;

	auto root=tree.getRoot();

	root=tree.insert(root, 100);

	root=tree.insert(root, 50);

	root=tree.insert(root, 200);

	root=tree.insert(root, -10);

	root=tree.insert(root, 60);

	root=tree.insert(root, 150);

	root=tree.insert(root, 300);

	root=tree.insert(root, -11);

	root=tree.insert(root, 9);

	root=tree.insert(root, 55);

	root=tree.insert(root, 70);

	int numberOfLinks=countPathsWithSum(root, 140);

	cout << "The number of links to find the sum is: " << numberOfLinks << endl;
}