#include <string>
#include <unordered_map>
#include <vector>

class LogSystem
{
    private:
        unordered_map<string, int> granularityToLength;
    
        vector<string> timestamps;
    
        vector<int> ids;
    
    public:
        LogSystem()
        {
            granularityToLength.emplace("Year", 4);
            
            granularityToLength.emplace("Month", 7);
            
            granularityToLength.emplace("Day", 10);
            
            granularityToLength.emplace("Hour", 13);
            
            granularityToLength.emplace("Minute", 16);
            
            granularityToLength.emplace("Second", string::npos);
        }

        //Time complexity: O(1)
        void put(int id, string timestamp)
        {
            ids.push_back(id);
            
            timestamps.push_back(timestamp);
        }

        //Time complexity: O(n * l) [where n is the total number of timestamps and l is the average length of a timestamp]
        vector<int> retrieve(string start, string end, string granularity)
        {
            vector<int> result;
            
            int length=granularityToLength[granularity];
            
            //Truncate the start timestamp appropriately
            string startPrefix=start.substr(0, length);
            
            //Truncate the end timestamp in the sammer manner as the start timestamp
            string endPrefix=end.substr(0, length);
            
            for(int index=0;index<timestamps.size();index++)
            {
                //Truncate the current timestamp in the same way that we truncated the start and end timestamps
                string timestampPrefix=timestamps[index].substr(0, length);
                
                //Since each part of the timestamp is zero-padded, we can just compare the string timestamps directly without having to do any fancy manipulation
                if(startPrefix <= timestampPrefix && timestampPrefix <= endPrefix)
                {
                    result.emplace_back(ids[index]);
                }
            }
            
            return result;
        }
};