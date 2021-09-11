#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 * Approach: for each e-mail address in the emails vector, we create a string, address, that will hold
 * the result of our parsing the current e-mail address according the following rules:
 *
 * If we see a . character in the local name (local name is the string before the @ sign) and it is before the @ sign,
 * then we don't add the character to our address string.
 * If we see a + character, then we skip all characters after it until we reach the @ sign.
 * Else, we add the current character to our address string.
 *
 * After parsing the e-mail address, we add our address string to our unordered_set<string> uniqueEmails.
 * Our answer will be the size of uniqueEmails.
 *
 * Time complexity: O(n * L) [where n is the length of our input vector<string> emails and L is the average length of an e-mail address]
 * Space complexity: O(n)
 */

int numUniqueEmails(vector<string> & emails)
{
    unordered_set<string> uniqueEmails;

    for(const string & email : emails)
    {
        string address{};

        int e=int(email.size());

        bool afterAtSign=false;

        for(int i=0;i<e;)
        {
            if(email[i]=='.' && !afterAtSign)
            {
                i++;
            }
            else if(email[i]=='+')
            {
                while(email[i]!='@' && i < e)
                {
                    i++;
                }
            }
            else
            {
                if(email[i]=='@')
                {
                    afterAtSign=true;
                }

                address+=email[i];

                i++;
            }
        }

        uniqueEmails.insert(address);
    }

    return int(uniqueEmails.size());
}