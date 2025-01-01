#include <string>
using namespace std;

/*
Time complexity: O(n + m) [where n is the length of num1 and m is the length of num2]
Space complexity: O(n + m)
*/

class Solution
{
    public:
        string complexNumberMultiply(string num1, string num2)
        {
            string result="";

            auto num1PlusIndex=num1.find('+');

            auto num1IIndex=num1.find('i');

            int a=stoi(num1.substr(0, num1PlusIndex));

            int b=stoi(num1.substr(num1PlusIndex + 1, num1IIndex));

            auto num2PlusIndex=num2.find('+');

            auto num2IIndex=num2.find('i');

            int c=stoi(num2.substr(0, num2PlusIndex));

            int d=stoi(num2.substr(num2PlusIndex + 1, num2IIndex));

            int first=a * c;

            int outter=a * d;

            int inner=b * c;

            int last=b * d * -1;

            int real=first + last;

            int imaginary=outter + inner;

            result.append(to_string(real));

            result.push_back('+');

            result.append(to_string(imaginary));

            result.push_back('i');

            return result;
        }
};