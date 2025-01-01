#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<long long> minimumCosts(vector<int> & regular, vector<int> & express, int expressCost)
        {
            vector<long long> result;

            int n=regular.size();

            result.resize(n, 0);

            long long previousRegularCost=0;

            long long previousExpressCost=expressCost;

            for(int i=0;i<n;i+=1)
            {
                //We rode the regular line from the previous stop to the current stop
                long long stayOnRegular=previousRegularCost + regular[i];

                //We rode the express line to get to the previous stop but switched to the regular line to ride to the current stop
                long long expressToRegular=previousExpressCost + regular[i];

                //We rode the express line from the previous stop to the current stop
                long long stayOnExpress=previousExpressCost + express[i];

                //We rode the regular line to get to the previous stop but switched to the express line to ride to the current stop
                long long regularToExpress=previousRegularCost + expressCost + express[i];

                long long minRegularCost=min(stayOnRegular, expressToRegular);

                long long minExpressCost=min(stayOnExpress, regularToExpress)

                result[i]=min(minRegularCost, minExpressCost);

                previousRegularCost=minRegularCost;

                previousExpressCost=minExpressCost;
            }

            return result;
        }
};