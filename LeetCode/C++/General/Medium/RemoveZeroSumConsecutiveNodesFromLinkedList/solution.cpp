
/*
Solution: inspired by this post --> https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/discuss/477112/Very-easy-Java-solution-with-explanation

Time complexity: O(n) [where n is the number of nodes in the linked list]
Space complexity: O(n)
*/

class Solution
{
    public:
        ListNode* removeZeroSumSublists(ListNode* head)
        {
            ListNode* result=nullptr;
            
            ListNode dummy(0);
            
            dummy.next=head;
            
            ListNode* current=&dummy;
            
            unordered_map<int, ListNode*> hashmap;
            
            int prefixSum=0;
            
            while(current!=nullptr)
            {
                prefixSum+=current->val;
                
                if(hashmap.find(prefixSum)!=end(hashmap))
                {
                    current=hashmap[prefixSum]->next;
                    
                    int sumToErase=prefixSum + current->val;
                    
                    while(sumToErase!=prefixSum)
                    {
                        hashmap.erase(sumToErase);
                        
                        current=current->next;
                        
                        sumToErase+=current->val;
                    }
                    
                    hashmap[prefixSum]->next=current->next;
                }
                else
                {
                    hashmap.emplace(prefixSum, current);
                }
                
                current=current->next;
            }
            
            result=&dummy;
            
            return result->next;
        }
};