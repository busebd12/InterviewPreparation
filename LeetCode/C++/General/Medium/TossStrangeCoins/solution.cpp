#include <vector>
using namespace std;

class Solution
{
    public:
        double probabilityOfHeads(vector<double> & prob, int target)
        {
            double result=0.0;

            int p=prob.size();

            int index=0;

            result=helper(prob, p, target, index);

            return result;
        }

        double helper(vector<double> & prob, int p, int target, int index)
        {
            if(target < 0)
            {
                return 0;
            }

            if(index==p)
            {
                return target==0;
            }

            double subproblemSolution=0.0;

            double headsProbability=prob[index] * helper(prob, p, target - 1, index + 1);

            double tailsProbability=(1 - prob[index]) * helper(prob, p, target, index + 1);

            subproblemSolution=headsProbability + tailsProbability;

            return subproblemSolution;
        }
};

class Solution
{
    public:
        double probabilityOfHeads(vector<double> & prob, int target)
        {
            double result=0.0;

            int p=prob.size();

            int index=0;

            vector<vector<double>> memo(p + 1, vector<double>(target + 1, -1));

            result=helper(prob, memo, p, target, index);

            return result;
        }

        double helper(vector<double> & prob, vector<vector<double>> & memo, int p, int target, int index)
        {
            if(target < 0)
            {
                return 0;
            }

            if(index==p)
            {
                return target==0;
            }

            if(memo[index][target]!=-1)
            {
                return memo[index][target];
            }

            double subproblemSolution=0.0;

            double headsProbability=prob[index] * helper(prob, memo, p, target - 1, index + 1);

            double tailsProbability=(1 - prob[index]) * helper(prob, memo, p, target, index + 1);

            subproblemSolution=headsProbability + tailsProbability;

            memo[index][target]=subproblemSolution;

            return subproblemSolution;
        }
};