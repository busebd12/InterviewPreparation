#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    int T=0;

    cin >> T;

    for(int testCase=0;testCase<T;++testCase)
    {
        string s1{};

        string s2{};

        cin >> s1;

        cin >> s2;

        vector<int> s1Letters(26);

        vector<int> s2Letters(26);

        int n=int(s1.size());

        int m=int(s2.size());

        for(int i=0;i<n;++i)
        {
            int c1=s1[i]-'a';

            s1Letters[c1]++;
        }

        for(int j=0;j<m;++j)
        {
            int c2=s2[j]-'a';

            s2Letters[c2]++;
        }

        int number;

        for(number=0;number<26;++number)
        {
            if(s1Letters[number] > 0 && s2Letters[number] > 0)
            {
                cout << "Yes" << endl;

                break;
            }
        }

        if(number==26)
        {
            cout << "No" << endl;
        }
    }

    return 0;
}