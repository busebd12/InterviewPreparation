#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

void populateMap(vector<Employee*> employees, unordered_map<int, pair<int, vector<int>>> & employeeMap)
{
    const size_t employeesSize=employees.size();
    
    for(int index=0;index<employeesSize;++index)
    {
        int employeeId=employees[index]->id;
        
        int employeeImportance=employees[index]->importance;
        
        vector<int> employeeSubordinates;
        
        const size_t subordinatesSize=employees[index]->subordinates.size();
        
        for(int i=0;i<subordinatesSize;++i)
        {
            employeeSubordinates.emplace_back(employees[index]->subordinates[i]);
        }
        
        pair<int, vector<int>> p=make_pair(employeeImportance, employeeSubordinates);
        
        employeeMap.insert(make_pair(employeeId, p));
    }
}

void getImportance(unordered_map<int, pair<int, vector<int>>> employeeMap, int employeeId, int & importance)
{
    importance+=employeeMap[employeeId].first;
    
    if((employeeMap[employeeId].second).empty())
    {
        return;
    }
    
    for(const auto & id : employeeMap[employeeId].second)
    {
        getImportance(employeeMap, id, importance);
    }
}


int getImportance(vector<Employee*> employees, int id)
{
    if(employees.empty())
    {
        return 0;
    }
    
    unordered_map<int, pair<int, vector<int>>> employeeMap;
    
    populateMap(employees, employeeMap);
    
    int importance=0;
    
    getImportance(employeeMap, id, importance);
    
    return importance;
}