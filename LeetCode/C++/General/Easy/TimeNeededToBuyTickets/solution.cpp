#include <vector>
using namespace std;

class Solution
{
    public:
        int timeRequiredToBuy(vector<int> & tickets, int k)
        {
            int result=0;

            int t=tickets.size();

            while(tickets[k] > 0)
            {
                for(int person=0;person<t;person+=1)
                {
                    if(tickets[person] > 0)
                    {
                        tickets[person]-=1;

                        result+=1;
                    }

                    if(person==k and tickets[person]==0)
                    {
                        break;
                    }
                }
            }

            return result;
        }
};