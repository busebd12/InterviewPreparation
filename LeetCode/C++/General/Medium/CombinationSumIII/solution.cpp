#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
    public:
        void backtracking(vector<vector<int>> & result, unordered_set<int> & used, int n, int k, int sum, int start)
        {
            if(sum==n && used.size()==k)
            {   
                vector<int> v(begin(used), end(used));
                
                result.emplace_back(v);
            }
            
            for(int number=start;number<=9;number++)
            {
                if(used.find(number)==end(used))
                {   
                    used.insert(number);
                    
                    sum+=number;
                    
                    backtracking(result, used, n, k, sum, number + 1);
                    
                    sum-=number;
                    
                    used.erase(number);
                }
            }
        }
    
        vector<vector<int>> combinationSum3(int k, int n)
        {
            vector<vector<int>> result;
            
            unordered_set<int> used;
            
            int sum=0;
            
            int start=1;
            
            backtracking(result, used, n, k, sum, start);
            
            return result;
        }
};

class Solution
{
    public:
        void backtracking(vector<vector<int>> & result, vector<int> & combination, int n, int k, int sum, int start)
        {
            if(sum==n && combination.size()==k)
            {   
                result.emplace_back(combination);
            }
            
            for(int number=start;number<=9;number++)
            {
                combination.emplace_back(number);
                    
                sum+=number;

                backtracking(result, combination, n, k, sum, number + 1);

                sum-=number;

                combination.pop_back();
            }
        }
    
        vector<vector<int>> combinationSum3(int k, int n)
        {
            vector<vector<int>> result;
            
            vector<int> combination;
            
            int sum=0;
            
            int start=1;
            
            backtracking(result, combination, n, k, sum, start);
            
            return result;
        }
};