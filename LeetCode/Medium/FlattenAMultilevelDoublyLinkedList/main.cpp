#include "../DoubleListNode.h"
#include <iostream>

/*
 * Solution: we walk the linked-list and if we encounter a node with a child, recurse down to the child's level.
 * Once we a node that has a next pointer and child pointer of nullptr, we know we've reached the end of a level.
 * Then, we insert the child and all nodes connected to it in the correct spot within the level above the child node.
 *
 * Time complexity: O(n) [where n is the total number of nodes in the linked-list]
 * Space complexity: O(number of levels in the linked-list)
 */

bool dfs(Node* node)
{
    if(node->next==nullptr && node->child==nullptr)
    {
        return true;
    }

    while(node!=nullptr)
    {
        if(node->child!=nullptr)
        {
            if(dfs(node->child))
            {
                Node* originalNext=nullptr;

                Node* originalChild=node->child;

                if(node->next!=nullptr)
                {
                    originalNext=node->next;
                }

                node->child=nullptr;

                node->next=nullptr;

                node->next=originalChild;

                node->next->prev=node;

                if(originalNext!=nullptr)
                {
                    while(node->next!=nullptr)
                    {
                        node=node->next;
                    }

                    node->next=originalNext;

                    originalNext->prev=node;
                }
            }
        }

        node=node->next;
    }

    return true;
}

Node* flatten(Node* head)
{
    if(head==nullptr)
    {
        return head;
    }

    if(head->next==nullptr && head->child==nullptr)
    {
        return head;
    }

    dfs(head);

    return head;
}