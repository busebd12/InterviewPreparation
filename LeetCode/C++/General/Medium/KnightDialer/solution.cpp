class Solution
{
    public:
        int knightDialer(int n)
        {
            int result=0;
            
            const int MOD=1000000007;
            
            if(n==1)
            {
                return 10;
            }
            
            vector<vector<int>> buttonToDestinations={{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
            
            unordered_map<int, deque<int>> hashtable;
            
            for(int button=0;button<10;button++)
            {
                hashtable[button].emplace_back(button);
            }
            
            for(int count=2;count<=n;count++)
            {
                for(auto & [button, phoneNumbers] : hashtable)
                {
                    auto qSize=phoneNumbers.size();
                    
                    for(int size=0;size<qSize;size++)
                    {
                        auto number=phoneNumbers.front();
                        
                        phoneNumbers.pop_front();
                        
                        if(!buttonToDestinations[number].empty())
                        {
                            for(auto destination : buttonToDestinations[number])
                            {   
                                phoneNumbers.emplace_back(destination);
                            }
                        }
                    }
                }
            }
            
            for(auto & [button, phoneNumbers] : hashtable)
            {   
                result+=phoneNumbers.size();
                    
                result=result % MOD;
            }
            
            return result;
        }
};

class Solution
{
    public:
        int dfs(unordered_map<int, vector<int>> & graph, int n, const int MOD, int button)
        {
            if(n==0)
            {
                return 1;
            }
            
            int subproblemSolution=0;
            
            for(auto neighbour : graph[button])
            {
                subproblemSolution=(subproblemSolution + dfs(graph, n-1, MOD, neighbour)) % MOD;
            }
            
            return subproblemSolution;
        }
    
        int knightDialer(int n)
        {
            int result=0;
            
            const int MOD=1000000007;
            
            vector<vector<int>> buttonToDestinations={{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
            
            for(int button=0;button<10;button++)
            {
                result=(result + dfs(buttonToDestinations, n-1, MOD, button)) % MOD;
            }
            
            return result;
        }
};

class Solution
{
    public:
        int memoization(vector<vector<int>> & graph, vector<vector<int>> & memo, int n, const int MOD, int button)
        {
            if(n==0)
            {
                return 1;
            }
            
            if(memo[n][button]!=-1)
            {
                return memo[n][button];
            }
            
            int subproblemSolution=0;
            
            for(auto neighbour : graph[button])
            {
                subproblemSolution=(subproblemSolution + memoization(graph, memo, n-1, MOD, neighbour)) % MOD;
            }
            
            memo[n][button]=subproblemSolution;
            
            return subproblemSolution;
        }
    
        int knightDialer(int n)
        {
            int result=0;
            
            const int MOD=1000000007;
            
            vector<vector<int>> buttonToDestinations={{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
            
            vector<vector<int>> memo(n + 1, vector<int>(10, -1));
            
            for(int button=0;button<10;button++)
            {
                result=(result + memoization(buttonToDestinations, memo, n-1, MOD, button)) % MOD;
            }
            
            return result;
        }
};