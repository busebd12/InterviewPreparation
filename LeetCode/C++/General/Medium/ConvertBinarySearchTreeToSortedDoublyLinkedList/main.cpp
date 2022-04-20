#include <iostream>
#include <stack>
#include <vector>

/*
 * Solutions:
 *
 * 1) Perform a recursive in-order traversal of the binary search tree and add the nodes to the circular doubly-linked
 * list as we go.
 *
 * Time complexity: O(n^2) [where n is the number of nodes in the binary search tree]
 * Space complexity: O(h) [where h is the height of the binary search tree]
 *
 * 2) Same idea as the first solution except that the traversal is iterative instead of recursive.
 *
 * Time complexity: O(n^2) [where n is the number of nodes in the binary search tree]
 * Space complexity: O(h) [where h is the height of the binary search tree]
 *
 * 3) Perform a recursive in-order traversal of the binary search tree and add all the nodes to a vector.
 * Then, link all the nodes in the vector together and form the circularity.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary search tree]
 * Space complexity: O(h) [where h is the height of the binary search tree]
 *
 * 4) Same idea as the third solution except the traversal is iterative instead of recursive.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary search tree]
 * Space complexity: O(h) [where h is the height of the binary search tree]
 *
 * 5) Keep two Nodes, head and tail, and create the doubly linked-list as we iterative through the binary search tree
 * using in-order traversal. After traversing the tree, link the head and tail nodes together.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary search tree]
 * Space complexity: O(h) [where h is the height of the binary search tree]
 *
 * 6) Iterative version of the fifth solution.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary search tree]
 * Space complexity: O(h) [where h is the height of the binary search tree]
 *
 *
 */

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution
{
    public:

        void addToEnd(Node* & head, int value)
        {
            if(head==nullptr)
            {
                head=new Node(value);

                head->left=head;

                head->right=head;
            }
            else
            {
                Node* current=head;

                Node* headCopy=head;

                Node* newTail=new Node(value);

                while(current->right!=nullptr && current->right->val!=headCopy->val)
                {
                    current=current->right;
                }

                current->right=newTail;

                newTail->left=current;

                newTail->right=headCopy;

                headCopy->left=newTail;
            }
        }

        void inOrderTraversal(Node* root, Node* & head)
        {
            if(root==nullptr)
            {
                return;
            }

            inOrderTraversal(root->left, head);

            addToEnd(head, root->val);

            inOrderTraversal(root->right, head);
        }

        Node* treeToDoublyList(Node* root)
        {
            Node* head=nullptr;

            if(root==nullptr)
            {
                return root;
            }

            inOrderTraversal(root, head);

            return head;
        }



        void addToEnd(Node* & head, int value)
        {
            if(head==nullptr)
            {
                head=new Node(value);

                head->left=head;

                head->right=head;
            }
            else
            {
                Node* current=head;

                Node* headCopy=head;

                Node* newTail=new Node(value);

                while(current->right!=nullptr && current->right->val!=headCopy->val)
                {
                    current=current->right;
                }

                current->right=newTail;

                newTail->left=current;

                newTail->right=headCopy;

                headCopy->left=newTail;
            }
        }

        void inOrderTraversalIterative(Node* root, Node* & head)
        {
            std::stack<Node*> stk;

            Node* node=root;

            while(!stk.empty() || node!=nullptr)
            {
                while(node!=nullptr)
                {
                    stk.push(node);

                    node=node->left;
                }

                node=stk.top();

                addToEnd(head, node->val);

                stk.pop();

                node=node->right;
            }
        }

        Node* treeToDoublyList(Node* root)
        {
            if(root==nullptr)
            {
                return root;
            }

            Node* head=nullptr;

            inOrderTraversalIterative(root, head);

            return head;
        }

        void inOrderTraversalIterative(Node* root, std::vector<Node*> & nodes)
        {
            std::stack<Node*> stk;

            Node* node=root;

            while(!stk.empty() || node!=nullptr)
            {
                while(node!=nullptr)
                {
                    stk.push(node);

                    node=node->left;
                }

                node=stk.top();

                nodes.emplace_back(node);

                stk.pop();

                node=node->right;
            }
        }

        Node* treeToDoublyList(Node* root)
        {
            if(root==nullptr)
            {
                return root;
            }

            std::vector<Node*> nodes;

            inOrderTraversalIterative(root, nodes);

            int n=int(nodes.size());

            for(int i=0;i<n-1;i++)
            {
                nodes[i]->right=nodes[i+1];

                nodes[i+1]->left=nodes[i];
            }

            nodes[0]->left=nodes[n-1];

            nodes[n-1]->right=nodes[0];

            return nodes[0];
        }

        void inOrderTraversal(Node* root, std::vector<Node*> & nodes)
        {
            if(root==nullptr)
            {
                return;
            }

            inOrderTraversal(root->left, nodes);

            nodes.emplace_back(root);

            inOrderTraversal(root->right, nodes);
        }

        Node* treeToDoublyList(Node* root)
        {
            if(root==nullptr)
            {
                return root;
            }

            std::vector<Node*> nodes;

            inOrderTraversal(root, nodes);

            int n=int(nodes.size());

            for(int i=0;i<n-1;i++)
            {
                nodes[i]->right=nodes[i+1];

                nodes[i+1]->left=nodes[i];
            }

            nodes[0]->left=nodes[n-1];

            nodes[n-1]->right=nodes[0];

            return nodes[0];
        }

        void inOrderTraversal(Node* root, Node* & head, Node* & tail)
        {
            if(root==nullptr)
            {
                return;
            }

            inOrderTraversal(root->left, head, tail);

            if(head==nullptr)
            {
                head=root;
            }
            else
            {
                tail->right=root;

                root->left=tail;
            }

            tail=root;

            inOrderTraversal(root->right, head, tail);
        }

        Node* treeToDoublyList(Node* root)
        {
            if(root==nullptr)
            {
                return root;
            }

            Node* head=nullptr;

            Node* tail=nullptr;

            inOrderTraversal(root, head, tail);

            head->left=tail;

            tail->right=head;

            return head;
        }

        void inOrderTraversalIterative(Node* root, Node* & head, Node* & tail)
        {
            std::stack<Node*> stk;

            Node* current=root;

            while(!stk.empty() || current!=nullptr)
            {
                while(current!=nullptr)
                {
                    stk.push(current);

                    current=current->left;
                }

                current=stk.top();

                stk.pop();

                if(head==nullptr)
                {
                    head=current;
                }
                else
                {
                    tail->right=current;

                    current->left=tail;
                }

                tail=current;

                current=current->right;
            }
        }

        Node* treeToDoublyList(Node* root)
        {
            if(root==nullptr)
            {
                return root;
            }

            Node* head=nullptr;

            Node* tail=nullptr;

            inOrderTraversalIterative(root, head, tail);

            head->left=tail;

            tail->right=head;

            return head;
        }
};