#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    public:
        int eatenApples(vector<int> & apples, vector<int> & days)
        {
            int result=0;

            int n=apples.size();

            int maxDay=-1;

            for(int i=0;i<n;i++) //O(n)
            {
                int rottenDay=i + days[i];

                maxDay=max(maxDay, rottenDay);
            }

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

            for(int day=0;day<=maxDay;day++) //O(maxDay)
            {
                while(!minHeap.empty() and minHeap.top().first <= day) //O(log(day))
                {
                    minHeap.pop();
                }

                if(day < n) //O(n)
                {
                    int todaysApples=apples[day];

                    int dayApplesWillRot=day + days[day];

                    if(todaysApples > 0)
                    {
                        minHeap.emplace(dayApplesWillRot, todaysApples);
                    }
                }

                if(!minHeap.empty())
                {
                    auto [rottenDay, numberOfApples]=minHeap.top();

                    minHeap.pop();

                    numberOfApples-=1;

                    result+=1;

                    if(numberOfApples > 0)
                    {
                        minHeap.emplace(rottenDay, numberOfApples);
                    }
                }
            }

            return result;
        }
};