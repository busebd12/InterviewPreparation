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
#include <string>
using namespace std;

Node* doTheListsIntersect(List & L1, List & L2)
{
	Node* result;

	map<int, int> nodeFrequency;

	Node* current1=L1.getHead();

	Node* current2=L2.getHead();

	int sizeOfListOne=L1.getNumberOfElements();

	int sizeOfListTwo=L2.getNumberOfElements();

	int tail1;

	int tail2;

	int count=0;

	current1=L1.getHead();

	current2=L2.getHead();

	while(current1!=nullptr)
	{
		nodeFrequency[current1->getData()]++;

		tail1=current1->getData();

		current1=current1->getNext();
	}

	while(current2!=nullptr)
	{
		nodeFrequency[current2->getData()]++;

		tail2=current2->getData();

		current2=current2->getNext();
	}

	for(const auto & element : nodeFrequency)
	{
		if(element.second==2)
		{
			count++;
		}
	}

	if(tail1==tail2)
	{	
		cout << "The two lists share the same tail, but that does not necessarily mean that they intersect" << endl;

		cout << "We still have to check to see if the two lists are the same. Since, if the two lists are exaclty the same, then they will have the same tail" << endl;

		if(count==nodeFrequency.size())
		{
			cout << "The lists do not insertect since they are two copies the same list" << endl;
		}
		else
		{
			auto position=find_if(nodeFrequency.begin(), nodeFrequency.end(), [] (const auto & element) {return element.second==1;});

			int intersectionValue;

			while(position!=nodeFrequency.end())
			{
				if(position->second==2)
				{
					intersectionValue=position->first;

					break;

					result=new Node(position->first);
				}

				++position;
			}

			cout << "The lists do intersect" << endl;

			cout << "The value at which they intersect is " << position->first << endl;
		}
	}
	else
	{
		cout << "The two lists do not intersect" << endl;

		result=new Node();
	}

	return result;
}

int main()
{
	List L1;

	List L2;

	List L3;

	List L4;

	L1.insertAtPosition(1, 1);

	L1.insertAtPosition(2, 3);

	L1.insertAtPosition(3, 5);

	L1.insertAtPosition(4, 7);

	L1.insertAtPosition(5, 8);

	L1.insertAtPosition(6, 9);

	L1.insertAtPosition(7, 10);


	L2.insertAtPosition(1, 2);

	L2.insertAtPosition(2, 4);

	L2.insertAtPosition(3, 6);

	L2.insertAtPosition(4, 7);

	L2.insertAtPosition(5, 8);

	L2.insertAtPosition(6, 9);

	L2.insertAtPosition(7, 10);


	L3.insertAtPosition(1, 1);

	L3.insertAtPosition(2, 3);

	L3.insertAtPosition(3, 5);

	L3.insertAtPosition(4, 7);

	L3.insertAtPosition(5, 8);

	L3.insertAtPosition(6, 9);

	L3.insertAtPosition(7, 10);


	L4.insertAtPosition(1, 1);

	L4.insertAtPosition(2, 3);

	L4.insertAtPosition(3, 5);

	L4.insertAtPosition(4, 7);

	L4.insertAtPosition(5, 8);

	L4.insertAtPosition(6, 9);

	L4.insertAtPosition(7, 10);


	doTheListsIntersect(L1, L2);

	cout << endl;

	cout << endl;

	doTheListsIntersect(L3, L4);
}