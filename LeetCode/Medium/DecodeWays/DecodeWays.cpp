#include <iostream>
#include <map>
#include <string>
using namespace std;

void traverse(map<int, char> table, string s, int step, int & ways)
{
    const int stringSize=int(s.size());

    if(step > 2)
    {
        return;
    }

    if(step==1)
    {
        int validCharacters=0;

        for(int index=0;index<stringSize;++index)
        {
            cout << "Searching for target: " << s[index]-'0' << endl;

            cout << endl;

            if(table.find(s[index]-'0')!=end(table))
            {
                cout << "Found target: " << s[index]-'0' << endl;

                cout << endl;

                validCharacters++;
            }
            else
            {
                --validCharacters;
            }
        }

        cout << "Valid characters: " << validCharacters << endl;

        cout << endl;

        ways+=((validCharacters==stringSize) ? 1 : 0);
    }
    else
    {
        cout << "STEP: " << step << endl;

        cout << endl;

        int start=0;

        while(true)
        {
            if((start + step) > stringSize)
            {
                break;
            }
            else
            {
                int validCharacters=0;

                int index=start;

                string target="";

                for(int count=0;count<=step-1;++count,++index)
                {
                    target+=s[index];
                }

                cout << "Searching for target: " << target << endl;

                cout << endl;

                if(target[0]!='0')
                {
                    if(table.find(stoi(target))!=end(table))
                    {
                        validCharacters+=target.size();
                    }
                }

                cout << "Valid characters: " << validCharacters << endl;

                cout << endl;

                ways+=((validCharacters==stringSize) ? 1 : 0);

                cout << "index: " << index << endl;

                cout << endl;

                start=index;

                cout << "start: " << start << endl;

                cout << endl;
            }
        }
    }

    traverse(table, s, step+1, ways);
}

void populateMap(map<int, char> & table)
{
    char c='a';

    for(int count=1;count<=26;++count,++c)
    {
        table[count]=c;
    }
}

int numDecodings(string s)
{
    int ways=0;

    if(s.empty())
    {
        return ways;
    }

    map<int, char> table;

    populateMap(table);

    int step=1;

    traverse(table, s, step, ways);

    return ways;
}

int main()
{
    //string s="6065812287883668764831544958683283296479682877898293612168136334983851946827579555449329483852397155";

    string s="01";

    int ways=numDecodings(s);

    cout << "Ways to decode " << s << ": " << ways << endl;
}