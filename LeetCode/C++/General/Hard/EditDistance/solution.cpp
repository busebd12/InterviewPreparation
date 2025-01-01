#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
Solution 1: recursion.

Submission status: Time Limit Exceeded.

Time complexity: O(max(3^(n, m))) [where n=length of word1 and m=length of word2]

Space complexity: O(max(n, m))
*/

class Solution
{
    public:
        int minDistance(string word1, string word2)
        {
            int result=0;

            int n=word1.size();

            int m=word2.size();

            int i=0;

            int j=0;

            result=helper(word1, word2, n, m, i, j);

            return result;
        }

        int helper(string & word1, string & word2, int n, int m, int i, int j)
        {
            //If we reach the end of word1
            if(i==n)
            {
                //The number of edits will be equal to the remaining letters in word2
                return (m - j);
            }

            //If we reach the end of word2
            if(j==m)
            {
                //The number of edits will be equal to the remaining letters in word1
                return (n - i);
            }

            int subproblemSolution=0;

            //If the letters from word1 and word2 match
            if(word1[i]==word2[j])
            {
                subproblemSolution=helper(word1, word2, n, m, i + 1, j + 1);
            }
            //Else, the letters from word1 and word2 don't match
            else
            {
                //Simulate inserting a letter into word1
                //Note: we don't increase i since inserting a letter into word1 will increase the length of word1 and move i up one index anyway
                int insert=helper(word1, word2, n, m, i, j + 1);

                //Simulate removing a letter from word1
                //Note: we do increment i since removing a letter from word1 will decrease the length and move decrease i one spot to the left
                //So, in order to make sure i is in the right spot after removing the letter, we increment it by one
                int remove=helper(word1, word2, n, m, i + 1, j);

                //Simulate replacing the letter word1[i] with the letter word2[j]
                int replace=helper(word1, word2, n, m, i + 1, j + 1);

                //Calculate the minimum number of operations needed between insert, remove, and replace
                int minOperation=min(insert, min(remove, replace));

                subproblemSolution=1 + minOperation;
            }

            return subproblemSolution;
        }
};


/*
Solution 2: recursion + memoization

Submission status: accepted.

Time complexity: O(n * m) [where n=length of word1 and m=length of word2]

Space complexity: O(n * m)
*/

class Solution
{
    public:
        int minDistance(string word1, string word2)
        {
            int result=0;

            int n=word1.size();

            int m=word2.size();

            vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

            int i=0;

            int j=0;

            result=helper(word1, word2, memo, n, m, i, j);

            return result;
        }

        int helper(string & word1, string & word2, vector<vector<int>> & memo, int n, int m, int i, int j)
        {
            if(i==n)
            {
                return (m - j);
            }

            if(j==m)
            {
                return (n - i);
            }

            if(memo[i][j]!=-1)
            {
                return memo[i][j];
            }

            int subproblemSolution=0;

            if(word1[i]==word2[j])
            {
                subproblemSolution=helper(word1, word2, memo, n, m, i + 1, j + 1);
            }
            else
            {
                int insert=helper(word1, word2, memo, n, m, i, j + 1);

                int remove=helper(word1, word2, memo, n, m, i + 1, j);

                int replace=helper(word1, word2, memo, n, m, i + 1, j + 1);

                int minOperation=min(insert, min(remove, replace));

                subproblemSolution=1 + minOperation;
            }

            memo[i][j]=subproblemSolution;

            return subproblemSolution;
        }
};