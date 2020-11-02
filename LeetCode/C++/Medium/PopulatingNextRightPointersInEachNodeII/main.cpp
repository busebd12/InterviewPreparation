#include "../Node.h"
#include <deque>
#include <iostream>

/*
 * Solutions:
 *
 * 1. Using a deque (double-ended queue), we perform your garden variety level order traversal and connect the
 * next pointers appropriately.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n)
 *
 * 2. Essentially, the same solution as the first one but we only iterate over the deque once per level to connect the next pointers.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n)
 *
 * 3. After we connect the next pointer of a node to another node, this allows to move to the right in the current level.
 * Aha! This means that we can perform the same level order traversal using the next pointers instead of a deque/queue.
 * So, starting at the root node, we move down level-by-level connecting the next pointers as we go. However, since the
 * given binary tree is not "perfect", after we have finished connecting all the next pointers in a given level, we
 * have three choices on how to move to the next level: move down the left subtree, the right subtree, or to the next
 * node to the right in the same level.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

Node* connect(Node* root)
{
    if(root==nullptr)
    {
        return root;
    }

    std::deque<Node*> dq;

    dq.push_back(root);

    while(!dq.empty())
    {
        int size=int(dq.size());

        for(int i=0;i<size;++i)
        {
            if(i==size-1)
            {
                dq[i]->next=nullptr;
            }
            else
            {
                dq[i]->next=dq[i+1];
            }
        }

        for(int count=0;count<size;++count)
        {
            auto node=dq.front();

            dq.pop_front();

            if(node->left!=nullptr)
            {
                dq.emplace_back(node->left);
            }

            if(node->right!=nullptr)
            {
                dq.emplace_back(node->right);
            }
        }
    }

    return root;
}

Node* connect(Node* root)
{
    if(root==nullptr)
    {
        return root;
    }

    std::deque<Node*> dq;

    dq.push_back(root);

    while(!dq.empty())
    {
        int size=int(dq.size());

        for(int count=0;count<size;++count)
        {
            auto node=dq.front();

            dq.pop_front();

            if(count==size-1)
            {
                node->next=nullptr;
            }
            else
            {
                node->next=dq.front();
            }

            if(node->left!=nullptr)
            {
                dq.emplace_back(node->left);
            }

            if(node->right!=nullptr)
            {
                dq.emplace_back(node->right);
            }
        }
    }

    return root;
}

Node* getNextRight(Node* node)
{
    Node* traveler=node->next;

    while(traveler!=nullptr)
    {
        if(traveler->left!=nullptr)
        {
            return traveler->left;
        }

        if(traveler->right!=nullptr)
        {
            return traveler->right;
        }

        traveler=traveler->next;
    }

    return nullptr;
}

Node* connect(Node* root)
{
    if(root==nullptr)
    {
        return root;
    }

    Node* current=root;

    while(current!=nullptr)
    {
        Node* iterator=current;

        while(iterator!=nullptr)
        {
            if(iterator->left!=nullptr)
            {
                if(iterator->right!=nullptr)
                {
                    iterator->left->next=iterator->right;
                }
                else
                {
                    iterator->left->next=getNextRight(iterator);
                }
            }

            if(iterator->right!=nullptr)
            {
                iterator->right->next=getNextRight(iterator);
            }

            iterator=iterator->next;
        }

        if(current->left!=nullptr)
        {
            current=current->left;
        }
        else if(current->right!=nullptr)
        {
            current=current->right;
        }
        else
        {
            current=getNextRight(current);
        }
    }

    return root;
}