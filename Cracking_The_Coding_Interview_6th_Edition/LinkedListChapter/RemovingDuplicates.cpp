/*
Note: I AM ONLY WRITING OUT THE CLASSES IN MAIN TO KEEP THE CODE IN ONE FILE.
IT IS GENERALLY NOT GOOD PRACTICE TO DO THIS, SO FOR REAL LIFE PRODUCTION CODE,
DON'T DO THIS
*/

/*
Also, this code pertains to the question in the linked list chapter that asks to do the following:
Write code to remove duplicates from an unsorted linked list
*/

#include <iostream>
#ifndef NODE_H
#define NODE_H
class List;
class Node
{
	friend class List;
	private:
		Node* next;
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

			if(Position==1)
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
			if(head==nullptr)
			{
				throw std::runtime_error("Can't delete any elements since the list is empty");
			}
			else if(Position==1)
			{
				Node* oldHead=head;

				head=head->next;

				delete oldHead;

				numberOfElements--;
			}
			else
			{
				Node* current=head;

				for(int j=0;j<Position-2;++j)
				{
					current=current->next;
				}

				Node* nodeToDelete=current->next;

				current->next=nodeToDelete->next;

				delete nodeToDelete;

				numberOfElements--;
			}
		}

		/*Helper function for the removing duplicates function*/
		void deleteByValue(const int Value)
		{
			if(head==nullptr)
			{
				throw std::runtime_error("Can't delete any elements since the list is empty");
			}
			else
			{
				Node* current=head;

				/*This node will always be one link ahead of the current node*/
				Node* aheadOfCurrent=current->next;

				/*The case where the head of the list is the one we want to delete*/
				if(head->data==Value)
				{
					head=head->next;

					delete current;

					numberOfElements--;
				}
				else
				{
					while(aheadOfCurrent!=nullptr)
					{
						/*if the node that is one step ahead found the value we want to delete*/
						if(aheadOfCurrent->data==Value)
						{
							/*Set the next pointer of the actual current node to the node that is pointed to 
							by the node that is one step ahead of the current node, breaking the link between the 
							actual current node and the node we want to delete*/
							current->next=aheadOfCurrent->next;

							/*free the node's memory that we want to delete*/
							delete aheadOfCurrent;

							numberOfElements--;

							break;
						}

						/*update the pointer current*/
						current=aheadOfCurrent;

						aheadOfCurrent=aheadOfCurrent->next;
					}
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

void removeDuplicates(List & L)
{
	/*The main logic is this:
	Iterate through the linked list and map the values in the list to the numbe of times they appear in the list
	Then, iterate through the map that we used for step 1 and store the values that appear more than once in a vector
	Finally, iterate through the vector and while the number of duplicates of that specific number is not 1 (no more duplicates)
	keep erasing copies of that specific number
	*/

	cout << "The list before removing duplicates:" << endl;

	L.print();

	map<int, int> listMap;

	vector<int> duplicateValues;

	Node* current=L.getHead();

	while(current!=nullptr)
	{
		listMap[current->getData()]++;

		current=current->getNext();
	}

	for(const auto & element : listMap)
	{
		if(element.second > 1)
		{
			duplicateValues.emplace_back(element.first);
		}
	}

	cout << "Duplicate value(s) to remove" << endl;

	for(const auto & value : duplicateValues)
	{
		cout << value << endl;
	}

	for(int z=0;z<duplicateValues.size();++z)
	{
		int valueToDelete=duplicateValues.at(z);

		int duplicatesLeftToDelete=listMap[valueToDelete];

		do
		{
			L.deleteByValue(valueToDelete);

			duplicatesLeftToDelete--;
		}
		while(duplicatesLeftToDelete!=1);
	}

	cout << "The list with duplicates removed:" << endl;

	L.print();
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

	removeDuplicates(L);
}