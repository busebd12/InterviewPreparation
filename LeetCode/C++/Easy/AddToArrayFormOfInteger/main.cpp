#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Approach: similar to that of adding two numbers but with one of them being in array/vector form.
 * We iterating through each number from right-to-left and perform grade school addition (remembering to
 * deal with the carry value appropriately). There are some edge/corner cases we have to be aware of
 *
 * a) The two numbers do not have the same number of digits
 * b) One of the two numbers is zero
 *
 * Time complexity: O(n + m) [where is the length of the vector<int> A and m is the number of digits in the number K]
 * Space complexity: O(t) [where t is the total number of digits in our resulting sum]
 */

vector<int> addToArrayForm(vector<int> & A, int K)
{
    vector<int> result;

    if(A.empty())
    {
        return result;
    }

    int n=int(A.size());

    int i=n-1;

    int carry=0;

    int k=K;

    int digits=0;

    while(k > 0)
    {
        digits++;

        k/=10;
    }

    while(K > 0 && i >= 0)
    {
        int digit=K % 10;

        int total=(carry + A[i] + digit);

        if(total >= 10)
        {
            if(i==0 && digits==1)
            {
                while(total > 0)
                {
                    result.emplace_back(total % 10);

                    total/=10;
                }
            }
            else
            {
                carry=total/10;

                int remainder=total % 10;

                result.push_back(remainder);
            }
        }
        else
        {
            carry=0;

            result.push_back(total);
        }

        K/=10;

        i--;

        digits--;
    }

    while(i >= 0)
    {
        int total=(carry + A[i]);

        if(total >= 10)
        {
            if(i==0)
            {
                while(total > 0)
                {
                    result.emplace_back(total % 10);

                    total/=10;
                }
            }
            else
            {
                carry=total/10;

                int remainder=total % 10;

                result.push_back(remainder);
            }
        }
        else
        {
            carry=0;

            result.push_back(total);
        }

        i--;
    }

    if(K > 0)
    {
        int leftOver=K + carry;

        if(leftOver >= 10)
        {
            while(leftOver > 0)
            {
                result.emplace_back(leftOver % 10);

                leftOver/=10;
            }
        }
        else
        {
            result.push_back(leftOver);
        }
    }

    reverse(result.begin(), result.end());

    return result;
}