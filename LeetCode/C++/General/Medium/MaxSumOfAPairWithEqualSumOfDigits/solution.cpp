#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

/*
Solution 1: use a hashmap (vector of multisets) to group numbers by their digit sums.
Then, the max sum for each digit sum will be the largest two numbers for that digit sum

Time complexity: O(n * log(n))
Space complexity: O(n)
*/

class Solution
{
    public:
        int maximumSum(vector<int> & nums)
        {
            int result=-1;

            int n=nums.size();

            vector<multiset<int>> hashmap(82, multiset<int>());

            for(int i=0;i<n;i++) //O(n)
            {
                int number=nums[i];

                int copy=number;

                int digitSum=0;

                while(copy > 0)
                {
                    int digit=copy % 10;

                    digitSum+=digit;

                    copy=copy / 10;
                }

                hashmap[digitSum].insert(number); //O(log(n))
            }

            for(int digitSum=1;digitSum<82;digitSum++) //O(81)
            {
                if(!hashmap[digitSum].empty() and hashmap[digitSum].size() > 1)
                {
                    auto lastNumberItr=hashmap[digitSum].end();

                    lastNumberItr--;

                    int largest=*(lastNumberItr);

                    lastNumberItr--;

                    int secondLargest=*(lastNumberItr);

                    int sum=largest + secondLargest;

                    result=max(result, sum);
                }
            }

            return result;
        }
};

/*
Solution 1: use a hashmap (vector of priority_queues [max heaps]) to group numbers by their digit sums.
Then, the max sum for each digit sum will be the largest two numbers for that digit sum

Time complexity: O(n * log(n))
Space complexity: O(n)
*/

class Solution
{
    public:
        int maximumSum(vector<int> & nums)
        {
            int result=-1;

            int n=nums.size();

            vector<priority_queue<int, vector<int>, less<int>>> hashmap(82, priority_queue<int, vector<int>, less<int>>());

            for(int i=0;i<n;i++) //O(n)
            {
                int number=nums[i];

                int copy=number;

                int digitSum=0;

                while(copy > 0)
                {
                    int digit=copy % 10;

                    digitSum+=digit;

                    copy=copy / 10;
                }

                hashmap[digitSum].emplace(number); //O(log(n))
            }

            for(int digitSum=1;digitSum<82;digitSum++) //O(81)
            {
                if(!hashmap[digitSum].empty() and hashmap[digitSum].size() > 1)
                {
                    int largest=hashmap[digitSum].top();

                    hashmap[digitSum].pop();

                    int secondLargest=hashmap[digitSum].top();

                    hashmap[digitSum].pop();

                    int sum=largest + secondLargest;

                    result=max(result, sum);
                }
            }

            return result;
        }
};