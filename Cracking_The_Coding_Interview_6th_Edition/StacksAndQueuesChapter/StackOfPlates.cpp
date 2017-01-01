#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <string>
#include <deque>

#ifndef STACK_H
#define STACK_H
#include "Node.h"
template <typename T>
class Stack
{
	private:
		Node<T>* top;
		int numberOfElements;
		int capacity;
		int capacityCounter;
	public:
		Stack():top(nullptr), numberOfElements(0), capacity(5), capacityCounter(0) {}

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

			capacityCounter++;
		}

		void pop()
		{
			Node<T> *oldTop=top;

			top=top->next;

			delete oldTop;

			numberOfElements--;
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

		bool isFull() const
		{
			if(numberOfElements==capacity)
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

#ifndef SETOFSTACKS_H
#define SETOFSTACKS_H

template <typename T>
class SetOfStacks
{
	private:
		std::deque<Stack<T>> setOfStacks;

	public:
		SetOfStacks() {}

		void push(const T Data)
		{
			/*just call the push function for stack within the stack*/

			//get the last stack within the set of stacks
			Stack<T> last=getLastStack();

			//if the stack is not full, push data into it
			if(!(last.isFull()))
			{
				last.push(Data);
			}
			//else, the stack is full, and we must create a new one and add the data to the new one
			else
			{
				Stack<T> newStack;

				newStack.push(Data);

				setOfStacks.addStack(newStack);
			}

		}

		void pop()
		{	
			/*just call the pop function for the stack within the stack*/

			//get the last stack
			Stack<T> last=getLastStack();

			//pop the value from the current stack
			int value=last.pop();

			/*
			if the pop operation caused the size of the current stack to become zero
			remove that stack from the set of stacks
			*/
			if(last.getNumberOfElements()==0)
			{
				setOfStacks.removeStack();
			}
		}

		void addStack(Stack<T> & S)
		{
			setOfStacks.emplace_front(S);
		}

		void removeStack()
		{
			setOfStacks.pop_front();
		}

		Stack<T> getLastStack() const
		{
			return setOfStacks.front();
		}

		bool isEmpty() const
		{
			if(setOfStacks.size==0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};
#endif

int main()
{
	return 0;
}