#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string complexNumberMultiply(string a, string b)
{
    int n=int(a.size());

    int m=int(b.size());

    string aBeforeOperator{};

    string aRest{};

    int aPlusIndex=0;

    for(int i=0;i<n;++i)
    {
        if(a[i]=='+')
        {
            aPlusIndex=i;

            break;
        }
    }

    for(int i=0;i<n;++i)
    {
        if(a[i]!='+')
        {
            if(i < aPlusIndex)
            {
                aBeforeOperator+=a[i];
            }

            if(i > aPlusIndex)
            {
                aRest+=a[i];
            }
        }
    }

    string bBeforeOperator{};

    string bRest{};

    int bPlusIndex=0;

    for(int j=0;j<m;++j)
    {
        if(b[j]=='+')
        {
            bPlusIndex=j;

            break;
        }
    }

    for(int j=0;j<m;++j)
    {
        if(b[j]!='+')
        {
            if(j < bPlusIndex)
            {
                bBeforeOperator+=b[j];
            }

            if(j > bPlusIndex)
            {
                bRest+=b[j];
            }
        }
    }

    int aOutter=0;

    string aOutterString{};

    for(int i=0;i<aBeforeOperator.size();++i)
    {
        if(isdigit(aBeforeOperator[i]))
        {
            aOutterString+=aBeforeOperator[i];
        }
    }

    aOutter=stoi(aOutterString);

    if(aBeforeOperator[0]=='-')
    {
        aOutter*=-1;
    }

    int aInner=0;

    string aInnerString{};

    for(int i=0;i<aRest.size();++i)
    {
        if(isdigit(aRest[i]))
        {
            aInnerString+=aRest[i];
        }
    }

    aInner=stoi(aInnerString);

    if(aRest[0]=='-')
    {
        aInner*=-1;
    }

    int bOutter=0;

    string bOutterString{};

    for(int i=0;i<bBeforeOperator.size();++i)
    {
        if(isdigit(bBeforeOperator[i]))
        {
            bOutterString+=bBeforeOperator[i];
        }
    }

    bOutter=stoi(bOutterString);

    if(bBeforeOperator[0]=='-')
    {
        bOutter*=-1;
    }

    int bInner=0;

    string bInnerString{};

    for(int i=0;i<bRest.size();++i)
    {
        if(isdigit(bRest[i]))
        {
            bInnerString+=bRest[i];
        }
    }

    bInner=stoi(bInnerString);

    if(bRest[0]=='-')
    {
        bInner*=-1;
    }

    int first=aOutter * bOutter;

    int outter=aOutter * bInner;

    int inner=aInner * bOutter;

    int last=aInner * bInner;

    int real=first + (last * -1);

    int imaginary=outter + inner;

    string result{};

    result+=to_string(real);

    result+="+";

    result+=to_string(imaginary);

    result+="i";

    return result;
}