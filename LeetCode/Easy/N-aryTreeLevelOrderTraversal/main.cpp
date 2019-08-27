#include "../Node.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 * Approach: Similar to level order traversal for a binary tree. The only difference is that,
 * for each node we remove from our queue, instead of only putting a left and right child nodes
 * into the queue, we loop through the vector<Node*> of children nodes and if the node is not
 * nullptr, we enqueue it.
 *
 * Time complexity: O(n) [where n is the number of nodes in the tree]
 * Space complexity: O(n)
 */

vector<vector<int>> levelOrder(Node* root)
{
    vector<vector<int>> result;

    if(root==nullptr)
    {
        return result;
    }

    queue<Node*> Q;

    Q.emplace(root);

    vector<int> level;

    while(true)
    {
        if(Q.empty())
        {
            break;
        }

        int qSize=int(Q.size());

        for(int count=0;count<qSize;++count)
        {
            Node* current=Q.front();

            Q.pop();

            level.emplace_back(current->val);

            for(Node* n : current->children)
            {
                if(n!=nullptr)
                {
                    Q.emplace(n);
                }
            }
        }

        result.push_back(level);

        level.clear();
    }

    return result;
}