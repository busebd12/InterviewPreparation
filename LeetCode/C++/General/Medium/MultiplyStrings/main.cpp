#include <deque>
#include <iostream>
#include <string>
using namespace std;

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

class Solution
{
    public:
        void helper(deque<deque<int>> & products, int n, string num1, char digit, int zeros)
        {
            deque<int> product;
            
            for(int count=0;count<zeros;count++)
            {
                product.emplace_front(0);
            }
            
            int carry=0;
            
            for(int i=n-1;i>=0;i--)
            {
                int digit1=num1[i] - '0';
                
                int digit2=digit - '0';
                
                int total=carry + (digit1 * digit2);
                
                product.emplace_front(total % 10);
                
                carry=total / 10;
            }
            
            if(carry > 0)
            {
                product.emplace_front(carry);
            }
            
            products.push_back(product);
        }
        
        string multiply(string num1, string num2)
        {
            string result{};
            
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
            
            deque<deque<int>> products;
            
            int zeros=0;
            
            int n=num1.size();
            
            int m=num2.size();
            
            for(int j=m-1;j>=0;j--)
            {   
                helper(products, n, num1, num2[j], zeros);
                
                zeros+=1;
            }
            
            int length=products.back().size();
            
            for(auto & product : products)
            {
                while(product.size() < length)
                {
                    product.emplace_front(0);
                }
            }
            
            int carry=0;
            
            deque<int> finalDigits;
            
            for(int column=length-1;column>=0;column--)
            {
                int columnSum=0;
                
                for(int row=0;row<products.size();row++)
                {
                    int digit=products[row][column];
                    
                    columnSum+=digit;
                }
                
                columnSum+=carry;
                
                finalDigits.emplace_front(columnSum % 10);
                
                carry=columnSum / 10;
            }
            
            if(carry > 0)
            {
                finalDigits.emplace_front(carry);
            }
            
            while(!finalDigits.empty())
            {
                result.push_back(finalDigits.front() + '0');
                
                finalDigits.pop_front();
            }
            
            return result;
        }
};