#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
template <typename T>
class BinaryTree;

template <typename T>
class BinaryTreeNode
{
	friend class BinaryTree<T>;

	private:
		T data;
		BinaryTreeNode<T> *rightChild;
		BinaryTreeNode<T> *leftChild;

	public:
		BinaryTreeNode(const T Data): data(Data), rightChild(nullptr), leftChild(nullptr) {}

		BinaryTreeNode() {}

		void setData(const T Data)
		{
			data=Data;
		}

		BinaryTreeNode<T>* getRightChild() const
		{
			return rightChild;
		}

		BinaryTreeNode<T>* getLeftChild() const
		{
			return leftChild;
		}

		T getData() const
		{
			return data;
		}
};
#endif