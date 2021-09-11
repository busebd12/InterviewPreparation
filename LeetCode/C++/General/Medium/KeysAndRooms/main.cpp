#include <iostream>
#include <queue>
#include <stack>
#include <vector>

/*
 * Solutions:
 *
 * 1. Recursive depth-first search.
 *
 * Time complexity: O(n + m) [where n is the number of rooms and m is the total number of keys]
 * Space complexity: O(n) recursive stack space
 *
 * 2. Iterative depth-first search.
 *
 * Time complexity: O(n + m) [where n is the number of rooms and m is the total number of keys]
 * Space complexity: O(n)
 *
 * 3. Breadth-first search.
 *
 * Time complexity: O(n + m) [where n is the number of rooms and m is the total number of keys]
 * Space complexity: O(n)
 */

class Solution
{
    public:
        void dfs(std::vector<std::vector<int>> & rooms, std::vector<bool> & visited, int room)
        {
            visited[room]=true;

            if(rooms[room].empty())
            {
                return;
            }

            for(const int & key : rooms[room])
            {
                if(!visited[key])
                {
                    dfs(rooms, visited, key);
                }
            }
        }


        bool canVisitAllRooms(std::vector<std::vector<int>> & rooms)
        {
            int n=int(rooms.size());

            std::vector<bool> visited(n, false);

            int startingRoom=0;

            dfs(rooms, visited, startingRoom);

            for(int index=0;index<n;index++)
            {
                if(!visited[index])
                {
                    return false;
                }
            }

            return true;
        }
};


class Solution
{
    public:
        void dfs(std::vector<std::vector<int>> & rooms, std::vector<bool> & visited, int room)
        {
            std::stack<int> stk;

            stk.push(room);

            while(!stk.empty())
            {
                auto currentRoom=stk.top();

                stk.pop();

                visited[currentRoom]=true;

                if(rooms[currentRoom].empty())
                {
                    continue;
                }

                for(const int & key : rooms[currentRoom])
                {
                    if(!visited[key])
                    {
                        stk.push(key);
                    }
                }
            }
        }


        bool canVisitAllRooms(std::vector<std::vector<int>> & rooms)
        {
            int n=int(rooms.size());

            std::vector<bool> visited(n, false);

            int startingRoom=0;

            dfs(rooms, visited, startingRoom);

            for(int index=0;index<n;index++)
            {
                if(!visited[index])
                {
                    return false;
                }
            }

            return true;
        }
};

class Solution
{
    public:
        void bfs(std::vector<std::vector<int>> & rooms, std::vector<bool> & visited, int room)
        {
            std::queue<int> Q;

            Q.emplace(room);

            while(!Q.empty())
            {
                auto currentRoom=Q.front();

                Q.pop();

                visited[currentRoom]=true;

                if(rooms[currentRoom].empty())
                {
                    continue;
                }

                for(const int & key : rooms[currentRoom])
                {
                    if(!visited[key])
                    {
                        Q.emplace(key);
                    }
                }
            }
        }


        bool canVisitAllRooms(std::vector<std::vector<int>> & rooms)
        {
            int n=int(rooms.size());

            std::vector<bool> visited(n, false);

            int startingRoom=0;

            bfs(rooms, visited, startingRoom);

            for(int index=0;index<n;index++)
            {
                if(!visited[index])
                {
                    return false;
                }
            }

            return true;
        }
};