#include <algorithm>
#include <deque>
#include <utility>
#include <vector>
using namespace std;

/*
Solutions inspired by this post --> https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/discuss/2119874/C%2B%2B-oror-EASY-TO-UNDERSTAND-oror-Sorting-%2B-Monotonic-Stack

Time complexity: O(n log n) + O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int numberOfWeakCharacters(vector<vector<int>> & properties)
        {
            int result=0;
            
            int p=properties.size();
            
            auto compareLikeThis=[] (vector<int> & lhs, vector<int> & rhs)
            {
                if(lhs[0]==rhs[0])
                {
                    return lhs[1] > rhs[1];
                }
                else
                {
                    return lhs[0] < rhs[0];
                }
            };
            
            sort(begin(properties), end(properties), compareLikeThis);
            
            deque<pair<int, int>> stack;
            
            for(int i=0;i<p;i++)
            {
                int attack=properties[i][0];
                
                int defense=properties[i][1];
                
                if(stack.empty())
                {   
                    stack.emplace_back(attack, defense);
                }
                else
                {
                    while(!stack.empty() and stack.back().first < attack and stack.back().second < defense)
                    {
                        stack.pop_back();
                        
                        result+=1;
                    }
                    
                    stack.emplace_back(attack, defense);
                }
            }
            
            return result;
        }
};

class Solution
{
    public:
        int numberOfWeakCharacters(vector<vector<int>> & properties)
        {
            int result=0;
            
            int p=properties.size();
            
            auto compareLikeThis=[] (vector<int> & lhs, vector<int> & rhs)
            {
                if(lhs[0]==rhs[0])
                {
                    return lhs[1] > rhs[1];
                }
                else
                {
                    return lhs[0] < rhs[0];
                }
            };
            
            sort(begin(properties), end(properties), compareLikeThis);
            
            deque<int> stack;
            
            for(int i=0;i<p;i++)
            {
                int attack=properties[i][0];
                
                int defense=properties[i][1];
                
                if(stack.empty())
                {   
                    stack.emplace_back(i);
                }
                else
                {
                    while(!stack.empty() and properties[stack.back()][0] < attack and properties[stack.back()][1] < defense)
                    {
                        stack.pop_back();
                        
                        result+=1;
                    }
                    
                    stack.emplace_back(i);
                }
            }
            
            return result;
        }
};

class Solution
{
    public:
        int numberOfWeakCharacters(vector<vector<int>> & properties)
        {
            int result=0;
            
            int n=properties.size();
            
            auto compareLikeThis=[] (vector<int> & lhs, vector<int> & rhs)
            {
                //if the attack is the same
                if(lhs[0]==rhs[0])
                {
                    //sort the defense values in descending order
                    return lhs[1] > rhs[1];
                }
                else
                {
                    //sort the attack values in ascending order
                    return lhs[0] < rhs[0];
                }
            };
            
            sort(begin(properties), end(properties), compareLikeThis);
            
            int maxDefense=numeric_limits<int>::min();
            
            for(int i=n-1;i>=0;i--)
            {
                int defense=properties[i][1];
                
                if(defense < maxDefense)
                {
                    result+=1;
                }
                
                maxDefense=max(maxDefense, defense);
            }
            
            return result;
        }
};