#include <unordered_map>
#include <vector>

/*
Solution 1: Recursive depth-first search

Time complexity: O(n) [where n is the number of employees]
Space complexity: O(n)
*/
class Solution
{
    public:
        int dfs(unordered_map<int, Employee*> & hashtable, int id)
        {
            //If the hashtable doesn't have the employee id
            if(!hashtable.count(id))
            {
                return 0;
            }
            
            //Importance of current employee
            int importance=hashtable[id]->importance;
            
            //If the current employee has direct reports
            if(!hashtable[id]->subordinates.empty())
            {
                //For each direct report
                for(const auto & subordinate : hashtable[id]->subordinates)
                {
                    //Add the importance of the direct report to the current employee's importance
                    importance+=dfs(hashtable, subordinate);
                }
            }
            
            return importance;
        }
    
        int getImportance(vector<Employee*> employees, int id)
        {
            //Hashtable used to map employee ids to Employee object pointers
            unordered_map<int, Employee*> hashtable;
            
            //Create the mapping
            for(auto & employee : employees)
            {
                hashtable[employee->id]=employee;
            }
            
            return dfs(hashtable, id);
        }
};

/*
Solution 2: Iterative depth-first search

Time complexity: O(n) [where n is the number of employees]
Space complexity: O(n)
*/
class Solution
{
    public:
        int getImportance(vector<Employee*> employees, int id)
        {
            int result=0;
            
            //Hashtable used to map employee ids to Employee object pointers
            unordered_map<int, Employee*> hashtable;
            
            //Create the mapping
            for(auto & employee : employees)
            {
                hashtable[employee->id]=employee;
            }
            
            //Stack to hold employee ids
            deque<int> stack;
            
            stack.emplace_back(id);
            
            while(!stack.empty())
            {
                auto employeeId=stack.back();
                
                stack.pop_back();
                
                //Add importance of current employee to the result
                result+=hashtable[employeeId]->importance;
                
                //If the current employee has direct reports
                if(!hashtable[employeeId]->subordinates.empty())
                {
                    //For each direct report
                    for(const auto & subordinate : hashtable[employeeId]->subordinates)
                    {
                        //Add the direct report to the stack
                        stack.emplace_back(subordinate);
                    }
                }
            }
            
            return result;
        }
};