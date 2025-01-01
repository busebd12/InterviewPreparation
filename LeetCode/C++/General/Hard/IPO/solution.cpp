#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
    public:
        int findMaximizedCapital(int k, int w, vector<int> & profits, vector<int> & capital)
        {
            int n=profits.size();

            vector<int> projectIndices(n, 0);

            for(int i=0;i<n;i++) //O(n)
            {
                projectIndices[i]=i;
            }

            auto compareLikeThis=[&capital] (const int & lhs, const int & rhs)
            {
                return capital[lhs] < capital[rhs];
            };

            //Sort indices of projects in increasing order of capital
            sort(projectIndices.begin(), projectIndices.end(), compareLikeThis); //O(n * log(n))

            //Maximum heap used to store the profits in increasing order
            priority_queue<int, vector<int>, less<int>> maxHeap;

            int index=0;

            while(k > 0) //O(k)
            {
                //While there is still capital available and our current capital is enough to select values of capital
                while(index < n and w >= capital[projectIndices[index]])
                {
                    //Add the profit associated with completing the project to the max heap
                    maxHeap.emplace(profits[projectIndices[index]]);

                    index+=1;
                }

                //If the max heap is empty, then we can't get any more profit
                if(maxHeap.empty())
                {
                    break;
                }

                //Choose the maximum profit we can obtain each time
                //Since we are using a maximum heap, the highest profit will just be the first element in the heap
                int profit=maxHeap.top();

                maxHeap.pop();

                w+=profit;

                k-=1;
            }

            return w;
        }
};