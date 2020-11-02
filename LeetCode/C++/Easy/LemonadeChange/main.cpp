#include <iostream>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) While looping over the bills vector, we have three cases to consider:
 *
 * a) If the customer pays with a five dollar bill, then no change is given and we can increment the number of five dollar bills we have.
 * b) If the customer pays with a ten dollar bill, then, as long as we have at least one five dollar bill, we can give the appropriate change.
 * c) If the customer pays with a twenty dollar bill, then we have two options - make change with a one $5 and one $10 or with three $5.
 * Since the $5 dollar bills are used no matter which option we pick, they are more valuable/versatile, and we want to be conservative about using them.
 * Hence, if we have the option to, we want to choose making change with one $10 and one $5. If this is not possible, then make change using three $5.
 * After successfully making change, increment the amount of bills the customer paid with. If we cannot make change, return false.
 * We use vector<int> hashtable to keep track of the amount of different types of bills we have.
 *
 * Time complexity: O(n) [where n is the size of vector<int> & bills]
 * Space complexity: O(1) [we only need 21 spots in our vector<int> hashtable, a constant value]
 *
 *
 * 2) Exactly the same logic, except that we only need three variables to keep track of the amount of five, ten, and twenty
 * dollar bills we have since we are only keeping track of three items, not 21.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

bool lemonadeChange(vector<int> & bills)
{
    if(bills.empty())
    {
        return false;
    }

    int n=int(bills.size());

    vector<int> hashtable(21, 0);

    for(int i=0;i<n;++i)
    {
        if(bills[i]==5)
        {
            hashtable[bills[i]]++;
        }
        else if(bills[i]==10)
        {
            if(hashtable[5]==0)
            {
                return false;
            }
            else
            {
                hashtable[5]--;

                hashtable[bills[i]]++;
            }
        }
        else
        {
            if(hashtable[5] > 0 && hashtable[10] > 0)
            {
                hashtable[5]--;

                hashtable[10]--;

                hashtable[bills[i]]++;
            }
            else if(hashtable[5] >= 3 && hashtable[10]==0)
            {
                hashtable[5]-=3;

                hashtable[bills[i]]++;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

bool lemonadeChange(vector<int> & bills)
{
    if(bills.empty())
    {
        return false;
    }

    int n=int(bills.size());

    int fives=0;

    int tens=0;

    int twenties=0;

    for(int i=0;i<n;++i)
    {
        if(bills[i]==5)
        {
            fives++;
        }
        else if(bills[i]==10)
        {
            if(fives==0)
            {
                return false;
            }
            else
            {
                fives--;

                tens++;
            }
        }
        else
        {
            if(fives > 0 && tens > 0)
            {
                fives--;

                tens--;

                twenties++;
            }
            else if(fives >= 3 && tens==0)
            {
                fives-=3;

                twenties++;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}