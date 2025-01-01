#include <deque>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
    public:
        string largestPalindromic(string num)
        {
            string result="";

            bool allZeros=(num.find_first_not_of('0')==string::npos);

            if(allZeros==true)
            {
                result.push_back('0');

                return result;
            }

            unordered_map<char, int> frequencies;

            for(char digit : num)
            {
                if(frequencies.find(digit)==frequencies.end())
                {
                    frequencies.emplace(digit, 0);
                }

                frequencies[digit]+=1;
            }

            auto heapComparator=[] (pair<char, int> & lhs, pair<char, int> & rhs)
            {
                int lhsDigit=lhs.first - '0';

                int rhsDigit=rhs.first - '0';

                return lhsDigit < rhsDigit;
            };

            priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(heapComparator)> evenFrequenciesMaxHeap(heapComparator);

            priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(heapComparator)> oddFrequenciesMaxHeap(heapComparator);

            for(auto & [digit, frequency] : frequencies)
            {
                if((frequency % 2)==0)
                {
                    evenFrequenciesMaxHeap.emplace(digit, frequency);
                }
                else
                {
                    int evenFrequency=frequency - 1;

                    if(evenFrequency > 0)
                    {
                        evenFrequenciesMaxHeap.emplace(digit, evenFrequency);
                    }

                    int oddFrequency=frequency - evenFrequency;

                    oddFrequenciesMaxHeap.emplace(digit, oddFrequency);
                }
            }

            deque<char> leftHalf;

            deque<char> rightHalf;

            if(!evenFrequenciesMaxHeap.empty() and evenFrequenciesMaxHeap.top().first=='0')
            {
                evenFrequenciesMaxHeap.pop();
            }

            while(!evenFrequenciesMaxHeap.empty())
            {
                auto [digit, frequency]=evenFrequenciesMaxHeap.top();

                evenFrequenciesMaxHeap.pop();

                for(int count=0;count<frequency/2;count++)
                {
                    leftHalf.push_back(digit);

                    rightHalf.push_front(digit);
                }
            }

            if(!oddFrequenciesMaxHeap.empty())
            {
                leftHalf.push_back(oddFrequenciesMaxHeap.top().first);

                oddFrequenciesMaxHeap.pop();
            }

            while(!leftHalf.empty())
            {
                result.push_back(leftHalf.front());

                leftHalf.pop_front();
            }

            while(!rightHalf.empty())
            {
                result.push_back(rightHalf.front());

                rightHalf.pop_front();
            }

            return result;
        }
};

class Solution
{
    public:
        string largestPalindromic(string num)
        {
            string result="";

            bool allZeros=(num.find_first_not_of('0')==string::npos);

            if(allZeros==true)
            {
                result.push_back('0');

                return result;
            }

            vector<int> frequencies(10, 0);

            for(char character : num)
            {
                int digit=character - '0';

                frequencies[digit]+=1;
            }

            deque<char> leftHalf;

            deque<char> rightHalf;

            int singleDigit=-1;

            for(int digit=9;digit>=0;digit--)
            {
                if(digit==0 and leftHalf.empty() and rightHalf.empty())
                {
                    continue;
                }

                while(frequencies[digit] > 1)
                {
                    leftHalf.emplace_back(digit + '0');

                    rightHalf.emplace_front(digit + '0');

                    frequencies[digit]-=2;
                }

                if(frequencies[digit]==1 and singleDigit==-1)
                {
                    singleDigit=digit;
                }
            }

            if(singleDigit!=-1)
            {
                leftHalf.emplace_back(singleDigit + '0');
            }

            while(!leftHalf.empty())
            {
                result.push_back(leftHalf.front());

                leftHalf.pop_front();
            }

            while(!rightHalf.empty())
            {
                result.push_back(rightHalf.front());

                rightHalf.pop_front();
            }

            return result;
        }
};