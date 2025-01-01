#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

/*
 * Solutions:
 *
 * 1. We map each domino in A to the indices that would need to be flipped in B in order to make A homogenous.
 * Then, we map each domino in B to the indices that would need to flipped in A in order to make B homogenous.
 * Our answer will be the size of the smallest number of indices from A and B that match.
 *
 * Time complexity: O(n + + ad + bd) [where n is the length of A, ad is the number of unique numbers in A, and bd is the number of unique numbers in B]
 * Space complexity: O(ad + bd)
 *
 * 2. Brute force. We fix each domino in A and try to flip the rest so that A is homogenous. Then, we do the same thing for B.
 *
 * Time complexity: O(n^2) [where n is the length of A and B]
 * Space complexity: O(m) [where m is number of flipped indices]
 *
 * 3. Slight improvement to brute force. Instead of trying every domino, we only try the dominoes that appear in both
 * A and B.
 *
 * Time complexity: O(n^2) [where n is the length of A and B]
 * Space complexity: O(m) [where m is number of flipped indices]
 *
 * 4. For both A and B, calculate the number that appears the most, and then try to flip all the other dominoes to match
 * that majority element. The answer will be the minimum number of flips between A and B.
 *
 * Time complexity: O(n) [where n is the length of A and B]
 * Space complexity: O(au + bu) [where au is the number of unique numbers from A and bu is the number of unique elements from B]
 */

int helper(std::vector<int> & first, std::vector<int> & second)
{
    std::unordered_map<int, std::vector<int>> firstMap;

    std::unordered_map<int, std::vector<int>> secondMap;

    auto n=first.size();

    auto m=second.size();

    for(const auto & number : first)
    {
        if(!firstMap.count(number))
        {
            firstMap.insert(std::make_pair(number, std::vector<int>()));
        }
    }

    for(auto & element : firstMap)
    {
        for(auto i=0;i<n;++i)
        {
            if(first[i]!=element.first)
            {
                element.second.push_back(i);
            }
        }
    }

    for(const auto & number : second)
    {
        if(!secondMap.count(number))
        {
            secondMap.insert(std::make_pair(number, std::vector<int>()));
        }
    }

    for(auto & element : firstMap)
    {
        if(secondMap.count(element.first))
        {
            for(auto j=0;j<m;++j)
            {
                if(second[j]==element.first)
                {
                    secondMap[element.first].push_back(j);
                }
            }
        }
    }

    int rotations=-1;

    for(auto & element : firstMap)
    {
        if(secondMap.count(element.first))
        {
            if(!element.second.empty() && !secondMap[element.first].empty())
            {
                if(std::includes(secondMap[element.first].begin(), secondMap[element.first].end(), element.second.begin(), element.second.end()))
                {
                    if(rotations==-1)
                    {
                        rotations=static_cast<int>(element.second.size());
                    }
                    else
                    {
                        rotations=std::min(rotations, static_cast<int>(element.second.size()));
                    }
                }
            }
        }
    }

    return rotations;
}

int minDominoRotations(std::vector<int> & A, std::vector<int> & B)
{
    int result=-1;

    if(A.empty() && B.empty())
    {
        return result;
    }

    if(A.empty())
    {
        if(std::all_of(B.begin(), B.end(), [&B] (const auto & element) {return element==B[0];}))
        {
            return 0;
        }
        else
        {
            return result;
        }
    }

    if(B.empty())
    {
        if(std::all_of(A.begin(), A.end(), [&A] (const auto & element) {return element==A[0];}))
        {
            return 0;
        }
        else
        {
            return result;
        }
    }

    if(std::equal(A.begin(), A.end(), B.begin(), B.end()))
    {
        return 0;
    }
    else
    {
        if(std::all_of(A.begin(), A.end(), [&A] (const auto & element) {return element==A[0];}) || std::all_of(B.begin(), B.end(), [&B] (const auto & element) {return element==B[0];}))
        {
            return 0;
        }
    }

    int aRotations=helper(A, B);

    int bRotations=helper(B, A);

    if(aRotations > -1)
    {
        if(result==-1)
        {
            result=aRotations;
        }

        result=std::min(result, aRotations);
    }

    if(bRotations > -1)
    {
        if(result==-1)
        {
            result=bRotations;
        }

        result=std::min(result, bRotations);
    }

    return result;
}

int minDominoRotations(std::vector<int> & A, std::vector<int> & B)
{
    int result=-1;

    if(A.empty() && B.empty())
    {
        return result;
    }

    if(A.empty())
    {
        if(std::all_of(B.begin(), B.end(), [&B] (const auto & element) {return element==B[0];}))
        {
            return 0;
        }
        else
        {
            return result;
        }
    }

    if(B.empty())
    {
        if(std::all_of(A.begin(), A.end(), [&A] (const auto & element) {return element==A[0];}))
        {
            return 0;
        }
        else
        {
            return result;
        }
    }

    if(std::equal(A.begin(), A.end(), B.begin(), B.end()))
    {
        return 0;
    }
    else
    {
        if(std::all_of(A.begin(), A.end(), [&A] (const auto & element) {return element==A[0];}) || std::all_of(B.begin(), B.end(), [&B] (const auto & element) {return element==B[0];}))
        {
            return 0;
        }
    }

    auto n=A.size();

    for(auto i=0;i<n;++i)
    {
        int targetDomino=A[i];

        std::vector<int> flippedIndices;

        for(int j=0;j<n;++j)
        {
            if(A[j]!=targetDomino && B[j]==targetDomino)
            {
                std::swap(A[j], B[j]);

                flippedIndices.push_back(j);
            }
        }

        if(std::all_of(A.begin(), A.end(), [&A] (const auto & element) {return element==A[0];}))
        {
            if(result==-1)
            {
                result=static_cast<int>(flippedIndices.size());
            }
            else
            {
                result=std::min(result, static_cast<int>(flippedIndices.size()));
            }
        }

        for(const auto & index : flippedIndices)
        {
            std::swap(A[index], B[index]);
        }
    }

    for(auto i=0;i<n;++i)
    {
        int targetDomino=B[i];

        std::vector<int> flippedIndices;

        for(int j=0;j<n;++j)
        {
            if(B[j]!=targetDomino && A[j]==targetDomino)
            {
                std::swap(A[j], B[j]);

                flippedIndices.push_back(j);
            }
        }

        if(std::all_of(B.begin(), B.end(), [&B] (const auto & element) {return element==B[0];}))
        {
            if(result==-1)
            {
                result=static_cast<int>(flippedIndices.size());
            }
            else
            {
                result=std::min(result, static_cast<int>(flippedIndices.size()));
            }
        }

        for(const auto & index : flippedIndices)
        {
            std::swap(A[index], B[index]);
        }
    }

    return result;
}

int countRotations(std::vector<int> first, std::vector<int> second, int n, int targetDomino)
{
    int rotations=0;

    for(auto i=0;i<n;++i)
    {
        if(first[i]!=targetDomino && second[i]==targetDomino)
        {
            std::swap(first[i], second[i]);

            rotations++;
        }
    }

    return std::all_of(first.begin(), first.end(), [&first] (const auto & element) {return element==first[0];}) ? rotations : -1;
}

int minDominoRotations(std::vector<int> & A, std::vector<int> & B)
{
    int result=-1;

    if(A.empty() && B.empty())
    {
        return result;
    }

    if(A.empty())
    {
        if(std::all_of(B.begin(), B.end(), [&B] (const auto & element) {return element==B[0];}))
        {
            return 0;
        }
        else
        {
            return result;
        }
    }

    if(B.empty())
    {
        if(std::all_of(A.begin(), A.end(), [&A] (const auto & element) {return element==A[0];}))
        {
            return 0;
        }
        else
        {
            return result;
        }
    }

    if(std::equal(A.begin(), A.end(), B.begin(), B.end()))
    {
        return 0;
    }
    else
    {
        if(std::all_of(A.begin(), A.end(), [&A] (const auto & element) {return element==A[0];}) || std::all_of(B.begin(), B.end(), [&B] (const auto & element) {return element==B[0];}))
        {
            return 0;
        }
    }

    auto n=A.size();

    std::unordered_map<int, int> aMap;

    std::unordered_map<int, int> bMap;

    for(const auto & number : A)
    {
        aMap[number]++;
    }

    for(const auto & number : B)
    {
        bMap[number]++;
    }

    for(auto & element : aMap)
    {
        if(bMap.count(element.first))
        {
            if(element.second + bMap[element.first] >= n)
            {
                int aRotations=countRotations(A, B, n, element.first);

                if(result==-1)
                {
                    result=aRotations;
                }
                else
                {
                    result=std::min(result, aRotations);
                }
            }
        }
    }

    for(auto & element : bMap)
    {
        if(aMap.count(element.first))
        {
            if(element.second + aMap[element.first] >= n)
            {
                int bRotations=countRotations(B, A, n, element.first);

                if(result==-1)
                {
                    result=bRotations;
                }
                else
                {
                    result=std::min(result, bRotations);
                }
            }
        }
    }

    return result;
}

int countRotations(std::vector<int> first, std::vector<int> second, int n, int targetDomino)
{
    int rotations=0;

    for(auto i=0;i<n;++i)
    {
        if(first[i]!=targetDomino && second[i]==targetDomino)
        {
            std::swap(first[i], second[i]);

            rotations++;
        }
    }

    return std::all_of(first.begin(), first.end(), [&first] (const auto & element) {return element==first[0];}) ? rotations : -1;
}

int minDominoRotations(std::vector<int> & A, std::vector<int> & B)
{
    int result=-1;

    if(A.empty() && B.empty())
    {
        return result;
    }

    if(A.empty())
    {
        if(std::all_of(B.begin(), B.end(), [&B] (const auto & element) {return element==B[0];}))
        {
            return 0;
        }
        else
        {
            return result;
        }
    }

    if(B.empty())
    {
        if(std::all_of(A.begin(), A.end(), [&A] (const auto & element) {return element==A[0];}))
        {
            return 0;
        }
        else
        {
            return result;
        }
    }

    if(std::equal(A.begin(), A.end(), B.begin(), B.end()))
    {
        return 0;
    }
    else
    {
        if(std::all_of(A.begin(), A.end(), [&A] (const auto & element) {return element==A[0];}) || std::all_of(B.begin(), B.end(), [&B] (const auto & element) {return element==B[0];}))
        {
            return 0;
        }
    }

    auto n=A.size();

    std::unordered_map<int, int> aMap;

    std::unordered_map<int, int> bMap;

    for(const auto & number : A)
    {
        aMap[number]++;
    }

    for(const auto & number : B)
    {
        bMap[number]++;
    }

    auto aItr=(std::max_element(aMap.begin(), aMap.end(), [] (const auto & e1, const auto & e2) {return e1.second < e2.second;}));

    int majorityDominoInA=aItr->first;

    int aRotations=countRotations(A, B, n, majorityDominoInA);

    if(result==-1)
    {
        result=aRotations;
    }

    result=std::min(result, aRotations);

    auto bItr=(std::max_element(aMap.begin(), aMap.end(), [] (const auto & e1, const auto & e2) {return e1.second < e2.second;}));

    int majorityDominoInB=bItr->first;

    int bRotations=countRotations(B, A, n, majorityDominoInB);

    result==-1 ? result=bRotations : result=std::min(result, bRotations);

    return result;
}

class Solution
{
    public:
        int minDominoRotations(vector<int> & tops, vector<int> & bottoms)
        {
            int result=numeric_limits<int>::max();

            int n=tops.size();

            int firstTop=tops[0];

            bool allTopsTheSame=all_of(tops.begin(), tops.end(), [&firstTop] (int & value) {return value==firstTop;});

            int firstBottom=bottoms[0];

            bool allBottomsTheSame=all_of(bottoms.begin(), bottoms.end(), [&firstBottom] (int & value) {return value==firstBottom;});

            if(allTopsTheSame==true or allBottomsTheSame==true)
            {
                return 0;
            }

            for(int top=1;top<7;top++)
            {
                vector<bool> used(n, false);

                for(int i=0;i<n;i++)
                {
                    if(tops[i]==top)
                    {
                        used[i]=true;
                    }
                }

                int flips=0;

                int flipsNeeded=0;

                for(int i=0;i<n;i++)
                {
                    if(used[i]==false)
                    {
                        flipsNeeded+=1;
                        
                        if(bottoms[i]==top)
                        {
                            flips+=1;
                        }
                    }
                }

                if(flips==flipsNeeded)
                {
                    result=min(result, flips);
                }
            }

            for(int bottom=1;bottom<7;bottom++)
            {
                vector<bool> used(n, false);

                for(int i=0;i<n;i++)
                {
                    if(bottoms[i]==bottom)
                    {
                        used[i]=true;
                    }
                }

                int flips=0;

                int flipsNeeded=0;

                for(int i=0;i<n;i++)
                {
                    if(used[i]==false)
                    {
                        flipsNeeded+=1;
                        
                        if(tops[i]==bottom)
                        {
                            flips+=1;
                        }
                    }
                }

                if(flips==flipsNeeded)
                {
                    result=min(result, flips);
                }
            }

            return (result==numeric_limits<int>::max()) ? -1 : result;
        }
};