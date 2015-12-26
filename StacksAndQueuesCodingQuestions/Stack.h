#ifndef STACK_H
#define STACK_H
#include "Node.h"
template <typename T>
class Stack
{
	private:
		Node<T>* top;
		int numberOfElements;
		T minimumElement;
		int minimumElementCount;
	public:
		Stack():top(nullptr), numberOfElements(0), minimumElementCount(0) {}

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

			if(minimumElementCount==0)
			{
				minimumElement=newNode->data;

				minimumElementCount++;
			}
			else 
			{
				if(newNode->data < minimumElement)
				{
					minimumElement=newNode->data;

					minimumElementCount++;
				}
			}

			newNode->next=top;

			top=newNode;

			numberOfElements++;
		}

		void pop()
		{
			Node<T> *oldTop=top;

			top=top->next;

			delete oldTop;

			numberOfElements--;
		}

		T getMinimumElement() const
		{
			std::cout << "The minimum element is " << minimumElement << std::endl;

			return minimumElement;
		}

		T peek() const
		{
			return top->data;
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
				std::cout << current->data << " ";

				current=current->next;
			}

			std::cout << std::endl;
		}
};
#endif