/*
Note: I AM ONLY WRITING OUT THE CLASSES IN MAIN TO KEEP THE CODE IN ONE FILE.
IT IS GENERALLY NOT GOOD PRACTICE TO DO THIS, SO FOR REAL LIFE PRODUCTION CODE,
DON'T DO THIS
*/

/*
This code corresponds to the following questions:
Implement a function to check if a linked list is a palindrome
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

bool isPalindrome(List & L)
{
	bool result;

	string contents="";

	Node* current=L.getHead();

	while(current!=nullptr)
	{
		string num=to_string(current->getData());

		contents+=num;

		current=current->getNext();
	}

	string reverseContents(contents.rbegin(), contents.rend());

	if(reverseContents==contents)
	{
		cout << "The list is a palindrome" << endl;

		result=true;
	}
	else
	{
		cout << "The list is not a palindrome" << endl;

		result=false;
	}

	return result;
}

int main()
{
	List L1;

	List L2;

	L1.insertAtPosition(1, 7);

	L1.insertAtPosition(2, 1);

	L1.insertAtPosition(3, 6);

	L2.insertAtPosition(1, 5);

	L2.insertAtPosition(2, 9);

	L2.insertAtPosition(3, 5);

	isPalindrome(L1);

	isPalindrome(L2);
}