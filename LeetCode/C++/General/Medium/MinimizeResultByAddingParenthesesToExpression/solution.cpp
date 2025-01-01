#include <string>
#include <vector>

/*
Time complexity: O(n^3)
Space complexity: O(n)
*/

class Solution
{
    public:
        string minimizeResult(string expression)
        {
            string result="";
            
            auto plusIndex=expression.find('+');
        
            int beforeSize=expression.substr(0, plusIndex).size();
            
            int afterSize=expression.substr(plusIndex + 1, string::npos).size();
            
            vector<int> beforeIndices;
            
            for(int index=0;index<beforeSize;index++)
            {
                beforeIndices.push_back(index);
            }
            
            vector<int> afterIndices;
            
            for(int index=0;index<afterSize;index++)
            {
                afterIndices.push_back(index);
            }

            int current=numeric_limits<int>::max();
            
            for(int beforeIndex : beforeIndices)
            {
                expression.insert(expression.begin() + beforeIndex, '(');
                
                for(int afterIndex : afterIndices)
                {
                    expression.insert(expression.end() - afterIndex, ')');

                    int total=evaluate(expression);

                    if(total < current)
                    {
                        current=total;

                        result=expression;
                    }
                    
                    expression.erase(expression.end() - (afterIndex + 1));
                }
                
                expression.erase(expression.begin() + beforeIndex);
            }

            return result;
        }

        int evaluate(string & expression)
        {
            int total=1;
            
            auto openParenIndex=expression.find('(');
            
            auto closedParenIndex=expression.find(')');
            
            auto plusIndex=expression.find('+');
            
            string beforeOpenParen=expression.substr(0, openParenIndex);
            
            string afterClosedParen=expression.substr(closedParenIndex + 1, string::npos);
            
            if(!beforeOpenParen.empty())
            {
                total*=stoi(beforeOpenParen);
            }
            
            if(!afterClosedParen.empty())
            {
                total*=stoi(afterClosedParen);
            }
            
            string left=expression.substr(openParenIndex + 1, plusIndex);
            
            string right=expression.substr(plusIndex + 1, closedParenIndex);
            
            int sum=stoi(left) + stoi(right);
            
            total*=sum;
            
            return total;
        }
};