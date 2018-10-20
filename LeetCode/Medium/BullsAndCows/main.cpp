#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;


string getHint(string secret, string guess)
{
    string hint{};

    if(secret.empty() || guess.empty())
    {
        return hint;
    }

    unordered_map<char, pair<int, bool>> frequencies;

    unordered_map<char, pair<int, int>> table;

    for(auto & letter : secret)
    {
        if(frequencies.find(letter)==end(frequencies))
        {
            frequencies.insert(make_pair(letter, make_pair(1, false)));
        }
        else
        {
            ++frequencies[letter].first;
        }
    }

    for(auto & letter : guess)
    {
        table.insert(make_pair(letter, make_pair(0, 0)));
    }

    int bulls=0;

    int cows=0;

    int n=static_cast<int>(secret.size());

    for(int i=0;i<n;++i)
    {
        if(secret[i]==guess[i])
        {
            ++table[secret[i]].first;
        }
        else
        {
            if(table.find(guess[i])!=end(table))
            {
                ++table[guess[i]].second;
            }
        }
    }

    for(int i=0;i<n;++i)
    {
        if(table.find(secret[i])!=end(table))
        {
            if(!frequencies[secret[i]].second)
            {
                int b=table[secret[i]].first;

                if(b > 0)
                {
                    int bullResult=frequencies[secret[i]].first-b;

                    bulls+=b;

                    frequencies[secret[i]].first-=b;

                    if(frequencies[secret[i]].first > 0)
                    {
                        if(table[secret[i]].second > 0)
                        {
                            while(frequencies[secret[i]].first > 0 && table[secret[i]].second > 0)
                            {
                                --table[secret[i]].second;

                                ++cows;

                                --frequencies[secret[i]].first;
                            }
                        }
                    }
                }
                else
                {
                    if(table[secret[i]].second > 0)
                    {
                        while(frequencies[secret[i]].first > 0 && table[secret[i]].second > 0)
                        {
                            --table[secret[i]].second;

                            ++cows;

                            --frequencies[secret[i]].first;
                        }
                    }
                }

                frequencies[secret[i]].second=true;
            }
        }
    }

    hint+=to_string(bulls);

    hint+='A';

    hint+=to_string(cows);

    hint+='B';

    return hint;
}