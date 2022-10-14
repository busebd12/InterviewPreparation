#include <sstream>
#include <string>
using namespace std;

/*
Time complexity: O(n) [where n is the length of expression]
Space complexity: O(n)
*/

class Solution
{
    public:
        string fractionAddition(string expression)
        {
            string result{};
            
            stringstream ss(expression);
            
            int firstNumerator=0;
            
            int firstDenominator=0;
            
            int secondNumerator=0;
            
            int secondDenominator=0;
            
            char op;
            
            ss >> firstNumerator;
            
            ss >> op;
            
            ss >> firstDenominator;
            
            while(ss >> secondNumerator)
            {
                ss >> op;
                
                ss >> secondDenominator;
                
                int combinedNumerator=(firstNumerator * secondDenominator) + (secondNumerator * firstDenominator);
                
                int combinedDenominator=firstDenominator * secondDenominator;
                
                int gcd=__gcd(abs(combinedNumerator), abs(combinedDenominator));
                
                firstNumerator=combinedNumerator / gcd;
                
                firstDenominator=combinedDenominator / gcd;
            }
            
            int lastGCD=__gcd(abs(firstNumerator), abs(firstDenominator));
            
            firstNumerator=firstNumerator / lastGCD;
            
            firstDenominator=firstDenominator / lastGCD;
            
            result.append(to_string(firstNumerator));
            
            result.push_back('/');
            
            result.append(to_string(firstDenominator));
            
            return result;
        }
};