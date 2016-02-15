#ifndef NODE_H
#define NODE_H
#include <iostream>
template <typename T>
class HashTable;

template <typename T>
class Node
{
	friend class HashTable<T>;

	private:
		T data;

	public:
		Node(const T Data): data(Data) {}

		Node() 
		{
			decltype(data) {};
		}

		void setData(const T Data)
		{
			data=Data;
		}

		T getData() const
		{
			return data;
		}
};
#endif