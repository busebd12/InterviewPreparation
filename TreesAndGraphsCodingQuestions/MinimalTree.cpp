#include "BinarySearchTree.h"
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <functional>
using namespace std;

template <typename T>
BinarySearchTreeNode<T>* createMinimalHeightBinarySearchTree(vector<T> Array)
{
	createMinimalHeightBinarySearchTree(Array, 0, Array.size()-1);
}

template <typename T>
BinarySearchTreeNode<T>* createMinimalHeightBinarySearchTree(vector<T> Array, int start, int end)
{
	/*
	The logic is as follows:
	To create a tree of minimal height, we need to match the number of nodes in the left
	subtree to the number of nodes in the right subtree as much as we can. This means 
	that we want the root to be the middle of the array, since this owuld mean that half the elements
	would be less than the root and half would be greater than it
	*/

	/*
	The algorithm works in 4 steps:
	1. insert into the tree the middle element of the array (vector)
	2. insert (into the left subtree) the left subarray elements (the elements that are less than the middle element of the array)
	3. insert (into the right subtree) the right subarray elements (the elements that are greater than the middle element of the array)
	4. recurse!
	*/

	if(end < start)
	{
		return nullptr;
	}
	else
	{
		int mid=(start+end)/2;

		BinarySearchTreeNode<T>* newNode=new BinarySearchTreeNode<T>(Array.at(mid));

		newNode->leftChild=createMinimalHeightBinarySearchTree(Array, start, mid-1);

		newNode->rightChild=createMinimalHeightBinarySearchTree(Array, end, mid+1);

		return newNode;
	}

}

int main()
{
	vector<int> array={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	createMinimalHeightBinarySearchTree(array);
}