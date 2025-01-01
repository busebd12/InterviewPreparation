#include "../ListNode.h"
#include <unordered_set>
using namespace std;

/*
Time complexity: O(n) [where n is the number of elements in the linked list]
Space complexity: O(m) [where m is the size of nums]
*/

class Solution
{
    public:
        int numComponents(ListNode* head, vector<int> & nums)
        {
            int result=0;

            unordered_set<int> hashset;

            for(int number : nums)
            {
                hashset.insert(number);
            }

            ListNode* current=head;

            int nodesInConnectedComponent=0;

            while(current!=nullptr)
            {
                if(hashset.find(current->val)!=hashset.end())
                {
                    nodesInConnectedComponent+=1;
                }
                else
                {
                    if(nodesInConnectedComponent > 0)
                    {
                        result+=1;
                    }

                    nodesInConnectedComponent=0;
                }

                current=current->next;
            }

            if(nodesInConnectedComponent > 0)
            {
                result+=1;
            }

            return result;
        }
};