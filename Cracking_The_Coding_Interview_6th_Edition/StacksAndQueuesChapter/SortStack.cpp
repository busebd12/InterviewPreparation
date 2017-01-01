#include <iostream>
#ifndef NODE_H
#define NODE_H
template <typename T>
class Stack;

template <typename T>
class Node
{
	friend class Stack<T>;

	private:
		T data;
		Node* next;
	public:
		Node(const T Data): data(Data), next(nullptr) {}

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

#ifndef STACK_H
#define STACK_H
template <typename T>

class Stack
{
	private:
		Node<T> *top;
		int numberOfElements;
	public:
		Stack(): top(nullptr), numberOfElements(0) {}

		~Stack()
		{
			while(!isEmpty())
			{
				pop();
			}
		}

		void push(const T Data)
		{
			Node<T> *newNode=new Node<T>(Data);

			newNode->next=top;

			top=newNode;

			numberOfElements++;
		}

		void pop()
		{
			Node<T>* temp=top;

			top=top->next;

			delete temp;

			numberOfElements--;
		}

		T peek() const
		{
			return top->data;
		}

		Node<T>* getTop() const
		{
			return top;
		}

		int getNumberOfElements() const
		{
			return numberOfElements;
		}

		bool isEmpty() const
		{
			if(top==nullptr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		void print() const
		{
			Node<T> *current=top;

			while(current!=nullptr)
			{
				std::cout << current->data << std::endl;

				current=current->next;
			}
		}
};
#endif

#include <cstdlib>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <numeric>
using namespace std;

void sortStack(Stack<int> & S)
{
	Stack<int> tempStack;

	int numberOfMaxInTempStack=0;

	do
	{
		int currentMax=0;
	
		auto current=S.getTop();

		while(current!=nullptr)
		{
			if(current->getData() >= currentMax)
			{
				currentMax=current->getData();
			}

			current=current->getNext();
		}

		cout << "The max of the stack is " << currentMax << endl;

		cout << endl;

		current=S.getTop();

		while(current!=nullptr)
		{
			if(current->getData() < currentMax)
			{
				auto temp=current->getData();

				tempStack.push(temp);

				S.pop();
			}

			current=current->getNext();
		}

		S.pop();

		if(numberOfMaxInTempStack > 0)
		{
			auto tempStackCurrent=tempStack.getTop();

			while(tempStack.getNumberOfElements()!=numberOfMaxInTempStack)
			{
				auto temp=tempStackCurrent->getData();

				S.push(temp);

				tempStack.pop();

				tempStackCurrent=tempStackCurrent->getNext();
			}
		}
		else
		{
			auto tempStackCurrent=tempStack.getTop();

			while(tempStackCurrent!=nullptr)
			{
				auto temp=tempStackCurrent->getData();

				S.push(temp);

				tempStack.pop();

				tempStackCurrent=tempStackCurrent->getNext();
			}
		}

		tempStack.push(currentMax);

		numberOfMaxInTempStack++;

		cout << "Contents of tempStack:" << endl;

		tempStack.print();

		cout << endl;

		cout << "Contents of the original stack:" << endl;

		S.print();

		cout << endl;

		cout << "Size of the original stack " << S.getNumberOfElements() << endl;
	}
	while(S.getNumberOfElements()!=0);
}

int main()
{
	Stack<int> S;

	S.push(9);

	S.push(5);

	S.push(8);

	S.push(1);

	S.push(0);

	S.print();

	cout << endl;

	sortStack(S);
}