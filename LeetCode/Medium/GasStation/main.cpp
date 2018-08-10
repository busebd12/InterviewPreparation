#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int> & gas, vector<int> & cost, int & answer, int & gasTank, int & start, int i, bool & beginning)
{
    if(i==start && !beginning)
    {
        answer=i;

        return;
    }

    if(gasTank < cost[i])
    {
        return;
    }

    gasTank-=cost[i];

    if(i+1 > gas.size()-1)
    {
        gasTank+=gas[0];
    }
    else
    {
        gasTank+=gas[i+1];
    }

    if(beginning)
    {
        beginning=false;
    }

    if(start <= gas.size()-1 && i==gas.size()-1)
    {
        helper(gas, cost, answer, gasTank, start, 0, beginning);
    }
    else
    {
        helper(gas, cost, answer, gasTank, start, i+1, beginning);
    }
}

int canCompleteCircuit(vector<int> & gas, vector<int> & cost)
{
    int answer=-1;

    if(gas.empty() || cost.empty())
    {
        return answer;
    }

    int gasSize=int(gas.size());

    for(int i=0;i<gasSize;++i)
    {
        int start=i;

        bool beginning=true;

        int gasTank=gas[i];

        helper(gas, cost, answer, gasTank, start, i, beginning);
    }

    return answer;
}