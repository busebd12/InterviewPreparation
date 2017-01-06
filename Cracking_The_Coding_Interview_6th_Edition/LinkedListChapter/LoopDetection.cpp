/*
Note: I AM ONLY WRITING OUT THE CLASSES IN MAIN TO KEEP THE CODE IN ONE FILE.
IT IS GENERALLY NOT GOOD PRACTICE TO DO THIS, SO FOR REAL LIFE PRODUCTION CODE,
DON'T DO THIS
*/

/*
This code corresponds to the following question:
Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop
*/

#include <iostream>

#ifndef NODE_H
#define NODE_H
class List;
class Node
{
	friend class List;
	private:
		Node *next;
		int data;
	public:
		Node(const int Data):next(nullptr), data(Data) {}

		Node() {}

		Node* getNext() const
		{
			return next;
		}

		int getData() const
		{
			return data;
		}
};
#endif

#ifndef LIST_H
#define LIST_H
class List
{
	private:
		Node* head;
		int numberOfElements;
	public:
		List():head(nullptr), numberOfElements(0) {}

		~List()
		{
			Node* current=head;

			Node* newHead;

			while(current!=nullptr)
			{
				newHead=current->next;

				delete current;

				current=newHead;
			}
		}

		void insertAtPosition(const int Position, const int Data)
		{
			Node* newNode=new Node(Data);

			if(head==nullptr)
			{
				newNode->next=head;

				head=newNode;
			}
			else
			{
				Node* current=head;

				for(int i=0;i<Position-2;++i)
				{
					current=current->next;
				}

				newNode->next=current->next;

				current->next=newNode;
			}

			numberOfElements++;
		}

		void deleteAtPosition(const int Position)
		{
			Node *current=head;

			if(head==nullptr)
			{
				throw std::runtime_error("Can't delete any elements since the list is empty");
			}
			else if(Position==1)
			{
				head=head->next;

				delete current;

				numberOfElements--;
			}
			else
			{
				for(int j=0;j<Position-2;++j)
				{
					current=current->next;
				}

				Node* newCurrentNext=current->next;

				current->next=newCurrentNext->next;

				delete newCurrentNext;

				numberOfElements--;
			}
		}

		void deleteByValue(const int Value)
		{
			if(head==nullptr)
			{
				throw std::runtime_error("Can't delete any elements since the list is empty");
			}
			else if(head->data==Value)
			{
				Node* tempHead=head;

				head=head->next;

				delete tempHead;

				numberOfElements--;
			}
			else
			{
				Node* current=head;

				Node* aheadOfCurrent=head->next;

				while(aheadOfCurrent!=nullptr)
				{
					if(aheadOfCurrent->data==Value)
					{
						current->next=aheadOfCurrent->next;

						delete aheadOfCurrent;

						numberOfElements--;

						break;
					}

					current=aheadOfCurrent;

					aheadOfCurrent=aheadOfCurrent->next;
				}
			}
		}

		void clear()
		{
			Node *current=head;

			Node* newHead;

			while(current!=nullptr)
			{
				newHead=current->next;

				delete current;

				current=newHead;
			}

			head=nullptr;
		}

		Node* getHead() const
		{
			return head;
		}

		int getNumberOfElements() const
		{
			return numberOfElements;
		}

		void print() const
		{
			std::cout << "Your list contains:" << std::endl;

			Node* current=head;

			while(current!=nullptr)
			{
				std::cout << current->data << " ";

				current=current->next;
			}

			std::cout << std::endl;
		}	
};
#endif

#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <functional>
#include <list>
#include <deque>
#include <string>
using namespace std;


void loopDetection(List & L)
{
	Node* slow=L.getHead();

	Node* fast=L.getHead();

	while(slow!=nullptr && fast!=nullptr)
	{	
		slow=slow->getNext();

		fast=fast->getNext()->getNext();

		if(slow==fast)
		{
			break;
		}
	}

	if(fast==nullptr && fast->getNext()==nullptr)
	{
		return nullptr;
	}

	slow=L.getHead();

	while(slow!=fast)
	{
		slow=slow->getNext();

		fast=fast->getNext();
	}

	return fast;

}