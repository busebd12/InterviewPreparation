#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the number of nodes in the linked list]
Space complexity: O(100000) --> O(1)
*/

class Solution
{
    private:
        vector<int> hashtable;
    
        int maxValue=100000;
    
    public:
        ListNode* deleteDuplicatesUnsorted(ListNode* head)
        {
            hashtable.resize(maxValue + 1, 0);
            
            ListNode* result=nullptr;
            
            ListNode* current=head;
            
            while(current!=nullptr)
            {   
                hashtable[current->val]+=1;
                
                current=current->next;
            }
            
            ListNode dummy(-1);
            
            current=head;
            
            ListNode* traveler=&dummy;
            
            while(current!=nullptr)
            {
                if(hashtable[current->val]==1)
                {
                    traveler->next=new ListNode(current->val);
                    
                    traveler=traveler->next;
                }
                
                current=current->next;
            }
            
            result=&dummy;
            
            return result->next;
        }
};