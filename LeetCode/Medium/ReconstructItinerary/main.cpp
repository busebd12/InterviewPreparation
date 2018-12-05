#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

void populateMap(unordered_map<string, vector<pair<string, bool>>> & table, vector<pair<string, string>> & tickets)
{
    for(auto & ticket : tickets)
    {
        if(table.find(ticket.first)==end(table))
        {
            table.insert(make_pair(ticket.first, vector<pair<string, bool>>()));
        }
    }

    for(auto & ticket : tickets)
    {
        table[ticket.first].emplace_back(make_pair(ticket.second, false));
    }
}

bool dfs(unordered_map<string, vector<pair<string, bool>>> & table, vector<string> & path, string startingAirport, int n)
{
    path.emplace_back(startingAirport);

    if(path.size()==n)
    {
        return true;
    }

    if(table.find(startingAirport)==end(table))
    {
        return false;
    }

    for(auto & airport : table[startingAirport])
    {
        if(!airport.second)
        {
            airport.second=true;

            if(dfs(table, path, airport.first, n))
            {
                return true;
            }

            airport.second=false;

            path.pop_back();
        }
    }

    return false;
}

vector<string> findItinerary(vector<pair<string, string>> & tickets)
{
    vector<string> result;

    if(tickets.empty())
    {
        return result;
    }

    unordered_map<string, vector<pair<string, bool>>> table;

    populateMap(table, tickets);

    for(auto & airport : table)
    {
        sort(airport.second.begin(), airport.second.end(), [] (auto & a, auto & b) {return a.first < b.first;});
    }

    string startingAirport="JFK";

    int n=int(tickets.size()+1);

    dfs(table, result, startingAirport, n);

    return result;
}