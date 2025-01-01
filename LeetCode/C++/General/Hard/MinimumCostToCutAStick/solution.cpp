#include <algorithm>
#include <limits>
#include <map>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
    public:
        int minCost(int n, vector<int> & cuts)
        {
            int result=0;

            int left=0;

            int right=n;

            int index=0;

            result=helper(cuts, n, left, right, index);

            return result;
        }

        int helper(vector<int> & cuts, int n, int left, int right, int index)
        {
            if(index==cuts.size())
            {
                return 0;
            }

            if(left >= right)
            {
                return 0;
            }

            int cost=right - left;

            int subproblemSolution=numeric_limits<int>::max();

            for(int position : cuts)
            {   
                if(left < position and position < right)
                {
                    int leftHalfCutCost=helper(cuts, n, left, position, index + 1);

                    int rightHalfCutCost=helper(cuts, n, position, right, index + 1);

                    int total=cost + leftHalfCutCost + rightHalfCutCost;

                    subproblemSolution=min(subproblemSolution, total);
                }
            }

            if(subproblemSolution==numeric_limits<int>::max())
            {
                return 0;
            }

            return subproblemSolution;
        }
};

class Solution
{
    private:
        map<pair<int, int>, int> hashmap;
    
    public:
        int minCost(int n, vector<int> & cuts)
        {
            int result=0;

            int left=0;

            int right=n;

            int index=0;

            result=helper(cuts, n, left, right, index);

            return result;
        }

        int helper(vector<int> & cuts, int n, int left, int right, int index)
        {
            if(index==cuts.size())
            {
                return 0;
            }

            if(left >= right)
            {
                return 0;
            }

            pair<int, int> key(left, right);

            if(hashmap.find(key)!=hashmap.end())
            {
                return hashmap[key];
            }

            int cost=right - left;

            int subproblemSolution=numeric_limits<int>::max();

            for(int position : cuts)
            {   
                if(left < position and position < right)
                {
                    int leftHalfCutCost=helper(cuts, n, left, position, index + 1);

                    int rightHalfCutCost=helper(cuts, n, position, right, index + 1);

                    int total=cost + leftHalfCutCost + rightHalfCutCost;

                    subproblemSolution=min(subproblemSolution, total);
                }
            }

            subproblemSolution=(subproblemSolution==numeric_limits<int>::max() ? 0 : subproblemSolution);

            hashmap[key]=subproblemSolution;

            return subproblemSolution;
        }
};