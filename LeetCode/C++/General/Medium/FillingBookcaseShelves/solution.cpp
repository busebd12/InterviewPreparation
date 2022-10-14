#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/filling-bookcase-shelves/discuss/1216516/C%2B%2B-Top-Down-DP-with-Memo

Time complexity: O(2^n) [where n is the length of books]
Space complexity: O(n)
*/

class Solution
{
    public:
        int minHeightShelves(vector<vector<int>> & books, int shelfWidth)
        {
            int result=0;
            
            int n=books.size();
            
            int currentShelfHeight=0;
            
            int currentShelfWidth=0;
            
            int maxShelfWidth=shelfWidth;
            
            int index=0;
            
            result=dfs(books, n, currentShelfHeight, currentShelfWidth, maxShelfWidth, index);
            
            return result;
        }
    
        int dfs(vector<vector<int>> & books, int n, int currentShelfHeight, int currentShelfWidth, int maxShelfWidth, int index)
        {   
            if(index==n)
            {
                return currentShelfHeight;
            }
            
            int subproblemSolution=numeric_limits<int>::max();
            
            int bookWidth=books[index][0];
            
            int bookHeight=books[index][1];
            
            int putBookOnCurrentShelf=numeric_limits<int>::max();
            
            int putBookOnNextShelf=numeric_limits<int>::max();
            
            int newShelfWidth=currentShelfWidth + bookWidth;
            
            if(newShelfWidth <= maxShelfWidth)
            {
                putBookOnCurrentShelf=dfs(books, n, max(bookHeight, currentShelfHeight), newShelfWidth, maxShelfWidth, index + 1);
            }
            
            putBookOnNextShelf=currentShelfHeight + dfs(books, n, bookHeight, bookWidth, maxShelfWidth, index + 1);
            
            subproblemSolution=min(putBookOnCurrentShelf, putBookOnNextShelf);
            
            return subproblemSolution;
        }
};


/*
Solution: inspired by this post --> https://leetcode.com/problems/filling-bookcase-shelves/discuss/1216516/C%2B%2B-Top-Down-DP-with-Memo

Time complexity: O(n)
Space complexity: O(1000 * 1000) --> O(1)
*/

class Solution
{
    private:
        vector<vector<int>> memo;
    
    public:
        int minHeightShelves(vector<vector<int>> & books, int shelfWidth)
        {
            int result=0;
            
            int n=books.size();
            
            memo.resize(1001, vector<int>(1001, -1));
            
            int currentShelfHeight=0;
            
            int currentShelfWidth=0;
            
            int maxShelfWidth=shelfWidth;
            
            int index=0;
            
            result=dfs(books, n, currentShelfHeight, currentShelfWidth, maxShelfWidth, index);
            
            return result;
        }
    
        int dfs(vector<vector<int>> & books, int n, int currentShelfHeight, int currentShelfWidth, int maxShelfWidth, int index)
        {   
            if(index==n)
            {
                return currentShelfHeight;
            }
            
            if(memo[currentShelfWidth][index]!=-1)
            {
                return memo[currentShelfWidth][index];
            }
            
            int subproblemSolution=numeric_limits<int>::max();
            
            int bookWidth=books[index][0];
            
            int bookHeight=books[index][1];
            
            int putBookOnCurrentShelf=numeric_limits<int>::max();
            
            int putBookOnNextShelf=numeric_limits<int>::max();
            
            int newShelfWidth=currentShelfWidth + bookWidth;
            
            if(newShelfWidth <= maxShelfWidth)
            {
                putBookOnCurrentShelf=dfs(books, n, max(bookHeight, currentShelfHeight), newShelfWidth, maxShelfWidth, index + 1);
            }
            
            putBookOnNextShelf=currentShelfHeight + dfs(books, n, bookHeight, bookWidth, maxShelfWidth, index + 1);
            
            subproblemSolution=min(putBookOnCurrentShelf, putBookOnNextShelf);
            
            memo[currentShelfWidth][index]=subproblemSolution;
            
            return subproblemSolution;
        }
};