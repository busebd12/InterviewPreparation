#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "BinaryTreeNode.h"
#include <iostream>
#include <random>
template <typename T>
class BinaryTree
{
	private:
		BinaryTreeNode<T> *root;
		int numberOfElements;
	public:
		BinaryTree(): root(nullptr), numberOfElements(0) {}

		~BinaryTree()
		{
			if(root!=nullptr)
			{
				delete root->leftChild;

				delete root->rightChild;
			}
		}

		BinaryTreeNode<T>* insert(BinaryTreeNode<T> *Root, const int Data)
		{
			BinaryTreeNode<T> *newNode=new BinaryTreeNode<T>(Data);

			if(Root==nullptr)
			{
				Root=newNode;

				numberOfElements++;
			}
			else if(Data > Root->data)
			{
				Root->rightChild=insert(Root->rightChild, Data);
			}
			else
			{
				Root->leftChild=insert(Root->leftChild, Data);
			}

			return Root;
		}

		BinaryTreeNode<T>* Delete(BinaryTreeNode<T> *Root, const int Data)
		{
			if(Root==nullptr)
			{
				return Root;
			}
			else if(Data > Root->data)
			{
				Root->rightChild=Delete(Root->rightChild, Data);
			}	
			else if(Data < Root->data)
			{
				Root->leftChild=Delete(Root->leftChild, Data);
			}
			else
			{
				if(Root->rightChild==nullptr && Root->leftChild==nullptr)
				{
					Root=nullptr;

					delete Root;
				}
				else if(Root->rightChild==nullptr)
				{
					BinaryTreeNode<T> *temp=Root;

					Root=Root->leftChild;

					delete temp;
				}
				else if(Root->leftChild==nullptr)
				{
					BinaryTreeNode<T> *temp=Root;

					Root=Root->rightChild;

					delete temp;
				}
				else
				{
					BinaryTreeNode<T> *temp=findMinimum(Root->rightChild);

					Root->data=temp->data;

					Root->rightChild=Delete(Root->rightChild, temp->data);
				}
				numberOfElements--;
			}
			return root;
		}

		void getRandomNode(BinaryTreeNode<T> *Root)
		{
			/*random number generator since c++11*/
			std::random_device rd;

			/*initialize the random number generator*/
			std::mt19937 gen(rd());

			/*set the range of numbers that we will be using*/
			std::uniform_int_distribution<> dis(1,3);

			int heightOfLeftChild=getHeightOfLeftChild(Root);

			int heightOfRightChild=getHeightOfRightChild(Root);

			if(dis(gen)==1)
			{
				std::cout << "Your random node is: " << Root->getData() << std::endl;
			}
			else if(dis(gen)==2)
			{	
				auto current=Root;

				/*generate a random number between 1 and the height of left subtree
				so when we traverse the tree, we don't go any farther than the last node in the left subtree*/
				std::uniform_int_distribution<> left(1, heightOfLeftChild);

				int counter=0;

				while(counter < left(gen))
				{
					current=current->getLeftChild();

					counter++;
				}

				std::cout << "Your random node is: " << current->getData() << std::endl;
			}
			else
			{
				auto current=Root;

				/*same logic as the left subtree case*/
				std::uniform_int_distribution<> right(1, heightOfLeftChild);

				int counter=0;

				while(counter < right(gen))
				{
					current=current->getRightChild();

					counter++;
				}

				std::cout << "Your random node is: " << current->getData() << std::endl;
			}
		}

		bool search(BinaryTreeNode<T> *Root, const int Data)
		{
			if(Root==nullptr)
			{
				return false;
			}
			else if(Root->getData()==Data)
			{
				return true;
			}
			else if(Data > Root->getDatat())
			{
				return search(Root->getRightChild(), Data);
			}
			else
			{
				return search(Root->getLeftChild(), Data);
			}
		}

		BinaryTreeNode<T>* findMinimum(BinaryTreeNode<T> *Root)
		{
			BinaryTreeNode<T> *current;

			if(Root!=nullptr)
			{
				current=Root;

				while(current!=nullptr)
				{
					current=current->leftChild;
				}
			}

			return current;
		}

		BinaryTreeNode<T>* getRoot() const
		{
			return root;
		}

		int getNumberOfElements() const
		{
			return numberOfElements;
		}

		int getHeightOfLeftChild(BinaryTreeNode<T> *Root)
		{
			if(Root==nullptr)
			{
				return 0;
			}
			else
			{
				return getHeightOfLeftChild(Root->getLeftChild())+1;
			}
		}

		int getHeightOfRightChild(BinaryTreeNode<T> *Root)
		{
			if(Root==nullptr)
			{
				return 0;
			}
			else
			{
				return getHeightOfRightChild(Root->getRightChild())+1;
			}
		}
};
#endif

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

int main()
{
	BinaryTree<int> tree;

	auto root=tree.getRoot();

	root=tree.insert(root, 100);

	root=tree.insert(root, 50);

	root=tree.insert(root, 200);

	root=tree.insert(root, 25);

	root=tree.insert(root, 60);

	root=tree.insert(root, 150);

	root=tree.insert(root, 300);

	//cout << "Your tree has " << tree.getNumberOfElements() << " of elements in it" << endl;

	//tree.Delete(root, 25);

	//cout << "Now, you tree has " << tree.getNumberOfElements() << " of elements in it" << endl;

	//auto randomNode=tree.getRandomNode(root);

	//cout << "Your random node is: " << randomNode->getData() << endl;

	cout << root->getData() << endl;

	tree.getRandomNode(root);
}