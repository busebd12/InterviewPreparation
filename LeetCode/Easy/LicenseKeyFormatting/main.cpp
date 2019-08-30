#include <iostream>
#include <deque>
#include <string>
#include <cctype>
using namespace std;

/*
 * Approaches:
 *
 * 1) We count the number of non-dash characters and put those characters into a deque.
 * Then, either the number of characters is divisible by K or not divisible by K.
 * If the number of characters is divisible by K, then we simply just loop over the deque,
 * form the number of K groups of characters,and append them to the result string (with the appropriate number of '-'s, of course).
 * If the number of characters is not divisible by K, then while the number of characters
 * is not divisible by K, we append characters to our first license group of characters.
 * Then, we append the group to our result. At this point, the number of characters
 * is, once again, divisible by K, and we can form the rest of the group of characters
 * like we did with the first case.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(m) [where m is the number of non '-' characters in the string]
 *
 * 2) We simply iterate over the string backwards and form the appropriate size groups of K characters
 * and append them to our result string (with the correct number of '-'s, of course). If, after
 * we have finished looping if we still have a group of characters left, then we append it.
 * Then, we remove the last '-' from the end of the string.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(m) [where m is the number of groups of K characters (or less) that make up the formatted license]
 */

string licenseKeyFormatting(string S, int K)
{
    string result{};

    if(S.empty() || K==0)
    {
        return result;
    }

    int characters=0;

    int n=int(S.size());

    deque<char> dq;

    for(int i=0;i<n;++i)
    {
        if(isalnum(S[i]) && S[i]!='-')
        {
            dq.emplace_back(S[i]);

            characters++;
        }
    }

    if(characters%K==0)
    {
        while(!dq.empty())
        {
            string part{};

            for(int count=0;count<K;++count)
            {
                char c=dq.front();

                if(isalpha(c))
                {
                    part+=toupper(c);
                }
                else
                {
                    part+=c;
                }

                dq.pop_front();
            }

            result+=part;

            result+='-';
        }
    }
    else
    {
        while(!dq.empty())
        {
            string part{};

            while(dq.size()%K!=0)
            {
                char c=dq.front();

                if(isalpha(c))
                {
                    part+=toupper(c);
                }
                else
                {
                    part+=c;
                }

                dq.pop_front();
            }

            if(!part.empty())
            {
                result+=part;

                result+='-';
            }
            else
            {
                for(int count=0;count<K;++count)
                {
                    char c=dq.front();

                    if(isalpha(c))
                    {
                        part+=toupper(c);
                    }
                    else
                    {
                        part+=c;
                    }

                    dq.pop_front();
                }

                result+=part;

                result+='-';
            }
        }
    }

    result.pop_back();

    return result;
}

string licenseKeyFormatting(string S, int K)
{
    string result{};

    if(S.empty() || K==0)
    {
        return result;
    }

    string group;

    group.reserve(K);

    int n=int(S.size());

    for(int i=n-1;i>=0;--i)
    {
        if(S[i]!='-')
        {
            group+=toupper(S[i]);

            if(group.length()==K)
            {
                result+=("-" + group);

                group.clear();
            }
        }
    }

    if(!group.empty())
    {
        result+=("-" + group);
    }

    reverse(result.begin(), result.end());

    if(!result.empty())
    {
        result.erase(result.size()-1, 1);
    }

    return result;
}