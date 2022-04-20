#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

class UndergroundSystem
{
    public:
        
        //Hashmap used to map id to station name and check-in time
        unordered_map<int, pair<string, int>> hashmap1;
    
        //Hashmap used to map a combination of the arrival and destination stations to travel times
        unordered_map<string, vector<int>> hashmap2;
    
        UndergroundSystem()
        {
            
        }

        void checkIn(int id, string stationName, int t)
        {
            hashmap1.emplace(id, make_pair(stationName, t));
        }

        void checkOut(int id, string stationName, int t)
        {   
            auto checkInItr=hashmap1.find(id);
            
            int arrivalTime=(checkInItr->second).second;
            
            string arrivalStation=(checkInItr->second).first;
            
            int travelTime=t - arrivalTime;
            
            string key=arrivalStation + "->" + stationName;
            
            hashmap2[key].emplace_back(travelTime);
            
            //IMPORTANT: erase traveler id from hashtable since they have checked-out
            hashmap1.erase(id);
        }

        double getAverageTime(string startStation, string endStation)
        {
            double result{};
            
            string key=startStation + "->" + endStation;
            
            double totalTravelTime=accumulate(begin(hashmap2[key]), end(hashmap2[key]), 0.0);
            
            result=static_cast<double>(totalTravelTime/hashmap2[key].size());
            
            return result;
        }
};