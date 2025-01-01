#include <cmath>
#include <vector>
using namespace std;

class Solution
{
    private:
        const double epsilon=1e-3;
    
    public:
        bool judgePoint24(vector<int> & cards)
        {
            bool result=false;

            vector<double> doubleCards;

            for(int card : cards)
            {
                doubleCards.emplace_back(1.0 * card);
            }

            result=helper(doubleCards);

            return result;
        }

        bool helper(vector<double> & doubleCards)
        {
            
            //if doubleCards only has one number left, then we have successfully applied operations on all four cards
            if(doubleCards.size()==1)
            {   
                double difference=abs(doubleCards[0] - 24.0);

                //Make sure that the difference is within our window for error
                return difference <= epsilon;
            }

            //Pick two cards
            for(int i=1;i<doubleCards.size();i++)
            {
                double first=doubleCards[i];
                
                for(int j=0;j<i;j++)
                {
                    double second=doubleCards[j];
                    
                    //All ways to apply the *, +, and - operators to two cards
                    vector<double> operationResults={first + second, first - second, second - first, first * second};

                    //Make sure first is greater than zero for division
                    if(first > 0)
                    {
                        operationResults.emplace_back(second / first);
                    }

                    //Make sure that second is greater than zero for division
                    if(second > 0)
                    {
                        operationResults.emplace_back(first / second);
                    }

                    //Remaining cards that are not first and second
                    vector<double> remaining;

                    //Add the remaining cards that are not first and second
                    for(int k=0;k<doubleCards.size();k++)
                    {
                        if(k!=i and k!=j)
                        {
                            remaining.push_back(doubleCards[k]);
                        }
                    }

                    //For each operation result
                    for(double operationResult : operationResults)
                    {
                        //Add each operation result, one at a time, to remaining
                        remaining.push_back(operationResult);

                        //Recurse on remaining
                        if(helper(remaining)==true)
                        {
                            return true;
                        }

                        //Remove the operation result we added so we can try the next one
                        remaining.pop_back();
                    }
                }
            }

            return false;
        }
};