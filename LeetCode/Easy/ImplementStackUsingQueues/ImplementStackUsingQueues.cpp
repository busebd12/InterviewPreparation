#include <iostream>
#include <queue>
using namespace std;

class Stack
{
	public:
		queue<int> q;

		void push(int x)
		{
			if(q.empty())
			{
				q.push(x);
			}
			else
			{
				q.push(x);

				while(q.front()!=x)
				{
					int oldTop=q.front();

					q.pop();

					q.push(oldTop);
				}
			}
		}

		int pop()
		{
			int topElement=q.front();

			q.pop();

			return topElement;
		}

		int top()
		{
			return q.front();
		}

		bool empty()
		{
			return q.empty();
		}
};