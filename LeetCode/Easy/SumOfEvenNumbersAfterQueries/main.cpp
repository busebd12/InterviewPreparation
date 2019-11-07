#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * Approaches:
 *
 * 1. Brute force. Execute each query and then loop over the input vector and sum up only the even numbers.
 *
 * Time complexity: O(q * n) [where q is the number of queries and n is the size of the input vector]
 * Space complexity: O(q)
 *
 * 2. Only keep track of the even numbers. We use a hashtable (unordered_map<int, int>) to map each index of an even
 * number to the even number at that index. Each time we apply a query, we update the hashtable in the following cases:
 *
 * a) If the value of an already tracked even number changes
 * b) If an even number in the hashtable becomes odd
 * c) If a previously odd number becomes even.
 *
 * Then, for each query we just sum up the even numbers in hashtable.
 *
 * Time complexity: O(q * e) [where q is the number of queries and e is the number of even numbers]
 * Space complexity: O(e)
 */

int sumOfEvenValues(const vector<int> & A)
{
    int sum=0;

    for(int number : A)
    {
        if((number % 2)==0)
        {
            sum+=number;
        }
    }

    return sum;
}

vector<int> sumEvenAfterQueries(vector<int> & A, vector<vector<int>> & queries)
{
    int Q=int(queries.size());

    int n=int(A.size());

    vector<int> result(Q, 0);

    for(int i=0;i<Q;++i)
    {
        int index=queries[i][1];

        int value=queries[i][0];

        A[index]+=value;

        sumOfEvenValues(A);

        result[i]=sumOfEvenValues(A);
    }

    return result;
}

int sumOfEvenValues(const unordered_map<int, int> & evenValues)
{
    int sum=0;

    for(const auto & element : evenValues)
    {
        sum+=element.second;
    }

    return sum;
}

vector<int> sumEvenAfterQueries(vector<int> & A, vector<vector<int>> & queries)
{
    int Q=int(queries.size());

    int n=int(A.size());

    vector<int> result(Q, 0);

    unordered_map<int, int> evenValues;

    for(int i=0;i<n;++i)
    {
        if(A[i]%2==0)
        {
            evenValues[i]=A[i];
        }
    }

    for(int i=0;i<Q;++i)
    {
        int index=queries[i][1];

        int value=queries[i][0];

        A[index]+=value;

        if(A[index]%2==0)
        {
            if(!evenValues.count(index))
            {
                evenValues[index]=A[index];
            }
            else
            {
                if(evenValues[index]!=A[index])
                {
                    evenValues[index]=A[index];
                }
            }
        }
        else
        {
            if(evenValues.count(index))
            {
                evenValues.erase(index);
            }
        }

        result[i]=sumOfEvenValues(evenValues);
    }

    return result;
}