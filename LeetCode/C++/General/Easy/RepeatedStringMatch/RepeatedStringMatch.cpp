#include <iostream>
#include <string>
using namespace std;

int repeatedStringMatch(string A, string B)
{   
    int count=0;
    
    string appended="";
    
    while(appended.size() < B.size())
    {   
        appended+=A;
        
        ++count;
    }
    
    if(appended.find(B)!=string::npos)
    {   
        return count;
    }
    
    appended+=A;
    
    if(appended.find(B)!=string::npos)
    {   
        return ++count;
    }
    
    return -1;
}