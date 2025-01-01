#include <set>
#include <vector>
using namespace std;

class SummaryRanges
{
    private:
        set<int> stream;
    
    public:
        SummaryRanges()
        {
            
        }
        
        void addNum(int value) //O(log(s)) [where s=size of the data stream]
        {   
            stream.insert(value);
        }
        
        vector<vector<int>> getIntervals() //O(s) [where s=size of the data stream]
        {
            vector<vector<int>> intervals;

            if(stream.empty())
            {   
                return intervals;
            }

            for(auto itr=stream.begin();itr!=stream.end();itr++)
            {
                int number=*itr;

                if(intervals.empty())
                {
                    intervals.push_back({number, number});
                }
                else
                {
                    if(number==(intervals.back().back() + 1))
                    {
                        intervals.back().back()=number;
                    }
                    else
                    {
                        intervals.push_back({number, number});
                    }
                }
            }

            return intervals;
        }
};