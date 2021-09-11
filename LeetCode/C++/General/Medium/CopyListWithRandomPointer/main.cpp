#include "../RandomNode.h"
#include <iostream>
#include <unordered_map>

/*
 * Solution: we maintain a mapping of old nodes to their new copies.In the first pass, we build our new nodes,
 * but do not assign any next or random pointers, because these nodes may not have been constructed yet.
 * In the second pass we assign pointers, looking up the corresponding destination node in the map.
 *
 * Time complexity: O(n) [where n is the number of nodes in the input linked list]
 * Space complexity: O(n)
 */

Node* copyRandomList(Node* head)
{
    if(head==nullptr)
    {
        return head;
    }

    std::unordered_map<Node*, Node*> hashtable;

    for(auto iterator=head;iterator!=nullptr;iterator=iterator->next)
    {
        hashtable[iterator]=new Node(iterator->val);
    }

    for(auto iterator=head;iterator!=nullptr;iterator=iterator->next)
    {
        hashtable[iterator]->next=hashtable[iterator->next];

        hashtable[iterator]->random=hashtable[iterator->random];
    }

    return hashtable[head];
}