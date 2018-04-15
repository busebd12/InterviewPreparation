#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//First solution: generate all permutations, store them in a vector, retrieve the kth one from the vector and convert it to a string
//However, got time limit exceeded
void getPermutationsHelper(vector<vector<int>> & permutations, vector<int> permutation, vector<int> nums, int k, bool & done)
{
    if(permutation.size()==nums.size())
    {
        permutations.emplace_back(permutation);

        if(permutations.size()==k)
        {
            done=true;

            return;
        }
    }
    else
    {
        for(int index=0,numsSize=int(nums.size());index<numsSize;++index)
        {
            if(find(begin(permutation), end(permutation), nums[index])!=end(permutation))
            {
                continue;
            }

            permutation.emplace_back(nums[index]);

            getPermutationsHelper(permutations, permutation, nums, k, done);

            if(done)
            {
                return;
            }

            permutation.pop_back();
        }
    }
}

string getPermutationBruteForce(int n, int k)
{
    vector<vector<int>> permutations;

    string result{};

    if(n==0)
    {
        return result;
    }

    vector<int> nums;

    vector<int> permutation;

    for(int i=1;i<=n;++i)
    {
        nums.emplace_back(i);
    }

    bool done=false;

    getPermutationsHelper(permutations, permutation, nums, k, done);

    for(int index=0,permutationSize=int(permutations[k-1].size());index<permutationSize;++index)
    {
        char numChar='0' + permutations[k-1][index];

        result+=numChar;
    }

    return result;
}

//Second solution: generate the next permutation until we reach the kth permutation using hand-rolled next_permutation function
//This solution also got time limited exceeded
string getNextPermutation(const string & numbers)
{
    string nextPermutation=numbers;

    const int numbersSize=int(numbers.size());

    int endOfLongestIncreasingSuffix=numbersSize-1;

    //find the end of the longest increasing suffix
    while(nextPermutation[endOfLongestIncreasingSuffix-1]-'0' >= nextPermutation[endOfLongestIncreasingSuffix]-'0')
    {
        --endOfLongestIncreasingSuffix;
    }

    //we are at the beginning of the string, so the next 'larger' permutation is the string itself
    if(endOfLongestIncreasingSuffix <= 0)
    {
        return nextPermutation;
    }


    int pivot=endOfLongestIncreasingSuffix-1;

    int index=numbersSize-1;

    //find the index of the first number, starting from the end, that is larger than the pivot number
    while(nextPermutation[index]-'0' <= nextPermutation[pivot]-'0')
    {
        --index;
    }

    swap(nextPermutation[pivot], nextPermutation[index]);

    auto startOfSuffix=begin(nextPermutation)+(pivot+1);

    reverse(startOfSuffix, end(nextPermutation));

    return nextPermutation;
}

//Third solution: still uses the idea of generating the next permutation based on the previous one until we have the kth permutation
//However, using the next_permutation function provided by the C++ STL, which is faster than than my hand-rolled one above
string getPermutation(int n, int k)
{
    string result{};

    string numbers{};

    for(int i=1;i<=n;++i)
    {
        numbers+=('0' + i);
    }

    if(k==1)
    {
        return numbers;
    }

    int count=2;

    do
    {
        next_permutation(begin(numbers), end(numbers));

        result=numbers;

        ++count;
    }
    while(count <= k);

    return result;
}