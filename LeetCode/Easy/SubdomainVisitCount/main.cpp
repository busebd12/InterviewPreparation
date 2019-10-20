#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

/*
 * Approaches:
 *
 * 1) Do the following:
 *
 * a) For each count-paired domain, initialize a stringstream with the cpdomain string and then parse out the
 * number of times the domain has been visited and the domain string. Then, if the domain is not in the hashtable,
 * we add it and map it to the number of times it has been visited. If the domain has been seen before, just increment
 * the number of times it has been visited by its visited count. Next, we parse out all subdomains from the domain.
 * If the subdomain has not seen before, then map it to its visited count. If it has been seen before, then we increment
 * the number of it has been seen by the domain's visited count. After looping through all the domains, we build the
 * count-paired domains strings and add them to our vector<string> result.
 *
 * Time complexity: O(n * L) [where n is the number of count-paired domains and L is the average length of a count-paired domain]
 * Space complexity: O(number of count-paired domains and number of subdomains for each count-paired domains)
 *
 * 2) Same logic as the first solution except that we use getline instead of >> when parsing the count-paired domain strings.
 *
 * Time complexity: O(n * L) [where n is the number of count-paired domains and L is the average length of a count-paired domain]
 * Space complexity: O(number of count-paired domains and number of subdomains for each count-paired domains)
 */

vector<string> subdomainVisits(vector<string>& cpdomains)
{
    vector<string> result;

    if(cpdomains.empty())
    {
        return result;
    }

    unordered_map<string, int> hashtable;

    for(string & cpdomain : cpdomains)
    {
        stringstream ss(cpdomain);

        int count=0;

        string buffer{};

        int visitedCount=0;

        string domain{};

        while(ss >> buffer)
        {
            if(count==0)
            {
                visitedCount=stoi(buffer);
            }
            else
            {
                domain=buffer;
            }

            count++;
        }

        if(!hashtable.count(domain))
        {
            hashtable[domain]=visitedCount;
        }
        else
        {
            hashtable[domain]+=visitedCount;
        }

        char period='.';

        size_t dotPosition=domain.find(period);

        while(dotPosition!=string::npos)
        {
            string subdomain(domain.substr(dotPosition+1));

            if(!hashtable.count(subdomain))
            {
                hashtable[subdomain]=visitedCount;
            }
            else
            {
                hashtable[subdomain]+=visitedCount;
            }

            dotPosition=domain.find(period, dotPosition+1);
        }
    }

    for(auto & element : hashtable)
    {
        string cpdomain{};

        cpdomain+=to_string(element.second);

        cpdomain+=" ";

        cpdomain+=element.first;

        result.push_back(cpdomain);
    }

    return result;
}

vector<string> subdomainVisits(vector<string>& cpdomains)
{
    vector<string> result;

    if(cpdomains.empty())
    {
        return result;
    }

    unordered_map<string, int> hashtable;

    for(string & cpdomain : cpdomains)
    {
        stringstream ss(cpdomain);

        int count=0;

        string buffer{};

        int visitedCount=0;

        string domain{};

        while(getline(ss, buffer, ' '))
        {
            if(count==0)
            {
                visitedCount=stoi(buffer);
            }
            else
            {
                domain=buffer;
            }

            count++;
        }

        if(!hashtable.count(domain))
        {
            hashtable[domain]=visitedCount;
        }
        else
        {
            hashtable[domain]+=visitedCount;
        }

        char period='.';

        size_t dotPosition=domain.find(period);

        while(dotPosition!=string::npos)
        {
            string subdomain(domain.substr(dotPosition+1));

            if(!hashtable.count(subdomain))
            {
                hashtable[subdomain]=visitedCount;
            }
            else
            {
                hashtable[subdomain]+=visitedCount;
            }

            dotPosition=domain.find(period, dotPosition+1);
        }
    }

    for(auto & element : hashtable)
    {
        string cpdomain(to_string(element.second) + " " + element.first);

        result.push_back(cpdomain);
    }

    return result;
}