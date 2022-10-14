#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n) [where n is the length of ratings]
Space complexity: O(n)
*/

class Solution
{
    public:
        int candy(vector<int> & ratings)
        {
            int result=0;
            
            int n=ratings.size();
            
            //Vector used to keep track of how many candies each child gets
            //Intially, each child starts with one candy
            vector<int> candies(n, 1);
            
            //Iterat through the input vector from left-to-right
            for(int i=1;i<n;i++)
            {
                //If the current child has a higher rating than their left-neighbour
                if(ratings[i] > ratings[i - 1])
                {
                    //Increase the child's candy amount by how many candies their left-neighbour has plus one
                    candies[i]=candies[i - 1] + 1;
                }
            }
            
            //Iterate through the input vector from right-to-left
            for(int i=n-2;i>=0;i--)
            {
                //If the current child has a higher rating than their right neighbour
                if(ratings[i] > ratings[i + 1])
                {
                    //Here's the tricky part: as a result of the previous left-to-right traversal, there could be a situation where the current child has a higher rating than their neighbour to the right but has less candy. So, to handle this, we want to assign the current child the maximum candy value between how much the candy the child currently has or how much candy their righ neighbour has plus one.
                    candies[i]=max(candies[i], candies[i + 1] + 1);
                }
            }
            
            //Iterate through all the candy values and add each to the result
            for(int amount : candies)
            {
                result+=amount;
            }
            
            return result;
        }
};