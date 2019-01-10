#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    public:
        ListNode* root;

        int size;

        Solution(ListNode* head)
        {
            root=head;

            size=0;

            ListNode* node=head;

            while(node)
            {
                ++size;

                node=node->next;
            }
        }

        int getRandom()
        {
            ListNode* node=root;

            int n=rand() % size;

            for(int i=0;i<n;++i)
            {
                node=node->next;
            }

            return node->val;
        }
};
