#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(3 log 3) --> O(1)
Space complexity: O(3) --> O(1)
*/

class Solution
{
    public:
        vector<int> numMovesStones(int a, int b, int c)
        {
            vector<int> result(2, 0);
            
            vector<int> stones={a, b, c};
            
            //Sort the stones in ascending order
            sort(begin(stones), end(stones));
            
            int minPosition=stones[0];
            
            int middlePosition=stones[1];

            int maxPosition=stones[2];
            
            //If all three stones are already in consecutive order, then we can't make any moves
            if(minPosition + 1==middlePosition and middlePosition + 1==maxPosition)
            {
                return result;
            }
            
            int maxMoves=(maxPosition - minPosition) - 2;
            
            result[1]=maxMoves;
            
            int minMoves=2;
            
            //If there is a gap of one position between the first and second stone or second and third stone, then just one move is necessary
            if(middlePosition - minPosition < 3 or maxPosition - middlePosition < 3)
            {
                minMoves=1;
            }
            
            result[0]=minMoves;
            
            return result;
        }
};