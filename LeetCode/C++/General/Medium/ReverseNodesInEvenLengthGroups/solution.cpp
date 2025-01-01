#include "../ListNode.h"
#include <deque>
using namespace std;

/*
Time complexity: O(n) [where n is the length of the linked list]
Space complexity: O(n)
*/

class Solution
{
    public:
        ListNode* reverseEvenLengthGroups(ListNode* head)
        {
            ListNode* result=nullptr;

            deque<int> queue;

            //Add all linked list nodes to the queue
            for(ListNode* current=head;current!=nullptr;current=current->next)
            {
                queue.emplace_back(current->val);
            }

            //Keep track of the length of each group of nodes
            int groupLength=1;

            //The linked list we will be adding the nodes to as we reverse the even length groups
            ListNode dummy(-1);

            ListNode* current=&dummy;

            while(!queue.empty())
            {
                int count=0;

                deque<int> group;

                //Add either groupLength number of nodes or however many nodes are left in the queue, whichever is less
                while(!queue.empty() and count < groupLength)
                {
                    group.push_back(queue.front());

                    queue.pop_front();

                    count+=1;
                }

                int groupSize=group.size();

                while(!group.empty())
                {
                    //If group size is even, then we want to remove from the tail/end of the deque
                    //so that we add the nodes in revers order to the dummy linked list
                    if((groupSize % 2)==0)
                    {
                        current->next=new ListNode(group.back());

                        group.pop_back();
                    }
                    //Else, the group size is odd, so we add the node in the original order to the dummy linked list
                    else
                    {   
                        current->next=new ListNode(group.front());

                        group.pop_front();
                    }

                    current=current->next;
                }

                groupLength+=1;
            }

            //Set our result linked list to the address of the dummy linked list in memory
            result=&dummy;

            //IMPORTANT: we need to return result->next since there's a -1 that servers a sentinel node at the
            //front of the result linked list and the answer part of the linked list doesn't start until after -1
            return result->next;
        }
};