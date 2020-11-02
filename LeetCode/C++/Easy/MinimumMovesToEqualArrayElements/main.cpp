#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
Approach: Incrementing all but one element is equivalent to decrementing that one element. So let's do that instead.
How many single-element decrements to make all equal? No point to decrementing below the current minimum.
If we did that, then we would have to then make more moves by changing the minimum value
(since it would no longer be the minimum) and we can't change all values in the array at once, just all but one.
So how many single-element decrements to make all equal to the current minimum?
Just find the minimum and for each element add the difference between the current element
and the minimum to the total moves.

Time complexity: O(n) [where n is the total number of elements in the input vector]
Space complexity: O(1)
*/

int minMoves(vector<int>& nums)
{
    int moves=0;

    int minimum=*(min_element(nums.begin(), nums.end()));

    for(int number : nums)
    {
        moves+=number-minimum;
    }

    return moves;
}