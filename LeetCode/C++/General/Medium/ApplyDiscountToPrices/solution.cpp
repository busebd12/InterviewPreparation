#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

/*
Time complexity: O(n) [where n is the length of sentence]
Space complexity: O(n)
*/

class Solution
{
    public:
        string discountPrices(string sentence, int discount)
        {
            string result="";

            int n=sentence.size();
    
            int i=0;
            
            while(i < n)
            {
                if(sentence[i]=='$' and ((i > 0 and isspace(sentence[i - 1])) or i==0))
                {
                    string price="";
                    
                    int j=i + 1;
                    
                    while(j < n and !isspace(sentence[j]))
                    {
                        price.push_back(sentence[j]);
                        
                        j+=1;
                    }
                    
                    result.push_back('$');
                    
                    if(isValidPrice(price)==true)
                    {
                        string newPrice=applyDiscount(price, discount);
                        
                        result.append(newPrice);
                    }
                    else
                    {
                        result.append(price);
                    }
                    
                    i=j;
                }
                else
                {
                    result.push_back(sentence[i]);
                    
                    i+=1;
                }
            }

            return result;
        }

        bool isValidPrice(string & price)
        {
            auto itr=find_if(price.begin(), price.end(), [] (char & c) {return !isdigit(c);});
            
            return !price.empty() and itr==price.end();
        }

        string applyDiscount(string & price, int discount)
        {
            double numerator=discount;
            
            double denominator=100;
            
            double quotient=numerator / denominator;
            
            double original=stod(price);
            
            double discounted=original * quotient;
            
            original-=discounted;
            
            stringstream ss;
            
            ss << fixed << setprecision(2) << original;
            
            return ss.str();
        }
};