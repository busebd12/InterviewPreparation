/*
Note: I AM ONLY WRITING OUT THE CLASSES IN MAIN TO KEEP THE CODE IN ONE FILE.
IT IS GENERALLY NOT GOOD PRACTICE TO DO THIS, SO FOR REAL LIFE PRODUCTION CODE,
DON'T DO THIS
*/

/*
This code is for the question which asks you to write a function to find the 
kth to last element in a singly linked list
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
using namespace std;

void KthToLast(List & L, int Position)
{
	Node* current=L.getHead();

	int count=L.getNumberOfElements();

	int kthToLastElement;

	/*
	The logic is this:
	We get the total number of elements in our list (count) 
	Position-1 is there because we start our pointer at the head, so we are already 1 spot into our list
	so whatever positon we want to go to, we just have to increment one less since we have already seen the first spot
	Finallly, we subtract the two to get the spot with respect to the entire list.
	*/

	for(int i=0;i<count-(Position-1);++i)
	{
		kthToLastElement=current->getData();

		current=current->getNext();
	}

	cout << "In the list:" << endl;

	L.print();

	cout << endl;

	cout << "The " << Position << " (st/rd/th) to last element is " << kthToLastElement << endl;
}

int main()
{
	List L;

	L.insertAtPosition(1, 5);

	L.insertAtPosition(2, 7);

	L.insertAtPosition(3, 7);

	L.insertAtPosition(4, 9);

	L.insertAtPosition(5, 10);

	L.insertAtPosition(6, 11);

	L.insertAtPosition(7, 11);

	//L.print();

	KthToLast(L, 4);


}