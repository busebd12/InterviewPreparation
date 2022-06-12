#include <string>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n) [where n is the length of s]
Space complexity: O(n)
*/

class Solution
{
    public:
        TreeNode* helper(string s)
        {
            TreeNode* root=nullptr;
            
            if(s.empty())
            {
                return root;
            }
            
            int rootValue=0;
            
            int left=-1;
            
            bool negative=false;
            
            if(s[0]=='-')
            {
                negative=true;
                
                left=1;
            }
            else
            {
                left=0;
            }
            
            //Calculate the value for root
            while(left < s.size() && s[left]!='(')
            {
                rootValue=rootValue * 10 + (s[left] - '0');
                
                left+=1;
            }
            
            //If root's value should be negative
            if(negative==true)
            {
                rootValue*=-1;
            }
            
            root=new TreeNode(rootValue);
            
            //If left reaches the end of the string, then, there are no left or right subtrees
            if(left >= s.size() - 1)
            {
                return root;
            }
            
            //Find the two indices for the left subtree substring
            int right=left;
            
            int total=0;
    
            while(right < s.size())
            {
                if(s[right]=='(')
                {
                    total-=1;
                }
                else if(s[right]==')')
                {
                    total+=1;
                }

                if(total==0)
                {
                    break;
                }

                right+=1;
            }
            
            //Left subtree substring
            string leftSubtree=s.substr(left + 1, (right - left) - 1);

            //Set the two indices in preparation for finding the right subtree
            right+=1;

            left=right;
            
            string rightSubtree{};
            
            //If right has reached the end of the string after finding the substring for the left subtree, then there is no right subtree
            if(right < s.size() - 1)
            {
                //Find the indices for the substring representing the right subtree
                while(right < s.size())
                {
                     if(s[right]=='(')
                    {
                        total-=1;
                    }
                    else if(s[right]==')')
                    {
                        total+=1;
                    }

                    if(total==0)
                    {
                        break;
                    }

                    right+=1;
                }

                rightSubtree=s.substr(left + 1, (right - left) - 1);
            }
            
            //Construct the left and right subtrees for the current root node
            root->left=helper(leftSubtree);
            
            root->right=helper(rightSubtree);
            
            return root;
        }
    
        TreeNode* str2tree(string s)
        {
            TreeNode* result=nullptr;
            
            if(s.empty())
            {
                return result;
            }
            
            result=helper(s);
            
            return result;
        }
};