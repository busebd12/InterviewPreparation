#include <iostream>
#include <string>
using namespace std;

/*
 * Approach: the way we add numbers on paper in base 10.
 *
 * Time complexity: O(m + n) [where m is the size of num1 and n is the size of num2]
 * Space complexity: O(length of the sum of num1 and num2)
 */

string addStrings(string & num1, string & num2)
{
    string result{};

    if(num1.empty() && num2.empty())
    {
        return result;
    }

    if(num1.empty())
    {
        return num2;
    }

    if(num2.empty())
    {
        return num1;
    }

    if((num1[0]=='0' && num1.size() > 1) || (num2[0]=='0' && num2.size() > 1))
    {
        return result;
    }

    if(num1[0]=='-' || num2[0]=='-')
    {
        return result;
    }

    int i=int(num1.size())-1;

    int j=int(num2.size())-1;

    int carry=0;

    while(i >= 0 && j >= 0)
    {
        int total=num1[i] - '0' + num2[j] - '0' + carry;

        if(i==0 && j==0)
        {
            result=to_string(total) + result;
        }
        else
        {
            if(total >= 10)
            {
                carry=total/10;
            }
            else
            {
                carry=0;
            }

            result=to_string(total%10) + result;
        }

        i--;

        j--;
    }

    if(i >= 0)
    {
        for(int index=i;index>=0;--index)
        {
            int total=num1[index] - '0' + carry;

            if(index==0)
            {
                result=to_string(total) + result;
            }
            else
            {
                if(total >= 10)
                {
                    carry=total/10;
                }
                else
                {
                    carry=0;
                }

                result=to_string(total%10) + result;
            }
        }
    }

    if(j >= 0)
    {
        for(int index=j;index>=0;--index)
        {
            int total=num2[index] - '0' + carry;

            if(index==0)
            {
                result=to_string(total) + result;
            }
            else
            {
                if(total >= 10)
                {
                    carry=total/10;
                }
                else
                {
                    carry=0;
                }

                result=to_string(total%10) + result;
            }
        }
    }

    return result;
}