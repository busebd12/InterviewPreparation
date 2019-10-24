#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

/*
 * Approaches:
 *
 * 1) Using two stringstreams objects, parse the individual, space separated words
 * out of A and B and put them in their own hashtables (unordered_map<string, int>).
 * Then, for each word in A's hashtable that appears only once, look to see if that word
 * does not appear in B's hashtable. If it does not, then it is an uncommon word and we
 * can add it to our vector<string> result. Do the same thing for B's hashtable and return
 * our result vector.
 *
 * Time complexity: O(n + m) [where n is the length of the string A and m is the length of the string B]
 * Space complexity: O(n + m)
 *
 * 2) Since any uncommon word will only appear once, we store both A and B into one single istringstream object
 * and then parse the individual words out and store them in a hashtable. We then loop through the hashtable and
 * any word that appears only once we can add to our vector<string> result. Return our result vector.
 *
 * Time complexity: O(n + m) [where n is the length of the string A and m is the length of the string B]
 * Space complexity: O(n + m)
 */

vector<string> uncommonFromSentences(string A, string B)
{
    vector<string> result;

    unordered_map<string, int> aMap;

    unordered_map<string, int> bMap;

    stringstream ssA(A);

    string word{};

    while(ssA >> word)
    {
        aMap[word]++;
    }

    stringstream ssB(B);

    while(ssB >> word)
    {
        bMap[word]++;
    }

    for(const auto & element : aMap)
    {
        if(element.second==1)
        {
            if(!bMap.count(element.first))
            {
                result.emplace_back(element.first);
            }
        }
    }

    for(const auto & element : bMap)
    {
        if(element.second==1)
        {
            if(!aMap.count(element.first))
            {
                result.emplace_back(element.first);
            }
        }
    }

    return result;
}

vector<string> uncommonFromSentences(string A, string B)
{
    vector<string> result;

    istringstream iss(A + " " + B);

    unordered_map<string, int> hashtable;

    while(iss >> A)
    {
        hashtable[A]++;
    }

    for(const auto & element : hashtable)
    {
        if(element.second==1)
        {
            result.emplace_back(element.first);
        }
    }

    return result;
}