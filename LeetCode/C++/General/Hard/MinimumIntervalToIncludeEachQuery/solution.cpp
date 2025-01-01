#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

/*
Time complexity: O(p + q + (q * log(q)) + (q * log(p))) [where p=length of intervals and q=length of queries]
Space complexity: O(p + q)
*/

class Solution
{
    public:
        vector<int> minInterval(vector<vector<int>> & intervals, vector<int> & queries)
        {
            vector<int> result;

            int intervalsSize=intervals.size();

            int q=queries.size();

            result.resize(q, -1);

            //Sort the intervals in increasing order by the start of each interval
            sort(intervals.begin(), intervals.end()); //O(p)

            //Store pairs of the form {query, index of the query}
            vector<pair<int, int>> queryIndexPairs;

            //Create the pairs
            for(int i=0;i<q;i++) //O(q)
            {
                queryIndexPairs.emplace_back(queries[i], i);
            }

            //Sort the pairs in increasing order based on the query value
            sort(queryIndexPairs.begin(), queryIndexPairs.end()); //O(q * log(q))

            //Minimum heap of pairs where each pair is of the form {length of interval, ending value of the interval}
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

            int n=queryIndexPairs.size();

            int intervalsIndex=0;

            //Iterate through all {query, index} pairs
            for(int i=0;i<n;i++) //O(q * log(p))
            {
                auto [query, index]=queryIndexPairs[i];

                //While there are still intervals to process and the start of the interval is less than or equal to the query
                //In other words, the query value can be included in this interval
                while(intervalsIndex < intervalsSize and intervals[intervalsIndex][0] <= query)
                {
                    int intervalBegin=intervals[intervalsIndex][0];

                    int intervalEnd=intervals[intervalsIndex][1];

                    int length=(intervalEnd - intervalBegin) + 1;

                    //Add the {interval length, interval ending value} pair to the minimum heap
                    minHeap.emplace(length, intervalEnd);

                    intervalsIndex+=1;
                }

                //While the minimum heap is not empty and the end of the range is less than the query value
                //In other words, the interval being removed from the heap cannot contain the query value
                while(!minHeap.empty() and minHeap.top().second < query)
                {
                    minHeap.pop();
                }

                //If the minimum heap is not empty, then there exists at least one interval range that contains the query value
                //Since we are using a minimum heap, the size of the smallest interval will be on top and this is the answer we want
                if(!minHeap.empty())
                {
                    int minimumIntervalLength=minHeap.top().first;

                    result[index]=minimumIntervalLength;
                }
            }

            return result;
        }
};