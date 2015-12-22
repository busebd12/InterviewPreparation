/*
Note: I AM ONLY WRITING OUT THE CLASSES IN MAIN TO KEEP THE CODE IN ONE FILE.
IT IS GENERALLY NOT GOOD PRACTICE TO DO THIS, SO FOR REAL LIFE PRODUCTION CODE,
DON'T DO THIS
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
using namespace std;

List sumListsInReverse(List & L1, List & L2)
{
	string number1="";

	string number2="";

	Node* current1=L1.getHead();

	Node* current2=L2.getHead();

	while(current1!=nullptr)
	{
		string temp=to_string(current1->getData());

		number1+=temp;

		current1=current1->getNext();
	}

	while(current2!=nullptr)
	{
		string temp=to_string(current2->getData());

		number2+=temp;

		current2=current2->getNext();
	}

	reverse(number1.begin(), number1.end());

	reverse(number2.begin(), number2.end());

	int num1=stoi(number1);

	int num2=stoi(number2);

	int sum=num1+num2;

	cout << "The sum is " << sum << endl;

	string sumAsString=to_string(sum);

	reverse(sumAsString.begin(), sumAsString.end());

	cout << "The sum reversed is " << sumAsString << endl;

	List sumList;

	for(int i=0;i<sumAsString.size();++i)
	{
		char temp=sumAsString[i];

		int number=atoi(&temp);

		//cout << number << endl;

		sumList.insertAtPosition(i+1, number);
	}

	sumList.print();

	return sumList;
}

List sumListsNotInReverse(List & L1, List & L2)
{
	string number1="";

	string number2="";

	Node* current1=L1.getHead();

	Node* current2=L2.getHead();

	while(current1!=nullptr)
	{
		string temp=to_string(current1->getData());

		number1+=temp;

		current1=current1->getNext();
	}

	while(current2!=nullptr)
	{
		string temp=to_string(current2->getData());

		number2+=temp;

		current2=current2->getNext();
	}

	int num1=stoi(number1);

	int num2=stoi(number2);

	int sum=num1+num2;

	cout << "The sum is " << sum << endl;

	string sumAsString=to_string(sum);

	List sumList;

	for(int i=0;i<sumAsString.size();++i)
	{
		char temp=sumAsString[i];

		int number=atoi(&temp);

		//cout << number << endl;

		sumList.insertAtPosition(i+1, number);
	}

	sumList.print();

	return sumList;
}

int main()
{
	List L1;

	List L2;

	List L3;

	List L4;

	L1.insertAtPosition(1, 7);

	L1.insertAtPosition(2, 1);

	L1.insertAtPosition(3, 6);

	L2.insertAtPosition(1, 5);

	L2.insertAtPosition(2, 9);

	L2.insertAtPosition(3, 2);

	L3.insertAtPosition(1, 6);

	L3.insertAtPosition(2, 1);

	L3.insertAtPosition(3, 7);

	L4.insertAtPosition(1, 2);

	L4.insertAtPosition(2, 9);

	L4.insertAtPosition(3, 5);

	sumListsInReverse(L1, L2);

	sumListsNotInReverse(L3, L4);

}