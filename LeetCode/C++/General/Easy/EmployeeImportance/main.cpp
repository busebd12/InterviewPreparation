#include "../Employee.h"
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Recursive, depth-first search. We build a hashtable (unordered_map<int, pair<int, vector<int>>>) to hold
 * the information about each employee, their importance, and subordinates. Then, for each employee,
 * we add their importance to our result variable and then recursively do the same thing for each of their direct subordinates.
 *
 * Time complexity: O(n) [where n is the length of the input employees vector]
 * Space complexity: O(n)
 *
 * 2) Similar to the first solution except we map each employee id to the Employee object pointer in our hashtable (unordered_map<int, Employee*>)
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */


void dfs(unordered_map<int, pair<int, vector<int>>> & hashtable, const int & id, int & result)
{
    if(!hashtable.count(id))
    {
        return;
    }

    result+=hashtable[id].first;

    if(!hashtable[id].second.empty())
    {
        for(const int & underling : hashtable[id].second)
        {
            dfs(hashtable, underling, result);
        }
    }
}

int getImportance(vector<Employee*> employees, int id)
{
    if(employees.empty())
    {
        return 0;
    }

    unordered_map<int, pair<int, vector<int>>> hashtable;

    for(Employee* employee : employees)
    {
        pair<int, vector<int>> p(employee->importance, employee->subordinates);

        hashtable.insert(make_pair(employee->id, p));
    }

    int result=0;

    dfs(hashtable, id, result);

    return result;
}

int dfs(unordered_map<int, Employee*> & hashtable, const int & id)
{
    if(!hashtable.count(id))
    {
        return 0;
    }

    int sum=hashtable[id]->importance;

    if(!hashtable[id]->subordinates.empty())
    {
        for(const int & underling : hashtable[id]->subordinates)
        {
            sum+=dfs(hashtable, underling);
        }
    }

    return sum;
}

int getImportance(vector<Employee*> employees, int id)
{
    if(employees.empty())
    {
        return 0;
    }

    unordered_map<int, Employee*> hashtable;

    for(Employee* employee : employees)
    {
        hashtable[employee->id]=employee;
    }

    return dfs(hashtable, id);
}