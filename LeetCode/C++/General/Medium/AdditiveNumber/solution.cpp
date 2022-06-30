#include <string>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/additive-number/discuss/622466/C%2B%2B-or-Easy-to-understand
*/

class Solution
{
    public:
        bool isAdditiveNumber(string num)
        {
            int n=num.length();
            
            if(n < 3)
            {
                return false;
            }
            
            for(int i=0;i<n;i++)
            {
                string firstNumber=num.substr(0, i+1);

                if(firstNumber.size() > 1 and firstNumber[0]=='0')
                {
                    break;
                }

                for(int j=i + 1,length=1;j<n;j++,length++)
                {
                    string secondNumber=num.substr(i+1, length);

                    if(secondNumber.size() > 1 and secondNumber[0]=='0')
                    {
                        break;
                    }

                    long num1=stol(firstNumber);

                    long num2=stol(secondNumber);

                    string candidate="";

                    candidate.append(firstNumber);

                    candidate.append(secondNumber);
                    
                    int numbers=2;

                    while(candidate.length() < num.length())
                    {
                        long next=num1 + num2;

                        candidate.append(to_string(next));

                        num1=num2;

                        num2=next;
                        
                        numbers+=1;
                    }

                    if(numbers > 2 and candidate==num)
                    {
                        return true;
                    }
                }
            }
    
            return false;
        }
};