#include <algorithm>
#include <limits>
#include <unordered_map>
#include <vector>
using namespaces std;

class Solution
{
    public:
        int minTransfers(vector<vector<int>> & transactions)
        {
            int result=0;

            int t=transactions.size();

            unordered_map<int, long> debtMap;

            for(vector<int> transaction : transactions)
            {
                int person0=transaction[0];

                int person1=transaction[1];

                int amount=transaction[2];

                if(debtMap.find(person0)==debtMap.end())
                {
                    debtMap.emplace(person0, 0);
                }

                debtMap[person0]-=amount;

                if(debtMap.find(person1)==debtMap.end())
                {
                    debtMap.emplace(person1, 0);
                }

                debtMap[person1]+=amount;
            }

            vector<long> debtAmounts;

            for(auto & [person, amount] : debtMap)
            {
                if(amount!=0)
                {
                    debtAmounts.push_back(amount);
                }
            }

            int d=debtAmounts.size();

            int person=0;

            result=helper(debtAmounts, d, person);

            return result;
        }

        int helper(vector<long> & debtAmounts, int d, int person)
        {
            if(person==d)
            {
                return 0;
            }

            if(debtAmounts[person]==0)
            {
                return helper(debtAmounts, d, person + 1);
            }

            int subproblemSolution=numeric_limits<int>::max();

            for(int person2=person+1;person2<d;person2++)
            {
                if(debtAmounts[person] * debtAmounts[person2] < 0)
                {
                    debtAmounts[person2]+=debtAmounts[person];

                    subproblemSolution=min(subproblemSolution, 1 + helper(debtAmounts, d, person + 1));

                    debtAmounts[person2]-=debtAmounts[person];
                }
            }

            return subproblemSolution;
        }
};