#include <array>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
    public:
        double soupServings(int n)
        {
            double result=0.0;

            array<pair<int, int>, 4> operations={{{100, 0}, {75, 25}, {50, 50}, {25, 75}}};

            int A=n;

            int B=n;

            result=helper(operations, A, B);

            return result;
        }

        double helper(array<pair<int, int>, 4> & operations, int A, int B)
        {
            if(A <= 0 and B > 0)
            {
                return 1.0;
            }

            if(A <= 0 and B <= 0)
            {
                return 0.5;
            }

            if(A > 0 and B <= 0)
            {
                return 0.0;
            }

            double subproblemSolution=0.0;

            for(auto & [aOperation, bOperation] : operations)
            {
                subproblemSolution+=helper(operations, A - aOperation, B - bOperation);
            }

            subproblemSolution*=0.25;

            return subproblemSolution;
        }
};


class Solution
{
    public:
        double soupServings(int n)
        {
            double result=0.0;

            if(n >= 4800)
            {
                result=1.0;

                return result;
            }

            array<pair<int, int>, 4> operations={{{100, 0}, {75, 25}, {50, 50}, {25, 75}}};

            int A=n;

            int B=n;

            vector<vector<double>> memo(n + 1, vector<double>(n + 1, -1));

            result=helper(operations, memo, A, B);

            return result;
        }

        double helper(array<pair<int, int>, 4> & operations, vector<vector<double>> & memo, int A, int B)
        {
            if(A <= 0 and B > 0)
            {
                return 1.0;
            }

            if(A <= 0 and B <= 0)
            {
                return 0.5;
            }

            if(A > 0 and B <= 0)
            {
                return 0.0;
            }

            if(memo[A][B]!=-1.0)
            {
                return memo[A][B];
            }

            double subproblemSolution=0.0;

            for(auto & [aOperation, bOperation] : operations)
            {
                subproblemSolution+=helper(operations, memo, A - aOperation, B - bOperation);
            }

            subproblemSolution*=0.25;

            memo[A][B]=subproblemSolution;

            return subproblemSolution;
        }
};