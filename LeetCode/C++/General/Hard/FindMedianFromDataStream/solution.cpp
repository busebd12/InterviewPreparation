#include <queue>
#include <set>
using namespace std;

/*
Solution 1: using multiset<double>. Note, this solution receives Time Limit Exceeded when ran.
*/

class MedianFinder
{
    private:
        multiset<double> stream;
    
    public:
        MedianFinder()
        {
            
        }
        
        void addNum(int num) //O(log(n))
        {
            stream.insert(num);
        }
        
        double findMedian() //O(n/2)
        {
            double result=0.0;

            int streamSize=stream.size();

            if((streamSize % 2)==1)
            {
                auto itr=stream.begin();

                advance(itr, streamSize/2);

                result=*itr;
            }
            else
            {
                int firstMiddle=(streamSize / 2) - 1;
                
                int secondMiddle=streamSize / 2;
                
                auto itr=stream.begin();
                
                advance(itr, firstMiddle);
                
                auto itr2=stream.begin();
                
                advance(itr2, secondMiddle);

                result=(double)(*itr + *itr2)/2;
            }

            return result;
        }
};

/*
Solution 2: inspired by this post --> https://leetcode.com/problems/find-median-from-data-stream/solutions/74163/my-c-priority-queue-based-solution-140-ms/
*/

class MedianFinder
{
    private:
        priority_queue<double, vector<double>, less<double>> smallerHalf;

        priority_queue<double, vector<double>, greater<double>> largerHalf;
    
    public:
        MedianFinder()
        {
            
        }
        
        void addNum(int num) //O(log(n))
        {
            if(smallerHalf.empty() or smallerHalf.top() > num)
            {
                smallerHalf.emplace(num);
            }
            else
            {
                largerHalf.emplace(num);
            }

            if(largerHalf.size() > smallerHalf.size() + 1)
            {
                smallerHalf.emplace(largerHalf.top());

                largerHalf.pop();
            }
            else if(smallerHalf.size() > largerHalf.size() + 1)
            {
                largerHalf.emplace(smallerHalf.top());

                smallerHalf.pop();
            }

        }
        
        double findMedian() //O(1)
        {
            double result=0.0;

            if(smallerHalf.size()==largerHalf.size())
            {
                result=(double)(smallerHalf.top() + largerHalf.top())/2.0;
            }
            else if(smallerHalf.size() > largerHalf.size())
            {
                result=smallerHalf.top();
            }
            else
            {
                result=largerHalf.top();
            }

            return result;
        }
};