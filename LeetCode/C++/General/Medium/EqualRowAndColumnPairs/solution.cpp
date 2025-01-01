#include <map>
#include <vector>
using namespace std;

class Solution
{
    public:
        int equalPairs(vector<vector<int>>& grid)
        {
            int result=0;

            int rows=grid.size();

            int columns=grid[0].size();

            map<vector<int>, int> hashmap;

            for(vector<int> & row : grid)
            {
                hashmap[row]+=1;
            }

            for(int column=0;column<columns;column+=1)
            {
                vector<int> c;

                for(int row=0;row<rows;row+=1)
                {
                    c.push_back(grid[row][column]);
                }

                if(hashmap.find(c)!=hashmap.end())
                {
                    int pairs=hashmap[c];

                    result+=pairs;
                }
            }

            return result;
        }
};