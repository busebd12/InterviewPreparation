#include <deque>
#include <string>
#include <vector>
using namespace std;

/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node
{
    public:
        virtual ~Node () {};
        virtual int evaluate() const = 0;
    protected:
        // define your fields here
};

class CustomNode : public Node
{
    private:
        CustomNode* left;
        
        CustomNode* right;
        
        string content;
        
        int data;
        
    public:
        CustomNode(string str, int value, CustomNode* l=nullptr, CustomNode* r=nullptr)
        {
            this->left=l;
            
            this->right=r;
            
            this->content=str;
            
            this->data=value;
        }
        
        ~CustomNode()
        {
            delete left;
            
            delete right;
        }
        
        int evaluate() const
        {
            return data;
        }
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder
{
    public:
        Node* buildTree(vector<string> & postfix)
        {
            deque<CustomNode*> stack;
            
            for(auto & str : postfix)
            {
                if(isdigit(str[0]))
                {
                    stack.emplace_back(new CustomNode(str, stoi(str)));
                }
                else
                {
                    CustomNode* r=stack.back();
                    
                    stack.pop_back();
                    
                    CustomNode* l=stack.back();
                    
                    stack.pop_back();
                    
                    stack.emplace_back(createNode(str, l, r));
                }
            }
            
            return stack.back();
        }
    
        CustomNode* createNode(string & str, CustomNode* l, CustomNode* r)
        {
            int value=0;
            
            switch(str[0])
            {
                case '+':
                    value=l->evaluate() + r->evaluate();
                    
                    break;
                    
                case '-':
                    value=l->evaluate() - r->evaluate();
                    
                    break;
                    
                case '*':
                    value=l->evaluate() * r->evaluate();
                    
                    break;
                    
                case '/':
                    value=l->evaluate() / r->evaluate();
                    
                    break;
                    
                default:
                    value=0;
            }
            
            return new CustomNode(str, value, l, r);
        }
};