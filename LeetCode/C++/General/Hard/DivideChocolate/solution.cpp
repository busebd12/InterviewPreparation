#include <vector>
using namespace std;

/*
Solution: binary search.

Time complexity: O(n * log(s)) [where n=length of sweetness and s=sum of chunks of sweetness]
Space complexity: O(1)
*/

class Solution
{
    public:
        int maximizeSweetness(vector<int> & sweetness, int k)
        {
            int result=0;

            int n=sweetness.size();

            int minSweetness=numeric_limits<int>::max();

            int sum=0;

            for(int chunkSweetness : sweetness)
            {
                minSweetness=min(minSweetness, chunkSweetness);

                sum+=chunkSweetness;
            }

            //Bounds for our binary search
            int low=minSweetness;

            int high=sum;

            //Do binary search
            while(low <= high)
            {
                //The minimum possible sweetness that any of the k + 1 pieces can have
                int minPieceSweetness=(low + (high - low)/2);

                //If we can divide the chocolate bar into k + 1 pieces where each piece will have at least minPieceSweetness sweetness
                if(canDivide(sweetness, n, k, minPieceSweetness)==true)
                {
                    //Update our result
                    result=minPieceSweetness;
                    
                    //Since we want to maximize the minimum total sweetness, let's try a larger minPieceSweetness next time
                    low=minPieceSweetness + 1;
                }
                //Else, we weren't able to divide the chocolate bar into k + 1 pieces, so let's try with a smaller minPieceSweetness next time
                else
                {
                    high=minPieceSweetness - 1;
                }
            }

            return result;
        }

        bool canDivide(vector<int> & sweetness, int n, int k, int minPieceSweetness)
        {
            int pieces=0;

            int pieceSweetness=0;

            for(int chunkSweetness : sweetness)
            {
                pieceSweetness+=chunkSweetness;

                if(pieceSweetness >= minPieceSweetness)
                {
                    pieces+=1;

                    pieceSweetness=0;
                }
            }

            return pieces >= k+1;
        }
};