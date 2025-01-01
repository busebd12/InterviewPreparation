#include <vector>
using namespace std;

/*
Time complexity: O(n * log(d)) [where n is the length of stations and d is the max difference between original gas stations]
Space complexity: O(1)
*/

class Solution
{
    public:
        double minmaxGasDist(vector<int> & stations, int k)
        {
            double result=0;

            int n=stations.size();

            double maxDifference=getMaxDifference(stations, n);

            double low=0;

            double high=maxDifference;

            //Since answers within 10^-6 will be accepted, use 10^-6 as our increment/decrement within the binary search instead of 1 (which we would normally use)
            double delta=1e-6;

            //Do binary search
            while(low <= high)
            {
                double penalty=(low + (high - low) / 2);

                //We can fit k new gas stations between existing stations such with current penalty value
                if(isPossible(stations, n, k, penalty)==true)
                {
                    //Set result equal to the lowest penalty value so far
                    result=penalty;

                    //Since we were able to add k additional gas stations such that the difference between then is penalty,
                    //decrement high so we can try again with a lower penalty value on the next iteration
                    high=penalty - delta;
                }
                else
                {
                    //We needed more than k additional gas stations to achieve the distance between gas stations of penalty,
                    //so increase low to get us a higher penalty value next time
                    low=penalty + delta;
                }
            }

            return result;
        }

        double getMaxDifference(vector<int> & stations, int n)
        {
            double maxDifference=0;

            for(int i=1;i<n;i++)
            {
                double difference=double(stations[i]) - double(stations[i - 1]);

                if(difference > maxDifference)
                {
                    maxDifference=difference;
                }
            }

            return maxDifference;
        }

        bool isPossible(vector<int> & stations, int n, int k, double penalty)
        {
            int gasStationsNeeded=0;
            
            for(int i=1;i<n;i++)
            {
                int difference=stations[i] - stations[i - 1];

                int gasStationsThatCanFit=int(difference / penalty);

                gasStationsNeeded+=gasStationsThatCanFit;
            }

            return gasStationsNeeded <= k;
        }
};