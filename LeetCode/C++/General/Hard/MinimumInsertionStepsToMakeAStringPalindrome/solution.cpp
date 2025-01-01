#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
        int minInsertions(string s)
        {
            int result=0;

            int n=s.size();

            int left=0;

            int right=n-1;

            result=helper(s, n, left, right);

            return result;   
        }

        int helper(string & s, int n, int left, int right)
        {
            if(left==right or left > right)
            {
                return 0;
            }

            int subproblemSolution=0;

            int lettersAreTheSame=0;

            int lettersAreDifferent=0;

            if(s[left]==s[right])
            {
                lettersAreTheSame=helper(s, n, left + 1, right - 1);
            }
            else
            {
                int addLetterToLeftEnd=1 + helper(s, n, left + 1, right);

                int addLetterToRightEnd=1 + helper(s, n, left, right - 1);

                lettersAreDifferent=min(addLetterToLeftEnd, addLetterToRightEnd);
            }

            subproblemSolution=max(lettersAreTheSame, lettersAreDifferent);

            return subproblemSolution;
        }
};

class Solution
{
    private:
        vector<vector<int>> memo;
    
    public:
        int minInsertions(string s)
        {
            int result=0;

            int n=s.size();

            int left=0;

            int right=n-1;

            memo.resize(n + 1, vector<int>(n + 1, -1));

            result=helper(s, n, left, right);

            return result;   
        }

        int helper(string & s, int n, int left, int right)
        {
            if(left==right or left > right)
            {
                return 0;
            }

            if(memo[left][right]!=-1)
            {
                return memo[left][right];
            }

            int subproblemSolution=0;

            int lettersAreTheSame=0;

            int lettersAreDifferent=0;

            if(s[left]==s[right])
            {
                lettersAreTheSame=helper(s, n, left + 1, right - 1);
            }
            else
            {
                int addLetterToLeftEnd=1 + helper(s, n, left + 1, right);

                int addLetterToRightEnd=1 + helper(s, n, left, right - 1);

                lettersAreDifferent=min(addLetterToLeftEnd, addLetterToRightEnd);
            }

            subproblemSolution=max(lettersAreTheSame, lettersAreDifferent);

            memo[left][right]=subproblemSolution;

            return subproblemSolution;
        }
};