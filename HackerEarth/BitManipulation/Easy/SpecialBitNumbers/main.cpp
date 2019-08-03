#include <iostream>
#include <vector>
using namespace std;

//The code commented out time out on the longer test cases
/*bool hasConsecutiveOnes(long long int number)
{
    int consecutiveOnes=0;

    while(number)
    {
        number=number & (number << 1);

        consecutiveOnes++;
    }

    return consecutiveOnes >= 2;
}

int solve(vector<long long int> & numbers, long long int L, long long int R)
{
    int count=0;

    for(int index=L-1;index<R;++index)
    {
        long long int current=numbers[index];

        if(hasConsecutiveOnes(current))
        {
            count++;
        }
    }

    return count;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    long long int N=0;

    long long int Q=0;

    cin >> N;

    cin >> Q;

    vector<long long int> numbers(N);

    for(int index=0;index<N;++index)
    {
        long long int number=0;

        cin >> number;

        numbers[index]=number;
    }

    for(int query=0;query<Q;++query)
    {
        long long int L=0;

        long long int R=0;

        cin >> L;

        cin >> R;

        cout << solve(numbers, L, R) << endl;
    }

    return 0;
}*/

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int N=0;

    int Q=0;

    cin >> N;

    cin >> Q;

    vector<unsigned long long int> counts(N);

    for(int count=0;count<N;++count)
    {
        long long int number=0;

        cin >> number;

        vector<int> digits;

        while(number)
        {
            digits.push_back(number & 1);

            number>>=1;
        }

        int consecutiveOnes=0;

        for(int index=0;index<digits.size()-1;++index)
        {
            if(digits[index]==1 && digits[index+1]==1)
            {
                consecutiveOnes++;
            }
        }

        counts[count]=consecutiveOnes;
    }

    for(int query=0;query<Q;++query)
    {
        int L=0;

        int R=0;

        cin >> L;

        cin >> R;

        int answer=0;

        for(int i=L-1;i<R;++i)
        {
            if(counts[i] >= 1)
            {
                answer++;
            }
        }

        cout << answer << endl;
    }
}