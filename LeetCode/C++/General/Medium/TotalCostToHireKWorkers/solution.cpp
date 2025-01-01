#include <algorithm>
#include <deque>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
    public:
        long long totalCost(vector<int> & costs, int k, int candidates)
        {
            long long result=0;

            deque<int> workerCosts(costs.begin(), costs.end());

            while(k > 0)
            {
                auto [firstCost, firstCostIndex]=getWorkerFromFirstGroup(workerCosts, candidates);

                auto [secondCost, secondCostIndex]=getWorkerFromSecondGroup(workerCosts, candidates);

                if(firstCost < secondCost)
                {
                    result+=firstCost;

                    swap(workerCosts[0], workerCosts[firstCostIndex]);

                    workerCosts.pop_front();
                }
                else if(secondCost < firstCost)
                {
                    result+=secondCost;

                    swap(workerCosts[workerCosts.size() - 1], workerCosts[secondCostIndex]);

                    workerCosts.pop_back();
                }
                else
                {
                    result+=firstCost;

                    int indexToRemove=min(firstCostIndex, secondCostIndex);

                    swap(workerCosts[0], workerCosts[indexToRemove]);

                    workerCosts.pop_front();
                }

                k-=1; 
            }

            return result;
        }

        pair<long long, int> getWorkerFromFirstGroup(deque<int> & workerCosts, int candidates)
        {
            long long minCost=numeric_limits<long long>::max();

            int minCostIndex=-1;

            int count=0;

            int index=0;

            while(index < workerCosts.size() and count < candidates)
            {
                long long currentCost=(long)workerCosts[index];

                if(currentCost <= minCost)
                {   
                    if(currentCost < minCost)
                    {
                        minCost=currentCost;

                        minCostIndex=index;
                    }
                    else if(currentCost==minCost)
                    {
                        minCostIndex=min(minCostIndex, index);
                    }
                }

                index+=1;

                count+=1;
            }

            return make_pair(minCost, minCostIndex);
        }

        pair<long long, int> getWorkerFromSecondGroup(deque<int> & workerCosts, int candidates)
        {
            long long minCost=numeric_limits<long long>::max();

            int minCostIndex=-1;

            int count=0;

            int index=workerCosts.size()-1;

            while(index >= 0 and count < candidates)
            {
                long long currentCost=(long)workerCosts[index];

                if(currentCost <= minCost)
                {   
                    if(currentCost < minCost)
                    {
                        minCost=currentCost;

                        minCostIndex=index;
                    }
                    else if(currentCost==minCost)
                    {
                        minCostIndex=min(minCostIndex, index);
                    }
                }

                index-=1;

                count+=1;
            }

            return make_pair(minCost, minCostIndex);
        }
};

class Solution
{
    public:
        long long totalCost(vector<int> & costs, int k, int candidates)
        {
            long long result=0;

            int n=costs.size();

            priority_queue<int, vector<int>, greater<int>> leftMinHeap;

            priority_queue<int, vector<int>, greater<int>> rightMinHeap;

            int left=0;

            int right=n-1;

            while(k > 0)
            {
                while(leftMinHeap.size() < candidates and left <= right)
                {
                    leftMinHeap.emplace(costs[left]);

                    left+=1;
                }

                while(rightMinHeap.size() < candidates and right >= left)
                {
                    rightMinHeap.emplace(costs[right]);

                    right-=1;
                }

                int firstGroupCost=numeric_limits<int>::max();

                int secondGroupCost=numeric_limits<int>::max();

                if(!leftMinHeap.empty())
                {
                    firstGroupCost=leftMinHeap.top();
                }

                if(!rightMinHeap.empty())
                {
                    secondGroupCost=rightMinHeap.top();
                }

                if(firstGroupCost <= secondGroupCost)
                {
                    result+=firstGroupCost;

                    leftMinHeap.pop();
                }
                else if(secondGroupCost < firstGroupCost)
                {
                    result+=secondGroupCost;

                    rightMinHeap.pop();
                }

                k-=1;
            }

            return result;
        }
};