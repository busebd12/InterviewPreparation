#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    int T=0;

    cin >> T;

    for(int testCase=0;testCase<T;++testCase)
    {
        int Z=0;

        int N=0;

        cin >> Z;

        cin >> N;

        bool found=false;

        vector<int> numbers(N);

        for(int count=0;count<N;++count)
        {
            int number=0;

            cin >> number;

            numbers[count]=number;
        }

        int result=numbers[0] & Z;

        for(int i=1;i<N;++i)
        {
            if(result==0)
            {
                found=true;

                break;
            }
            else
            {
                result=result & numbers[i];

                if(result==0)
                {
                    found=true;

                    break;
                }
            }
        }

        if(found)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}