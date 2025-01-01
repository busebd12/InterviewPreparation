#include <algorithm>
#include <limits>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution 1: brute-force. Submission result: Time Limit Exceeded.
*/

class Solution
{
    public:
        int minWastedSpace(vector<int> & packages, vector<vector<int>> & boxes)
        {
            int result=numeric_limits<int>::max();

            const int MOD=1e9 + 7;

            int p=packages.size();

            int b=boxes.size();

            unordered_map<int, int> hashmap;

            for(int package : packages)
            {
                hashmap[package]+=1;
            }

            for(vector<int> & box : boxes)
            {
                sort(box.begin(), box.end());
            }

            for(vector<int> & box : boxes)
            {
                pair<bool, long> wastedSpacePair=getWastedSpace(hashmap, box, packages, MOD);

                if(wastedSpacePair.first==true)
                {
                    result=min(result, (int)wastedSpacePair.second);
                }
            }

            return result==numeric_limits<int>::max() ? -1 : result;
        }

        pair<bool, long> getWastedSpace(unordered_map<int, int> & hashmap, vector<int> & box, vector<int> & packages, const int MOD)
        {
            bool canFitAllPackages=true;

            long totalWastedSpace=0;

            for(auto & [package, frequency] : hashmap)
            {
                auto itr=lower_bound(box.begin(), box.end(), package);

                if(itr!=box.end())
                {
                    long size=(long)*(itr);

                    long leftOverSpace=size - (long)package;

                    long wastedSpace=(long)frequency * leftOverSpace;

                    wastedSpace=wastedSpace % MOD;

                    totalWastedSpace+=wastedSpace;

                    totalWastedSpace=totalWastedSpace % MOD;
                }
                else
                {
                    canFitAllPackages=false;

                    break;
                }
            }

            return make_pair(canFitAllPackages, totalWastedSpace);
        }
};

/*
Solution 2: better binary search application. Submission result: accepted.

Time complexity: O((p * log(p)) + b * (log(L) + (L * log(p)))) [where b=length of boxes; L=average length of element of boxes; p=length of packages]
Space complexity: O(sort) [where sort=recursive space needed for the Standard Template Library sorting algorithm]
*/

class Solution
{
    public:
        int minWastedSpace(vector<int> & packages, vector<vector<int>> & boxes)
        {
            int result=0;

            const int MOD=1e9 + 7;

            long minTotalSizeOfNeededBoxes=numeric_limits<long>::max();

            sort(packages.begin(), packages.end()); //O(p * log(p))

            for(vector<int> & box : boxes) //O(b)
            {
                sort(box.begin(), box.end()); //O(log(L))

                int largestPackage=packages.back();

                int largestBox=box.back();

                if(largestBox < largestPackage)
                {
                    continue;
                }

                long totalSizeOfNeededBoxes=getSizeOfNeededBoxes(box, packages);

                minTotalSizeOfNeededBoxes=min(minTotalSizeOfNeededBoxes, totalSizeOfNeededBoxes);
            }

            if(minTotalSizeOfNeededBoxes==numeric_limits<long>::max())
            {
                return -1;
            }

            long totalPackageSize=accumulate(packages.begin(), packages.end(), long(0));

            result=(minTotalSizeOfNeededBoxes - totalPackageSize) % MOD;

            return result;
        }

        long getSizeOfNeededBoxes(vector<int> & boxSizes, vector<int> & packages)
        {
            long totalSizeOfNeededBoxes=0;

            int startIndex=0;

            for(int & boxSize : boxSizes) //O(L)
            {
                auto firstPackageTooLargeIterator=upper_bound(packages.begin() + startIndex, packages.end(), boxSize); //O(log(p))

                int indexOfLastPackageThatFits=(firstPackageTooLargeIterator - packages.begin()) - 1;

                long packagesThatCanFit=(indexOfLastPackageThatFits - startIndex) + 1;

                long sizeOfNeededBoxes=packagesThatCanFit * boxSize;

                totalSizeOfNeededBoxes+=sizeOfNeededBoxes;

                startIndex=indexOfLastPackageThatFits + 1;
            }

            return totalSizeOfNeededBoxes;
        }
};