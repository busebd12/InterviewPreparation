#include "BinaryTree.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <numeric>
#include <deque>
#include <array>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <deque>
using namespace std;

template <typename T>
deque<deque<T>> allSequences(BinaryTreeNode<T> *Root)
{
	deque<deque<T>> result;

	if(Root==nullptr)
	{
		result.emplace_back(deque<T> temp);

		return result;
	}
	else
	{
		deque<T> prefix;

		prefix.emplace_back(Root->getData());

		deque<deque<T>> weaved;

		/*recursively add all the elements from the left and right subtrees*/
		deque<T> leftSequence=allSequences(Root->getLeftChild());

		deque<T> rightSequences=allSequences(Root->getRightChild());

		/*Weave together each list from the left and right sides*/
		for(auto & element : leftSequences)
		{
			for(auto & element : rightSequences)
			{
				weaveLists(leftSequences, rightSequences, weaved, prefix);

				result.emplace_back(weaved);
			}
		}
	}

	return result;
}

/*Weave lists together in all possible ways. This algorithm works by removing the head of the list, recursing, and then doing the same thing with the other list*/
template <typename T>
void weaveLists(deque<T> first, deque<T> second, deque<deque<T>> results, deque<T> prefix)
{
	/*One list is empty. Add remainder to (a cloned) prefix and store the result*/
	if(first.size()==0 || second.size()==0)
	{
		auto result=prefix

		result.emplace_back(first);

		result.emplace_back(second);

		results.emplace_back(result);

		return;
	}

	/*Recurse with the head of first added to the prefix. Removoing the head will damage first, so we'll need to put it back where we found it afterwards*/
	int headFirst=first.pop_front();

	prefix.emplace_back(headFirst);

	weaveLists(first, second, results, prefix);

	prefix.pop_back();

	first.push_front(headFirst);

	/*Do the same thing with the second, damaging and then restoring the list*/
	int headSecond=second.pop_front();

	prefix.emplace_back(headSecond);

	weaveLists(first, second, results, prefix);

	prefix.pop_back();

	second.push_front(headSecond);
}