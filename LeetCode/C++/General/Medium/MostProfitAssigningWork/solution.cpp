#include <algorithm>
#include <map>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n * log(n)) + O(u) + O(m * log(m))
[where n is the length of difficulty and profit, u is the unique number of job difficulties, and m is the length of worker]

Space complexity: O(u) [where u is the unique number of job difficulties]
*/

class Solution
{
    public:
        int maxProfitAssignment(vector<int> & difficulty, vector<int> & profit, vector<int> & worker)
        {
            int result=0;
            
            int n=profit.size();
            
            int m=worker.size();
            
            //Map each job difficulty to the maximum amount of profit for that difficulty level
            map<int, int> difficultyToProfits;
            
            for(int i=0;i<n;i++) //O(n) [where n is the length of difficulty and profit]
            {
                int d=difficulty[i];
                
                int p=profit[i];
                
                //Create the difficulty-to-profit mapping
                if(difficultyToProfits.find(d)==end(difficultyToProfits))
                {
                    difficultyToProfits.emplace(d, 0); //O(log(n))
                }
                
                difficultyToProfits[d]=max(p, difficultyToProfits[d]);
            }
            
            int maxJobProfit=0;
            
            //Here's the galactic brain moment: since each worker's ability is the maximum difficulty they can handle,
            //how do we account for the case where a lower difficulty job has a greater profit than a higher difficulty one?
            //The answer is we "bubble up" the max profit from all the jobs below a job with a certain difficulty level.
            //In other words, if there is a job with difficulty 90 and there are several jobs "below it", in terms of difficulty level, say, 85, 70, 63,
            //and one of these other three jobs has a greater profit, then we want to "bubble up" that larger profit so it appears like the job with difficulty
            //90 has that greater profit margin.
            for(auto & [difficultyLevel, jobProfit] : difficultyToProfits) //O(u) [where u is the unique number of job difficulty levels]
            {
                maxJobProfit=max(maxJobProfit, jobProfit);
                
                jobProfit=maxJobProfit;
            }
            
            //After we have "bubbled up" the maximum profit possible for each job difficulty,
            //we just need to iterate through each unique job difficulty and add the maximum profit to the result
            for(int w : worker) //O(m) [where m is the number of workers]
            {   
                //Use upper_bound (binary search) to find the job difficulty that is greater than the maximum the worker can handle
                auto itr=difficultyToProfits.upper_bound(w); //O(log(m))
                
                //If the iterator points to the beginning of the map,
                //then all the job difficulty values are greater than the w[i] and the worker can't complete any of the jobs
                if(itr!=begin(difficultyToProfits))
                {
                    //Move the iterator back so it points to the most difficult job the worker can complete
                    advance(itr, -1);
                    
                    int maxAmount=itr->second;
                    
                    //Add the max amount of profit possible to the result
                    result+=maxAmount;
                }
            }
            
            return result;
        }
};