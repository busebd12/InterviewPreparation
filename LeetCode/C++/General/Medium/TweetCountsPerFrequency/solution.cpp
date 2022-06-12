#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TweetCounts
{
    private:
        unordered_map<string, int> frequencyToChunk;
    
        unordered_map<string, vector<int>> tweetToTimestamp;
    
    public:
        TweetCounts()
        {
            frequencyToChunk.emplace("minute", 60);
            
            frequencyToChunk.emplace("hour", 3600);
            
            frequencyToChunk.emplace("day", 86400);
        }

        void recordTweet(string tweetName, int time)
        {
            tweetToTimestamp[tweetName].emplace_back(time);
        }

        vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)
        {
            vector<int> result;
            
            int intervalStart=startTime;
            
            while(intervalStart <= endTime)
            {
                int intervalEnd=min(endTime, (intervalStart + frequencyToChunk[freq]) - 1);
                
                int count=0;
                
                for(int timestamp : tweetToTimestamp[tweetName])
                {
                    if(intervalStart <= timestamp && timestamp <= intervalEnd)
                    {
                        count+=1;
                    }
                }
                
                result.emplace_back(count);
                
                intervalStart=intervalEnd + 1;
            }
            
            return result;
        }
};