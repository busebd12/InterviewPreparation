#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <set>
#include <unordered_map>
#include <vector>

/*
 * Solutions: all solutions are based implementations of Hierholzer’s Algorithm. See this awesome video --> https://www.youtube.com/watch?v=8MpoO2zA2l4
 *
 * 1. Recursion + dfs. After creating the graph, we sort the individual edges to ensure that the result will be in lexicographical order.
 *
 * Time complexity: O(E log E) [where E is the number of edges in the graph]
 * Space complexity: O(V + E) [where V is the number of vertices and E is the number of edges in the graph]
 *
 * 2. Almost the same as the first solution but we use a std::deque since we removing from the front of our data strucutre
 * a lot and std::deque allows us to do this in O(1) time.
 *
 * Time complexity: O(E log E) [where E is the number of edges in the graph]
 * Space complexity: O(V + E) [where V is the number of vertices and E is the number of edges in the graph]
 *
 * 3. Almost the same as the first solution but we use a multiset to keep the edges sorted instead of
 * using the std::sort algorithm.
 *
 * Time complexity: O(E log E) [where E is the number of edges in the graph]
 * Space complexity: O(V + E) [where V is the number of vertices and E is the number of edges in the graph]
 *
 * 4. Iterative version of the first solution.
 *
 * Time complexity: O(E log E) [where E is the number of edges in the graph]
 * Space complexity: O(V + E) [where V is the number of vertices and E is the number of edges in the graph]
 *
 * 5. Iterative version of the second solution.
 *
 * Time complexity: O(E log E) [where E is the number of edges in the graph]
 * Space complexity: O(V + E) [where V is the number of vertices and E is the number of edges in the graph]
 *
 * 6. Iterative version of the third solution.
 *
 * Time complexity: O(E log E) [where E is the number of edges in the graph]
 * Space complexity: O(V + E) [where V is the number of vertices and E is the number of edges in the graph]
 */

void dfs(std::unordered_map<std::string, std::vector<std::string>> & graph, std::vector<std::string> & itinerary, std::string startingAirport)
{
    while(!graph[startingAirport].empty())
    {
        auto nextAirport=graph[startingAirport][0];

        graph[startingAirport].erase(graph[startingAirport].begin());

        dfs(graph, itinerary, nextAirport);
    }

    itinerary.emplace_back(startingAirport);

    return;
}

std::vector<std::string> findItinerary(std::vector<std::vector<std::string>> & tickets)
{
    std::vector<std::string> itinerary;

    if(tickets.empty())
    {
        return {};
    }

    std::unordered_map<std::string, std::vector<std::string>> graph;

    for(auto & airports : tickets)
    {
        std::string departing=airports[0];

        std::string arriving=airports[1];

        graph[departing].emplace_back(arriving);
    }

    for(auto & [key, value] : graph)
    {
        std::sort(value.begin(), value.end());
    }

    std::string startingAirport="JFK";

    dfs(graph, itinerary, startingAirport);

    std::reverse(itinerary.begin(), itinerary.end());

    return itinerary;
}

void dfs(std::unordered_map<std::string, std::deque<std::string>> & graph, std::vector<std::string> & itinerary, std::string startingAirport)
{
    while(!graph[startingAirport].empty())
    {
        auto nextAirport=graph[startingAirport].front();

        graph[startingAirport].pop_front();

        dfs(graph, itinerary, nextAirport);
    }

    itinerary.emplace_back(startingAirport);

    return;
}

std::vector<std::string> findItinerary(std::vector<std::vector<std::string>> & tickets)
{
    std::vector<std::string> itinerary;

    if(tickets.empty())
    {
        return {};
    }

    std::unordered_map<std::string, std::deque<std::string>> graph;

    for(auto & airports : tickets)
    {
        std::string departing=airports[0];

        std::string arriving=airports[1];

        graph[departing].emplace_back(arriving);
    }

    for(auto & [key, value] : graph)
    {
        std::sort(value.begin(), value.end());
    }

    std::string startingAirport="JFK";

    dfs(graph, itinerary, startingAirport);

    std::reverse(itinerary.begin(), itinerary.end());

    return itinerary;
}

void dfs(std::unordered_map<std::string, std::multiset<std::string>> & graph, std::vector<std::string> & itinerary, std::string startingAirport)
{
    while(!graph[startingAirport].empty())
    {
        auto itr=graph[startingAirport].begin();

        auto nextAirport=*itr;

        graph[startingAirport].erase(itr);

        dfs(graph, itinerary, nextAirport);
    }

    itinerary.emplace_back(startingAirport);

    return;
}

std::vector<std::string> findItinerary(std::vector<std::vector<std::string>> & tickets)
{
    std::vector<std::string> itinerary;

    if(tickets.empty())
    {
        return {};
    }

    std::unordered_map<std::string, std::multiset<std::string>> graph;

    for(auto & airports : tickets)
    {
        std::string departing=airports[0];

        std::string arriving=airports[1];

        graph[departing].insert(arriving);
    }

    std::string startingAirport="JFK";

    dfs(graph, itinerary, startingAirport);

    std::reverse(itinerary.begin(), itinerary.end());

    return itinerary;
}

std::vector<std::string> findItinerary(std::vector<std::vector<std::string>> & tickets)
{
    std::vector<std::string> itinerary;

    if(tickets.empty())
    {
        return itinerary;
    }

    std::unordered_map<std::string, std::vector<std::string>> graph;

    for(auto & airports : tickets)
    {
        std::string departing=airports[0];

        std::string arriving=airports[1];

        graph[departing].emplace_back(arriving);
    }

    for(auto & [key, value] : graph)
    {
        std::sort(value.begin(), value.end());
    }

    std::stack<std::string> stk;

    stk.push("JFK");

    while(!stk.empty())
    {
        auto current=stk.top();

        if(!graph.count(current) || graph[current].empty())
        {
            itinerary.emplace_back(current);

            stk.pop();
        }
        else
        {
            auto nextAirport=graph[current][0];

            graph[current].erase(graph[current].begin());

            stk.push(nextAirport);
        }
    }

    std::reverse(itinerary.begin(), itinerary.end());

    return itinerary;
}

std::vector<std::string> findItinerary(std::vector<std::vector<std::string>> & tickets)
{
    std::vector<std::string> itinerary;

    if(tickets.empty())
    {
        return itinerary;
    }

    std::unordered_map<std::string, std::deque<std::string>> graph;

    for(auto & airports : tickets)
    {
        std::string departing=airports[0];

        std::string arriving=airports[1];

        graph[departing].emplace_back(arriving);
    }

    for(auto & [key, value] : graph)
    {
        std::sort(value.begin(), value.end());
    }

    std::stack<std::string> stk;

    stk.push("JFK");

    while(!stk.empty())
    {
        auto current=stk.top();

        if(!graph.count(current) || graph[current].empty())
        {
            itinerary.emplace_back(current);

            stk.pop();
        }
        else
        {
            auto nextAirport=graph[current][0];

            graph[current].pop_front();

            stk.push(nextAirport);
        }
    }

    std::reverse(itinerary.begin(), itinerary.end());

    return itinerary;
}

std::vector<std::string> findItinerary(std::vector<std::vector<std::string>> & tickets)
{
    std::vector<std::string> itinerary;

    if(tickets.empty())
    {
        return itinerary;
    }

    std::unordered_map<std::string, std::multiset<std::string>> graph;

    for(auto & airports : tickets)
    {
        std::string departing=airports[0];

        std::string arriving=airports[1];

        graph[departing].insert(arriving);
    }

    std::stack<std::string> stk;

    stk.push("JFK");

    while(!stk.empty())
    {
        auto current=stk.top();

        if(!graph.count(current) || graph[current].empty())
        {
            itinerary.emplace_back(current);

            stk.pop();
        }
        else
        {
            auto itr=graph[current].begin();

            auto nextAirport=*itr;

            graph[current].erase(itr);

            stk.push(nextAirport);
        }
    }

    std::reverse(itinerary.begin(), itinerary.end());

    return itinerary;
}