#include <vector>
using namespace std;

/*
Time complexity: O(s + t + (t * n)) [where s is the length of preferences and t is the length of pairs]
Space complexity: O(s + t)
*/

class Solution
{
    public:
        int unhappyFriends(int n, vector<vector<int>> & preferences, vector<vector<int>> & pairs)
        {
            int result=0;

            int p=preferences.size();

            vector<vector<int>> rankings(n, vector<int>(n, -1));

            for(int i=0;i<p;i++) //O(s)
            {
                for(int j=0;j<preferences[i].size();j++)
                {
                    int friendId=preferences[i][j];

                    int rank=j + 1;

                    rankings[i][friendId]=rank;
                }
            }

            vector<int> hashmap(n, -1);

            for(const vector<int> & p : pairs) //O(t)
            {
                int x=p[0];

                int y=p[1];

                hashmap[x]=y;

                hashmap[y]=x;
            }

            for(const vector<int> & p : pairs) //O(t)
            {
                int x=p[0];

                int y=p[1];

                int yRank=rankings[x][y];

                bool alreadyFound=false;

                for(int u : preferences[x]) //O(n)
                {
                    if(hashmap[u]!=-1)
                    {
                        int uRank=rankings[x][u];
                        
                        int v=hashmap[u];
                        
                        if(alreadyFound==false)
                        {
                            int vRank=rankings[u][v];

                            if(uRank < yRank and rankings[u][x] < vRank)
                            {
                                alreadyFound=true;

                                result+=1;
                            }
                        }
                    }
                }

                int xRank=rankings[y][x];

                alreadyFound=false;

                for(int u : preferences[y]) //O(n)
                {
                    if(hashmap[u]!=-1)
                    {
                        int v=hashmap[u];
                        
                        int uRank=rankings[y][u];
                        
                        if(alreadyFound==false)
                        {
                            int vRank=rankings[u][v];

                            if(uRank < xRank and rankings[u][y] < vRank)
                            {
                                alreadyFound=true;

                                result+=1;
                            }
                        }
                    }
                }
            }

            return result;
        }
};