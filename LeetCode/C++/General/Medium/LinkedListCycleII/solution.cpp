#include <unordered_set>
using namespace std;

class Solution
{
    public:
        ListNode *detectCycle(ListNode *head)
        {
            ListNode* result=nullptr;

            bool hasCycle=false;

            ListNode* current=head;

            unordered_set<ListNode*> seen;

            while(current!=nullptr and hasCycle==false)
            {
                if(seen.find(current)!=seen.end())
                {
                    result=current;

                    hasCycle=true;
                }
                else
                {
                    seen.insert(current);
                }

                current=current->next;
            }

            return result;
        }
};