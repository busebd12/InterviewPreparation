#include <deque>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of arr]
Space complexity: O(n)
*/

class Solution
{
    public:
        bool canReach(vector<int> & arr, int start)
        {
            int n=arr.size();

            vector<bool> visited(n, false);

            deque<int> stack;

            stack.push_back(start);

            visited[start]=true;

            while(!stack.empty())
            {
                int current=stack.back();

                stack.pop_back();

                if(arr[current]==0)
                {
                    return true;
                }

                int forwardIndex=current + arr[current];

                if(forwardIndex >= 0 and forwardIndex < n and visited[forwardIndex]==false)
                {
                    visited[forwardIndex]=true;

                    stack.push_back(forwardIndex);
                }

                int backwardIndex=current - arr[current];

                if(backwardIndex >= 0 and backwardIndex < n and visited[backwardIndex]==false)
                {
                    visited[backwardIndex]=true;

                    stack.push_back(backwardIndex);
                }
            }

            return false;
        }
};