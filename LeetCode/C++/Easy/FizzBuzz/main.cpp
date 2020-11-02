#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * Approaches:
 *
 * 1) Fairly routine:
 *
 * a) If the number is divisible by five and three, add "FizzBuzz" to the vector
 * b) If the number is divisible by just three, add "Fizz" to the vector
 * c) If the number is divisible by just five, add "Buzz" to the vector
 * d) If the number is not divisible by three or five, add the string version of the number to the vector
 *
 * Time complexity: O(n) [where n is the input number]
 * Space complexity: O(n) [if we are counting the space needed by the result vector]
 *
 * 2) Same logic, just using two integers instead of the % operator
 *
 * Time complexity: O(n)
 * Space complexity: O(n) [again, if we are counting the space needed for the result vector]
 */

vector<string> fizzBuzz(int n)
{
    vector<string> result;

    if(n <= 0)
    {
        return result;
    }

    for(int number=1;number<=n;++number)
    {
        if(number%3==0 && number%5==0)
        {
            result.emplace_back("FizzBuzz");
        }
        else if(number%3==0)
        {
            result.emplace_back("Fizz");
        }
        else if(number%5==0)
        {
            result.emplace_back("Buzz");
        }
        else
        {
            result.push_back(to_string(number));
        }
    }

    return result;
}

vector<string> fizzBuzz(int n)
{
    vector<string> result;

    if(n <= 0)
    {
        return result;
    }

    int fizz=3;

    int buzz=5;

    for(int number=1;number<=n;++number)
    {
        if(number==fizz && number==buzz)
        {
            result.emplace_back("FizzBuzz");

            fizz+=3;

            buzz+=5;
        }
        else if(number==fizz)
        {
            result.emplace_back("Fizz");

            fizz+=3;
        }
        else if(number==buzz)
        {
            result.emplace_back("Buzz");

            buzz+=5;
        }
        else
        {
            result.push_back(to_string(number));
        }
    }

    return result;
}