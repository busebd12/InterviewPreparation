#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "BinaryTreeNode.h"
#include <iostream>
template <typename T>
class BinaryTree
{
	private:
		BinaryTreeNode<T> *root;
		int numberOfElements;
	public:
		BinaryTree(): root(nullptr), numberOfElements(0) {}

		BinaryTreeNode<T>* insert(BinaryTreeNode<T> *root, const T Data)
		{
			BinaryTreeNode<T>* newNode=new BinaryTreeNode<T>(Data);

			if(root==nullptr)
			{
				root=newNode;

				numberOfElements++;
			}
			else if(Data < root->data)
			{
				root->leftChild=insert(root->leftChild, Data);
			}
			else
			{
				root->rightChild=insert(root->rightChild, Data);
			}

			return root;
		}

		void preOrderTraversal(BinaryTreeNode<T> *root)
		{
			if(root!=nullptr)
			{
				std::cout << root->data << std::endl;

				preOrderTraversal(root->leftChild);

				preOrderTraversal(root->rightChild);
			}
		}

		void inOrderTraversal(BinaryTreeNode<T> *root)
		{
			if(root!=nullptr)
			{
				inOrderTraversal(root->leftChild);

				std::cout << root->data << std::endl;

				inOrderTraversal(root->rightChild);
			}
		}

		void postOrderTraversal(BinaryTreeNode<T> *root)
		{
			if(root!=nullptr)
			{
				postOrderTraversal(root->leftChild);

				postOrderTraversal(root->rightChild);

				std::cout << root->data << std::endl;
			}
		}

		int getNumberOfElements() const
		{
			return numberOfElements;
		}

		BinaryTreeNode<T>* getRoot() const
		{
			return root;
		}
};
#endif