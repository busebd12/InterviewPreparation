#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
    public:
        double average(vector<int> & salary)
        {
            double result=0;

            int minSalary=*(min_element(salary.begin(), salary.end()));

            int maxSalary=*(max_element(salary.begin(), salary.end()));

            double total=0;

            double count=0;

            for(int amount : salary)
            {
                if(amount!=minSalary and amount!=maxSalary)
                {
                    double current=(double)amount;

                    total+=current;

                    count+=1;
                }
            }

            result=total / count;

            return result;
        }
};