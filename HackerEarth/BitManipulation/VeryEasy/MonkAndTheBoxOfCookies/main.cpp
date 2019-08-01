#include <iostream>
#include <vector>
using namespace std;

int getBit(vector<int> & frequencies)
{
    int maxFrequency=frequencies[0];

    int n=int(frequencies.size());

    for(int index=0;index<n;++index)
    {
        if(frequencies[index] > maxFrequency)
        {
            maxFrequency=frequencies[index];
        }
    }

    int result=-1;

    for(int index=0;index<n;++index)
    {
        if(frequencies[index]==maxFrequency)
        {
            if(result==-1)
            {
                result=index;
            }
            else if(index < result)
            {
                result=index;
            }
        }
    }

    return result;
}

int main(int argc, char** argv)
{
    int T=0;

    cin >> T;

    for(int testCase=0;testCase<T;++testCase)
    {
        int N=0;

        cin >> N;

        vector<int> frequencies(32, 0);

        for(int count=0;count<N;++count)
        {
            long int number=0;

            cin >> number;

            for(int bit=0;bit<32;++bit)
            {
                if(number & (1 << bit))
                {
                    frequencies[bit]++;
                }
            }
        }

        cout << getBit(frequencies) << endl;
    }

    return 0;
}