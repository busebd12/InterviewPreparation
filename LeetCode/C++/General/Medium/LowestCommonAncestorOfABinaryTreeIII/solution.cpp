#include <deque>
using namespace std;

/*
Solution: see comments

Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(n)
*/

class Solution
{
    public:
        Node* lowestCommonAncestor(Node* p, Node * q)
        {
            Node* lca=nullptr;
            
            //Stack to store path from root node to p
            deque<Node*> pStack;
            
            //Build path from root node to p
            while(p!=nullptr)
            {
                pStack.emplace_front(p);
                
                p=p->parent;
            }
            
            //Stack to store path from root node to q
            deque<Node*> qStack;
            
            //Build path from root node to q
            while(q!=nullptr)
            {
                qStack.emplace_front(q);
                
                q=q->parent;
            }
            
            //Now, we walk along the path from the root to p and the path from the root to q
            //Any nodes that are the same in both paths are common ancestors.
            //Since we want to lowest common ancestor, we keep removing nodes that are the same from both stacks until we reach the the first node that is different
            //Once we've reached the first node that is different, we know that the node we just removed from both stacks is the lowest common ancestor
            while(!pStack.empty() && !qStack.empty() && pStack.front()->val==qStack.front()->val)
            {
                //Update lca value
                lca=pStack.front();
                
                //Remove common ancestors from both stacks
                pStack.pop_front();
                
                qStack.pop_front();
            }

            return lca;
        }
};