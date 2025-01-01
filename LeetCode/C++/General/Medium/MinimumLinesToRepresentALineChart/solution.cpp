#include <algorithm>
#include <vector>
using namespace std;

/*
Solution 1:

Time complexity: O(n log n) [where n is the length of stockPrices]
Space complexity: O(log(n)) [space needed for std::sort function]
*/

class Solution
{
    public:
        int minimumLines(vector<vector<int>> & stockPrices)
        {
            int result=0;

            int n=stockPrices.size();

            if(n==1)
            {
                return 0;
            }

            sort(stockPrices.begin(), stockPrices.end());

            result+=1;

            for(int i=1;i<n-1;i++)
            {
                long double x1=stockPrices[i - 1][0];

                long double y1=stockPrices[i - 1][1];

                long double x2=stockPrices[i][0];

                long double y2=stockPrices[i][1];

                long double x3=stockPrices[i + 1][0];

                long double y3=stockPrices[i + 1][1];

                long double slopeBetweenPointOneAndTwo=(long double)(y2 - y1) / (x2 - x1);

                long double slopeBetweenPointTwoAndThree=(long double)(y3 - y2) / (x3 - x2);

                if(slopeBetweenPointOneAndTwo!=slopeBetweenPointTwoAndThree)
                {
                    result+=1;
                }
            }

            return result;
        }
};


/*
Solution 2:

Time complexity: O(n log n) [where n is the length of stockPrices]
Space complexity: O(log(n)) [space needed for std::sort function]
*/

class Solution
{
    public:
        int minimumLines(vector<vector<int>> & stockPrices)
        {
            int result=0;

            int n=stockPrices.size();

            if(n==1)
            {
                return 0;
            }

            sort(stockPrices.begin(), stockPrices.end());

            result+=1;

            for(int i=1;i<n-1;i++)
            {
                long x1=stockPrices[i - 1][0];

                long y1=stockPrices[i - 1][1];

                long x2=stockPrices[i][0];

                long y2=stockPrices[i][1];

                long x3=stockPrices[i + 1][0];

                long y3=stockPrices[i + 1][1];

                long slope1=(x3 - x2) * (y2 - y1);

                long slope2=(y3 - y2) * (x2 - x1);

                if(slope1!=slope2)
                {
                    result+=1;
                }
            }

            return result;
        }
};