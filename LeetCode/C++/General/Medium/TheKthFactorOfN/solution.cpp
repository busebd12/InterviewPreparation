#include <queue>
#include <vector>
using namespace std;

/*
Solution 1: maximum heap.

Time complexity: O(n * log(k))
Space complexity: O(k)
*/

class Solution
{
    public:
        int kthFactor(int n, int k)
        {
            int factor=1;

            priority_queue<int, vector<int>, less<int>> maxHeap;

            while(factor <= n)
            {
                if((n % factor)==0)
                {
                    maxHeap.emplace(factor);

                    if(maxHeap.size() > k)
                    {
                        maxHeap.pop();
                    }
                }

                factor+=1;
            }

            if(k > maxHeap.size())
            {
                return -1;
            }

            return maxHeap.top();
        }
};

/*
Solution 2: minimum heap.

Time complexity: O(n * log(f)) [where f is the total number of factors of n]
Space complexity: O(f)
*/

class Solution
{
    public:
        int kthFactor(int n, int k)
        {
            int result=0;
            
            int factor=1;

            priority_queue<int, vector<int>, greater<int>> minHeap;

            while(factor <= n)
            {
                if((n % factor)==0)
                {
                    minHeap.emplace(factor);
                }

                factor+=1;
            }

            if(k > minHeap.size())
            {
                return -1;
            }

            while(!minHeap.empty() && k > 0)
            {
                result=minHeap.top();
                
                minHeap.pop();
                
                k-=1;
            }
            
            return result;
        }
};

/*
Solution 3: ordering the factors using a vector.

Time complexity: O(n)
Space complexity: O(f) [where f is the total number of factors of n]
*/

class Solution
{
    public:
        int kthFactor(int n, int k)
        {
            int result=0;
            
            int factor=1;
            
            vector<int> factors;

            while(factor <= n)
            {
                if((n % factor)==0)
                {
                    factors.push_back(factor);
                }

                factor+=1;
            }

            if(k > factors.size())
            {
                return -1;
            }

            for(int index=0;k > 0 && index<factors.size();index++,k--)
            {
                result=factors[index];
            }
            
            return result;
        }
};

/*
Solution 4: just looping and keeping track of the kth factor as we go.

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
        int kthFactor(int n, int k)
        {
            int result=0;
            
            int factor=1;
            
            int count=0;

            while(factor <= n)
            {
                if((n % factor)==0)
                {
                    result=factor;
                    
                    count+=1;
                }
                
                if(count==k)
                {
                    return result;
                }

                factor+=1;
            }
            
            return -1;
        }
};