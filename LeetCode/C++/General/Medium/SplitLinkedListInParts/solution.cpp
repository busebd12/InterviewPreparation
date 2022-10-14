#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of the linked list]
Space complexity: O(k)
*/

class Solution
{
    public:
        vector<ListNode*> splitListToParts(ListNode* head, int k)
        {
            vector<ListNode*> result;
            
            int n=getLength(head);
            
            vector<int> buckets(k, 0);
            
            int minimumBucketSize=-1;
    
            int leftOver=-1;

            if(n < k)
            {
                if(n==0)
                {
                    minimumBucketSize=0;
                }
                else
                {
                    minimumBucketSize=1;
                }
                
                leftOver=0;
            }
            else
            {
                minimumBucketSize=n / k;

                leftOver=n % k;
            }
            
            int length=n;
            
            for(int i=0;i<k;i++)
            {
                for(int count=0;count<minimumBucketSize and length > 0;count++)
                {
                    buckets[i]+=1;

                    length-=1;
                }

                if(leftOver > 0 and length > 0)
                {
                    buckets[i]+=1;

                    leftOver-=1;

                    length-=1;
                }
            }
            
            ListNode* current=head;
    
            for(int i=0;i<k;i++)
            {
                int bucketSize=buckets[i];
                
                ListNode* part=nullptr;

                if(bucketSize > 0)
                {
                    ListNode dummy(-1);
                    
                    ListNode* temp=&dummy;
                    
                    for(int count=0;count<bucketSize and current!=nullptr;count++)
                    {   
                        temp->next=new ListNode(current->val);
                        
                        temp=temp->next;
                        
                        current=current->next;
                    }
                    
                    part=&dummy;
                    
                    part=part->next;
                }
                
                result.push_back(part);
            }
            
            return result;
        }
    
        int getLength(ListNode* head)
        {
            int length=0;
            
            ListNode* walker=head;
            
            while(walker!=nullptr)
            {
                length+=1;
                
                walker=walker->next;
            }
            
            return length;
        }
};