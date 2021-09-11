#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * Approach: Loop over the ops vector and
 *
 * if the operation is "+", add the two previous scores to the sum and add the sum of the two last numbers to the values vector
 * if the operation is "C", subtract the previous score from the sum and remove the previous score from the values vector
 * if the operation is "D", add twice the last score in the values vector to the sum and to the values vector
 * if the operations is a number, add it to the score and to the values vector
 *
 * Time complexity: O(n) [where n is the length of input vector]
 * Space complexity: O(n)
 */

int calPoints(vector<string> & ops)
{
    int sum=0;

    if(ops.empty())
    {
        return sum;
    }

    vector<int> values;

    for(string & str : ops)
    {
        if(str=="+")
        {
            if(!values.empty() && values.size() >= 2)
            {
                int twoSum=values.back() + (*(values.rbegin() + 1));

                sum+=twoSum;

                values.push_back(twoSum);
            }
        }
        else if(str=="C")
        {
            if(!values.empty())
            {
                sum-=values.back();

                values.pop_back();
            }
        }
        else if(str=="D")
        {
            if(!values.empty())
            {
                int twiceTheLast=2 * values.back();

                sum+=twiceTheLast;

                values.push_back(twiceTheLast);
            }
        }
        else
        {
            int score=stoi(str);

            sum+=score;

            values.push_back(score);
        }
    }

    return sum;
}