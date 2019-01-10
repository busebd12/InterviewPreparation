#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int lastRemainingTLE(int n)
{
    if(n==0)
    {
        return 0;
    }

    if(n==1)
    {
        return 1;
    }

    static map<int, bool> numbers;

    for(int number=1;number<=n;++number)
    {
        numbers.insert(make_pair(number, false));
    }

    while(true)
    {
        bool remove=true;

        for(auto itr=numbers.begin();itr!=numbers.end();)
        {
            if(remove)
            {
                itr=numbers.erase(itr);

                remove=false;
            }
            else
            {
                remove=true;

                ++itr;
            }
        }

        cout << "REMAINING:" << endl;

        for(auto & number : numbers)
        {
            cout << number.first << " ";
        }

        cout << endl;

        cout << endl;

        if(numbers.size()==1)
        {
            //cout << "ONE NUMBER LEFT" << endl;

            break;
        }

        remove=true;

        for(auto itr=numbers.rbegin();itr!=numbers.rend();++itr)
        {
            if(remove)
            {
                itr->second=true;

                remove=false;
            }
            else
            {
                remove=true;
            }
        }

        for(auto itr=numbers.begin();itr!=numbers.end();)
        {
            if(itr->second)
            {
                itr=numbers.erase(itr);
            }
            else
            {
                ++itr;
            }
        }

        cout << "REMAINING:" << endl;

        for(auto & number : numbers)
        {
            cout << number.first << " ";
        }

        cout << endl;

        cout << endl;

        if(numbers.size()==1)
        {
            //cout << "ONE NUMBER LEFT" << endl;

            break;
        }

    }

    return numbers.begin()->first;
}

int lastRemaining(int n)
{
    int head=1;

    int remaining=n;

    int step=1;

    bool leftToRight=true;

    while(remaining > 1)
    {
        if(leftToRight || remaining%2==1)
        {
            head+=step;
        }

        step*=2;

        remaining/=2;

        leftToRight=!leftToRight;
    }

    return head;
}

int main()
{
    int n=10;

    cout << lastRemaining(n) << endl;
}