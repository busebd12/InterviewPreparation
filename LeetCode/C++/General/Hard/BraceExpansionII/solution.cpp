#include <deque>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/brace-expansion-ii/solutions/1914844/c-bfs-with-comments/
*/

class Solution
{
    public:
        vector<string> braceExpansionII(string expression)
        {
            vector<string> result;

            set<string> unique;

            deque<string> queue;

            queue.push_back(expression);

            while(!queue.empty())
            {
                string current=queue.front();

                queue.pop_front();

                int openBracketIndex=-1;

                int closingBracketIndex=0;

                while(closingBracketIndex < current.size() and current[closingBracketIndex]!='}')
                {
                    if(current[closingBracketIndex]=='{')
                    {
                        openBracketIndex=closingBracketIndex;
                    }

                    closingBracketIndex+=1;
                }

                if(openBracketIndex==-1)
                {
                    auto [insertionIterator, success]=unique.insert(current);

                    continue;
                }

                string beforeBracketExpression=current.substr(0, openBracketIndex);

                string afterBracketExpression=current.substr(closingBracketIndex + 1, string::npos);

                string bracketExpressionContents=current.substr(openBracketIndex + 1, closingBracketIndex - openBracketIndex - 1);

                stringstream expressionSS(bracketExpressionContents);

                char delimeter=',';

                string singleton="";

                while(getline(expressionSS, singleton, delimeter))
                {
                    string next="";

                    if(!beforeBracketExpression.empty())
                    {
                        next.append(beforeBracketExpression);
                    }

                    next.append(singleton);

                    if(!afterBracketExpression.empty())
                    {
                        next.append(afterBracketExpression);
                    }

                    queue.push_back(next);
                }
            }

            for(const string & singleton : unique)
            {
                result.push_back(singleton);
            }

            return result;
        }
};