#include <iostream>
#include <cmath>
using namespace std;

/*
 First approach: convert the number to a string, reverse the string, and convert the string back to an integer.

 Time Complexity: O(number of digits)

 Space Complexity: O(number of digits)
 */
int reverse(int x)
{
    bool negative=(x < 0) ? true : false;

    string xAsString=to_string(x);

    std::reverse(xAsString.begin(), xAsString.end());

    long int answer=stol(xAsString);

    if(negative)
    {
        answer*=-1;
    }

    return (answer > numeric_limits<int>::max() || answer < numeric_limits<int>::min()) ? 0 : answer;
}

/*
 Second approach: loop through the digits of the integer and create the reverse of the number

 Time Complexity: O(number of digits)

 Space Complexity: O(number of digits)
 */
int getDigits(int x)
{
    int number=x;

    int digits=0;

    while(number)
    {
        number/=10;

        digits++;
    }

    return digits;
}

int reverse(int x)
{
    long int answer=0;

    int digits=getDigits(x);

    long int place=pow(10, digits-1);

    while(x)
    {
        int digit=x % 10;

        long int total=(digit * place);

        answer+=total;

        x/=10;

        place/=10;
    }

    return (answer > numeric_limits<int>::max() || answer < numeric_limits<int>::min()) ? 0 : answer;
}

int main()
{
    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}