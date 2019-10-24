#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
using namespace std;

/*
 * Approaches:
 *
 * 1) Do the following
 *
 * a) Add up the total number of candy bars in A
 * b) Add up the total number of candy bars in B
 * c) Half of the total of the two prior sums is the amount we want each person to have
 * d) For each candy bar value in A, if we gave it away, the amount we need in return is half the original
 * total number of candy bars minus the quantity of the total number of candy bars in A minus the value
 * of the candy bar we are trading. Calculate this value and map each candy bar amount to this value in a hashtable.
 * e) Do the same thing for each candy bar value in B.
 * f) For each candy bar amount in A's hashtable, check to see if the required amount we need from trading is in B's hashtable.
 * If it is, then we have our two answers.
 * g) After we are finished, return our vector<int> result.
 *
 * Time complexity: O(n + m) [where n is the length the vector<int> A and m is the length of the vector<int> B]
 * Space complexity: O(n + m)
 *
 *
 * 2) Same logic but we use a single unordered_set<int> instead of two unordered_map<int, int> because we only need
 * to store the candy bar values from B in our unordered_set<int>. We can calculate the amount we would need in return
 * for trading each of A's candy bar values as we go and don't need to store it.
 *
 * Time complexity: O(n + m) [where n is the length of the vector<int> A and m is the length of the vector<int> & B)
 * Space complexity: O(m)
 */

void populateHashtable(unordered_map<int, int> & hashtable, vector<int> & candyBars, int & candyAmount, int & half)
{
    for(const int & candy : candyBars)
    {
        if(!hashtable.count(candy))
        {
            int amountNeeded=(half - (candyAmount - candy));

            hashtable[candy]=amountNeeded;
        }
    }
}

vector<int> fairCandySwap(vector<int> & A, vector<int> & B)
{
    vector<int> result(2, 0);

    if(A.empty() || B.empty())
    {
        return result;
    }

    int aTotal=accumulate(A.begin(), A.end(), 0);

    int bTotal=accumulate(B.begin(), B.end(), 0);

    int totalCandy=aTotal + bTotal;

    int half=totalCandy/2;

    unordered_map<int, int> aHashtable;

    unordered_map<int, int> bHashtable;

    populateHashtable(aHashtable, A, aTotal, half);

    populateHashtable(bHashtable, B, bTotal, half);

    for(const auto & element : aHashtable)
    {
        if(bHashtable.count(element.second))
        {
            result[0]=element.first;

            result[1]=element.second;

            break;
        }
    }

    return result;
}

vector<int> fairCandySwap(vector<int> & A, vector<int> & B)
{
    vector<int> result(2, 0);

    if(A.empty() || B.empty())
    {
        return result;
    }

    int aTotal=accumulate(A.begin(), A.end(), 0);

    int bTotal=0;

    unordered_set<int> us;

    for(const int & amount : B)
    {
        bTotal+=amount;

        us.insert(amount);
    }

    int totalCandy=aTotal + bTotal;

    int half=totalCandy/2;

    for(const int & amount : A)
    {
        int target=(half - (aTotal - amount));

        if(us.count(target))
        {
            result[0]=amount;

            result[1]=target;

            break;
        }
    }

    return result;
}