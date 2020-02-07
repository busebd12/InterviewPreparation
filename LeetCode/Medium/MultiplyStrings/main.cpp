#include <deque>
#include <iostream>
#include <string>

/*
 * Solution: we use the grade school multiplication algorithm.
 * Some bookeeping details to keep in mind:
 *
 * 1. Making sure we add the required number of padding zeroes to the end of the resulting rows when we multiply
 * a single digit from one number against all the digits from the other number.
 *
 * 2. Edge cases: when either one of the inputs is 1 or 0
 *
 * Time complexity: O(n * m) [where n is the length of num1 and m is the length of num2]
 * Space complexity: O(length of the smaller string)
 */

std::deque<int> add(std::deque<int> x, std::deque<int> y)
{
    if(x.empty())
    {
        return y;
    }

    if(y.empty())
    {
        return x;
    }

    int i=int(x.size()-1);

    int j=int(y.size()-1);

    std::deque<int> result;

    int carry=0;

    while(i >= 0 && j >= 0)
    {
        int total=carry + x[i] + y[j];

        carry=total/10;

        result.push_front(total % 10);

        if(i==0 && j==0 && carry > 0)
        {
            result.push_front(carry);
        }

        i--;

        j--;
    }

    while(i >= 0)
    {
        int total=carry + x[i];

        carry=total/10;

        result.push_front(total % 10);

        if(i==0 && carry > 0)
        {
            result.push_front(carry);
        }

        i--;
    }

    while(j >= 0)
    {
        int total=carry + y[j];

        carry=total/10;

        result.push_front(total % 10);

        if(j==0 && carry > 0)
        {
            result.push_front(carry);
        }

        j--;
    }

    return result;
}

std::string multiply(std::string num1, std::string num2)
{
    std::string result{};

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

    if(num1=="0" || num2=="0")
    {
        return "0";
    }

    if(num1=="1")
    {
        return num2;
    }

    if(num2=="1")
    {
        return num1;
    }

    std::deque<int> dq;

    std::string longer{};

    std::string shorter{};

    if(num1.size()==num2.size())
    {
        shorter=num1;

        longer=num2;
    }
    else if(num1.size() < num2.size())
    {
        shorter=num1;

        longer=num2;
    }
    else
    {
        shorter=num2;

        longer=num1;
    }

    int n=int(shorter.size());

    int m=int(longer.size());

    int zeroes=0;

    for(int i=n-1;i>=0;--i)
    {
        int carry=0;

        int x=shorter[i] - '0';

        std::deque<int> row;

        for(int count=0;count<zeroes;++count)
        {
            row.push_front(0);
        }

        for(int j=m-1;j>=0;--j)
        {
            int y=longer[j] - '0';

            int total=carry + (x  * y);

            carry=total/10;

            row.push_front(total % 10);
        }

        if(carry > 0)
        {
            row.push_front(carry);
        }

        dq=add(dq, row);

        zeroes++;
    }

    for(auto & digit : dq)
    {
        result+=char(digit + '0');
    }

    return result;
}