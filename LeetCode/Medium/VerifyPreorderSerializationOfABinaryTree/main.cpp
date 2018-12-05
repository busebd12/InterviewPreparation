#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isValidSerialization(string preorder)
{
    istringstream ps(preorder);

    string s;

    int degree=1;

    while(getline(ps, s, ','))
    {
        if(degree <= 0)
        {
            return false;
        }

        if(s.back()=='#')
        {
            --degree;
        }
        else
        {
            ++degree;
        }
    }

    return degree==0;
}