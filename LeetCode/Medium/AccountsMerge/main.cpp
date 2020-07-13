#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * Solution: we use the disjoint set(s) data structure. Each account and all emails associated with that account
 * is tied to one "parent". When an email belongs to two different parents, we merge the accounts (union the two different
 * subsets). Then, we just have build the output std::vector<std::string> in the proper format.
 *
 * Time complexity: O(n) [where n is the number of accounts]
 * Space complexity: O(u) [where u is the number of unique emails]
 */
class Solution
{
    public:

        int getParent(std::vector<int> & parent, int node)
        {
            while(parent[node]!=node)
            {
                node=parent[node];
            }

            return node;
        }

        std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<string>> & accounts)
        {
            std::vector<std::vector<std::string>> result;

            int n=int(accounts.size());

            std::unordered_map<std::string, int> hashtable;

            std::vector<int> disjointSets(n);

            std::iota(disjointSets.begin(), disjointSets.end(), 0);

            for(int i=0;i<n;i++)
            {
                int m=int(accounts[i].size());

                for(int j=1;j<m;j++)
                {
                    std::string email=accounts[i][j];

                    if(hashtable.count(email))
                    {
                        int p1=getParent(disjointSets, hashtable[email]);

                        int p2=getParent(disjointSets, i);

                        if(p1!=p2)
                        {
                            disjointSets[p2]=p1;
                        }
                    }
                    else
                    {
                        hashtable[email]=i;
                    }
                }
            }

            std::unordered_map<int, vector<std::string>> indexToEmailsMap;

            for(const auto & [key, value] : hashtable)
            {
                int parent=getParent(disjointSets, value);

                indexToEmailsMap[parent].emplace_back(key);
            }

            for(auto & [key, value] : indexToEmailsMap)
            {
                std::vector<std::string> mergedAccount;

                mergedAccount.emplace_back(accounts[key][0]);

                std::sort(value.begin(), value.end());

                for(const auto & email : value)
                {
                    mergedAccount.emplace_back(email);
                }

                result.emplace_back(mergedAccount);
            }

            return result;
        }
};