#include <algorithm>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

/*
Solution: see comments below.

Time complexity: O(p log p) [where p is the length of points]
Space complexity: O(p)

Intuition is as follows:

We are given the following equation yi + yj + |xi - xj| and we want to maximize the value for it.

Let's first re-write it as T=yi + yj + |xi - xj|

Next, define the following equalities

1) xi=points[i][0]
2) xj=points[j][0]
3) yi=points[i][1]
4) yj=points[j][1]

After substituting in the original equation appropriately, we have T=points[i][1] + points[j][1] + |points[i][0] - points[j][0]|

Let's look more closely at the |points[i][0] - points[i][1]| part.

Since the x-coordinates are sorted in increasing order and i < j, we know that the points[j][0] > points[i][0].

If we remove the absolute value sign, points[i][0] - points[j][0] will result in a negative value.

In order to turn this negative value into a positive one, we'll multiply by -1.

More formally, we re-write |points[i][0] - points[j][0]| as -(points[i][0] - points[j][0]).

Then, if we distribute the negative one, we have (-points[i][0] + points[j][0]).

Replacing the |points[i][0] - points[j][0]| with (-points[i][0] + points[j][0]) in our equation,

we have T=points[i][1] + points[j][1] + (-points[i][0] + points[j][0]).

After group like terms together, we have

T=points[j][1] + points[j][0] + (points[i][1] - points[i][0]).

Now, if we know the sum points[j][1] + points[j][0], then to maximize the value for T, we need to maximize the value of (points[i][1] - points[i][0]).

So, if we are at position j, for all positions i, where i=[1, j - 1], we need to know the largest possible value for (points[i][1] - points[i][0]).

Also, we need to check if points[j][0] - points[i][0] <= k.

Since we want to maximize the value of (points[i][1] - points[i][0]), we will use a max heap (priority_queue) of pairs,
where each pair in the heap is of the form {points[i][1] - points[i][0]), points[i][0]}.

Then, we simply do the following to get the answer:

Loop through all the points
    1) While the max heap is not empty and the difference between the current point's x-coordinate and the x-coordinate
    at the top of the heap is not less than or equal to k, remove the top heap element

    2) If the heap is not empty, then we have a maximum value (so far) for (points[i][1] - points[i][0]).
    So, we calculate the value for T=points[j][1] + points[j][0] + (points[i][1] - points[i][0]) and update
    our result variable if T > result.

    3) Calculate the value of (points[i][1] - points[i][0]) for the current point points[i]

    4) Add the pair {difference found in step 3, points[i][0]} to the max heap
*/

class Solution
{
    public:
        int findMaxValueOfEquation(vector<vector<int>> & points, int k)
        {
            int result=numeric_limits<int>::min();

            int p=points.size();

            priority_queue<pair<int, int>, vector<pair<int,int>>, less<pair<int, int>>> maxHeap;

            for(int i=0;i<p;i++)
            {
                while(!maxHeap.empty() and (points[i][0] - maxHeap.top().second) > k)
                {
                    maxHeap.pop();
                }

                if(!maxHeap.empty())
                {
                    int equationValue=points[i][0] + points[i][1] + maxHeap.top().first;

                    result=max(result, equationValue);
                }

                int difference=points[i][1] - points[i][0];

                maxHeap.emplace(difference, points[i][0]);
            }

            return result;
        }
};