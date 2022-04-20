#include <cmath>
#include <queue>
#include <vector>
using namespace std;

/*
Solution: minimum heap + custom comparator

Time complexity: O((n log n) + (k log n) + (k log k))
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<int> findClosestElements(vector<int> & arr, int k, int x)
        {
            vector<int> result;
            
            auto likeThis=[&x] (int & a, int & b)
            {
                return ((abs(a - x) > abs(b - x)) || (abs(a - x)==abs(b - x) && a > b));
            };
            
            priority_queue<int, vector<int>, decltype(likeThis)> minHeap(likeThis);
            
            for(int & number : arr)
            {
                minHeap.emplace(number);
            }
            
            while(!minHeap.empty() && k > 0)
            {
                result.emplace_back(minHeap.top());
                
                minHeap.pop();
                
                k-=1;
            }
            
            sort(begin(result), end(result));
            
            return result;
        }
};


/*
Solution: maximum heap + custom comparator

Time complexity: O((n log n) + k + (k log k))
Space complexity: O(k)
*/

class Solution
{
    public:
        vector<int> findClosestElements(vector<int> & arr, int k, int x)
        {
            vector<int> result;
            
            auto likeThis=[&x] (int & a, int & b)
            {
                return ((abs(a - x) < abs(b - x)) || (abs(a - x)==abs(b - x) && a < b));
            };
            
            priority_queue<int, vector<int>, decltype(likeThis)> maxHeap(likeThis);
            
            for(int & number : arr)
            {
                maxHeap.emplace(number);
                
                if(maxHeap.size() > k)
                {
                    maxHeap.pop();
                }
            }
            
            while(!maxHeap.empty())
            {
                result.emplace_back(maxHeap.top());
                
                maxHeap.pop();
            }
            
            sort(begin(result), end(result));
            
            return result;
        }
};

/*
Solution: see comments.

Time complexity: O(log(n) + k) [where n is the length of arr]
Space complexity: O(k)
*/

class Solution
{
    public:
        vector<int> findClosestElements(vector<int>& arr, int k, int x)
        {
            vector<int> result;
            
            int n=arr.size();
            
            int low=0;
            
            int high=n-1;
            
            int left=-1;
            
            int right=-1;
            
            //Find the index of the first number that is greater than or equal to x
            //This will be the right end of the group of k numbers
            while(low <= high)
            {
                int middle=(low + (high - low)/2);
                
                if(arr[middle]==x)
                {
                    low=middle;
                    
                    break;
                }
                else if(arr[middle] > x)
                {
                    high=middle - 1;
                }
                else
                {
                    low=middle + 1;
                }
            }
            
            //Right end of our window of k numbers
            right=low;
            
            //Left end of our window of k numbers
            left=right - 1;
            
            //Deque that will hold the desired k closest numbers in sorted order
            deque<int> numbers;
            
            //While we haven't found k numbers
            while(k > 0)
            {
                if(left >= 0 && right <= n-1)
                {
                    //If the number to the left is closer to x than the number to the right
                    if(x-arr[left] <= arr[right]-x)
                    {
                        numbers.emplace_front(arr[left]);
                        
                        left-=1;
                    }
                    //Else, the number to the right is closer to x than the number to the left
                    else
                    {
                        numbers.emplace_back(arr[right]);
                        
                        right+=1;
                    }
                }
                //If left has reached index 0
                else if(right <= n-1)
                {
                    numbers.emplace_back(arr[right]);
                    
                    right+=1;
                }
                //Right has reached the last index in the array
                else if(left >= 0)
                {
                    numbers.emplace_front(arr[left]);
                    
                    left-=1;
                }
                
                k-=1;
            }
            
            //Move the numbers from the deque into our result vector
            while(!numbers.empty())
            {
                result.emplace_back(numbers.front());
                
                numbers.pop_front();
            }
            
            return result;
        }
};