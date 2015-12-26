#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <unordered_map>
#ifndef QUEUE_H
#define QUEUE_H
template <typename T>
class Queue
{
	private:
		std::stack<T> primary;
		std::stack<T> secondary;
		int numberOfElements;
	public:
		Queue(): numberOfElements(0) {}

		~Queue()
		{
			while(!primary.empty())
			{
				primary.pop();
			}
		}

		void enqueue(T Data)
		{
			std::cout << "Enqueuing " << Data << std::endl;

			primary.push(Data);

			numberOfElements++;	
		}

		void dequeue()
		{	
			while(primary.size()!=1)
			{
				auto temp=primary.top();

				primary.pop();

				secondary.push(temp);

				//std::cout << "Size of secondary stack: " << secondary.size() << std::endl;

				numberOfElements--;
			}

			std::cout << "popping off " << primary.top() << std::endl;

			primary.pop();

			//std::cout << "after popping the top element" << std::endl;

			while(!secondary.empty())
			{
				//std::cout << "in the while loop" << std::endl;

				auto temp=secondary.top();

				//std::cout << "Moving " << temp << " back to the primary stack" << std::endl;

				secondary.pop();

				primary.push(temp);
			}
		}

		bool isEmpty() const
		{
			if(primary.empty())
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		int getNumberOfElements() const
		{
			return numberOfElements;
		}

		void print()
		{
			while(!primary.empty())
			{
				auto current=primary.top();

				primary.pop();

				secondary.push(current);
			}

			std::cout << std::endl;

			while(!secondary.empty())
			{
				auto current=secondary.top();

				std::cout << current << std::endl;

				primary.push(current);

				secondary.pop();
			}
		}		
};
#endif

using namespace std;

int main()
{
	Queue<int> Q;

	Q.enqueue(5);

	Q.dequeue();

	Q.enqueue(6);

	Q.enqueue(7);

	Q.enqueue(8);

	Q.enqueue(9);

	Q.enqueue(10);

	Q.dequeue();

	Q.print();
}