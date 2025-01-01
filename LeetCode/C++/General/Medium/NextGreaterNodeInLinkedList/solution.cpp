#include <deque>
#include <utility>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of the linked list]
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<int> nextLargerNodes(ListNode* head)
        {
            vector<int> result;
            
            int n=getLength(head);

            result.resize(n, 0);

            deque<pair<ListNode*, int>> stack;

            int index=0;

            for(ListNode* current=head;current!=nullptr;current=current->next)
            {
                while(!stack.empty() and stack.back().first->val < current->val)
                {
                    int i=stack.back().second;
                    
                    result[i]=current->val;

                    stack.pop_back();
                }

                stack.emplace_back(current, index);

                index+=1;
            }

            return result;
        }

        int getLength(ListNode* head)
        {
            int length=0;

            for(ListNode* current=head;current!=nullptr;current=current->next)
            {
                length+=1;
            }

            return length;
        }
};