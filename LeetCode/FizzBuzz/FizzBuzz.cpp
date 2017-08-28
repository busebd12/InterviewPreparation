#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fizzBuzz(int n)
{
    vector<string> answer;
    
    for(int number=1;number<=n;++number)
    {
        if(number%3==0 && number%5==0)
        {
            answer.emplace_back("FizzBuzz");
        }
        else if(number%3==0)
        {
            answer.emplace_back("Fizz");
        }
        else if(number%5==0)
        {
            answer.emplace_back("Buzz");
        }
        else
        {
            answer.emplace_back(to_string(number));
        }
    }
    
    return answer;
}