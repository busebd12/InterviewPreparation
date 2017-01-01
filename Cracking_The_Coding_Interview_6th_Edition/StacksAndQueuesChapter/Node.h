#ifndef NODE_H
#define NODE_H
template <typename T>
class Stack;

template <typename T>
class Node
{
	friend class Stack<T>;

	private:
		Node* next;
		T data;
	public:
		Node(const T Data):next(nullptr), data(Data) {}

		Node() {}

		Node* getNext() const
		{
			return next;
		}

		T getData() const
		{
			return data;
		}

};
#endif