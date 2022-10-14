#include <string>
#include <vector>
using namespace std;

class CombinationIterator
{
    private:
        vector<string> combinations;
    
        int index;
    
    public:
        CombinationIterator(string characters, int combinationLength)
        {
            index=0;
            
            generateCombinations(characters, combinationLength);
        }

        string next()
        {
            return combinations[index++];
        }

        bool hasNext()
        {
            return index < combinations.size();
        }
    
        void generateCombinations(string characters, int combinationLength)
        {
            string combination{};
            
            int n=characters.size();
            
            int start=0;
            
            dfs(characters, combination, n, combinationLength, start);
        }
    
        void dfs(string characters, string & combination, int n, int combinationLength, int start)
        {
            if(combination.size()==combinationLength)
            {
                combinations.push_back(combination);
            }

            for(int index=start;index<n;index++)
            {
                combination.push_back(characters[index]);

                dfs(characters, combination, n, combinationLength, index + 1);

                combination.pop_back();
            }
        }
};