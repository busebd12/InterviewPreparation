#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

/*
Time complexity: O(d) [where d is the total number of digits in num]
Space complexity: O(d)
*/

class Solution
{
    public:
        int maxDiff(int num)
        {
            int result=0;

            int a=num;
    
            int b=num;
            
            deque<int> aDigits;
            
            while(a > 0)
            {
                int digit=a % 10;
                
                aDigits.push_front(digit);
                
                a=a / 10;
            }
            
            auto itr=find_if(begin(aDigits), end(aDigits), [] (int & digit) {return digit!=9;});
            
            if(itr!=aDigits.end())
            {
                int digitToReplace=*(itr);
                
                for(int & digit : aDigits)
                {
                    if(digit==digitToReplace)
                    {
                        digit=9;
                    }
                }
            }
            
            deque<int> bDigits;
            
            while(b > 0)
            {
                int digit=b % 10;
                
                bDigits.push_front(digit);
                
                b=b / 10;
            }
            
            if(bDigits[0]==1)
            {
                auto itr=find_if(begin(bDigits), end(bDigits), [] (int & digit) {return digit!=1 and digit!=0;});
                
                if(itr!=end(bDigits))
                {
                    int digitToReplace=*(itr);
                    
                    for(int & digit : bDigits)
                    {
                        if(digit==digitToReplace)
                        {
                            digit=0;
                        }
                    }
                }
            }
            else
            {
                int digitToReplace=bDigits[0];
                
                for(int & digit : bDigits)
                {
                    if(digit==digitToReplace)
                    {
                        digit=1;
                    }
                }
            }
            
            a=convertDigitsToNumber(aDigits);
            
            b=convertDigitsToNumber(bDigits);
            
            int difference=a - b;

            result=difference;

            return result;
        }

        int convertDigitsToNumber(deque<int> & digits)
        {
            int number=0;
            
            int d=digits.size();
            
            int exponent=0;
            
            for(int i=d-1;i>=0;i--)
            {
                int powerOfTen=pow(10, exponent);
                
                int placeValue=powerOfTen * digits[i];
                
                number+=placeValue;
                
                exponent+=1;
            }
            
            return number;
        }
};