#include <vector>
using namespace std;

/*
Solution: inspired by these posts

1) https://leetcode.com/problems/android-unlock-patterns/solutions/922032/c-solution-beats-94-23-with-explanation-in-comments/
2) https://leetcode.com/problems/android-unlock-patterns/solutions/418284/javascript-dfs-clean-readable-code-with-explanation/
3) https://leetcode.com/problems/android-unlock-patterns/solutions/2256263/java-solution-dfs-easy-to-understand-with-explaination/
*/

class Solution
{
    private:
        vector<vector<int>> graph;
    
    public:
        int numberOfPatterns(int m, int n)
        {
            int result=0;
            
            graph.resize(10, vector<int>(10, -1));

            populateGraph(graph);

            vector<bool> visited(10, false);

            int size=1;

            int patterns=0;

            helper(visited, m, n, patterns, size, 1);

            //Multiply by four due to symmetry between keys 1, 3, 7, and 9 on the keypad
            result+=(patterns * 4);

            patterns=0;

            helper(visited, m, n, patterns, size, 2);

            //Multiply by four due to symmetry between keys 2, 4, 5, and 8 on the keypad
            result+=(patterns * 4);

            patterns=0;

            //The only starting key left is 5
            helper(visited, m, n, patterns, size, 5);

            //The 5 key doesn't have symmetry with any other keys on the keypad
            result+=patterns;

            return result;
        }

        void helper(vector<bool> & visited, int m, int n, int & patterns, int size, int u)
        {
            //If the size of our unlock pattern becomes larger than n, we are done
            if(size > n)
            {
                return;
            }

            //As long as the unlock pattern size keeps growing larger than m, we count it as a valid pattern each time
            if(size >= m)
            {
                patterns+=1;
            }

            //Mark the current vertex (key) as visited
            visited[u]=true;

            //Iterate through all the neighbours of this vertex (key)
            for(int neighbour=1;neighbour<10;neighbour++)
            {
                //If the neighbour is the same as the current vertex or we've already visited the neighbour
                if(u==neighbour or visited[neighbour]==true)
                {
                    continue;
                }

                //Check to see which middle key we have to use in order to move from u to neighbour
                int middle=graph[u][neighbour];

                //If the middle key is -1 (means you can move from u to neighbour without visiting middle [example: going from 1 to 6 on the keypad])
                //Or, if we have visited the middle key, then we can move from u to neighbour
                if(middle==-1 or visited[middle]==true)
                {
                    helper(visited, m, n, patterns, size + 1, neighbour);
                }
            }

            //Mark the current vertex (key) as not visited as part of standard backtracking algorithm
            visited[u]=false;
        }

        void populateGraph(vector<vector<int>> & graph)
        {
            //gaph[1][3]=2 means in order to move from 1 to 3 on the keypad/unlock screen, you need to go through 2
            //Another way to view this is that vertex 1 and vertex 3 are connected by an edge that passes through verted 2 in our graph
            //The same thinking applies to the rest of the vertex assignments in this function
            graph[1][3]=2;

            graph[3][1]=2;

            graph[4][6]=5;

            graph[6][4]=5;

            graph[7][9]=8;

            graph[9][7]=8;

            graph[1][7]=4;

            graph[7][1]=4;

            graph[2][8]=5;

            graph[8][2]=5;

            graph[3][9]=6;

            graph[9][3]=6;

            graph[1][9]=5;

            graph[9][1]=5;

            graph[7][3]=5;

            graph[3][7]=5;
        }
};