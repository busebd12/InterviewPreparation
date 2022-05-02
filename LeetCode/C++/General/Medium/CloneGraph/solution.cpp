#include <deque>
#include <unordered_map>
using namespace std;

/*
Solution 1: Clone the graph using depth-first traversal

Time complexity: O(V + E) [where V is the number of vertices and E is the number of edges]
Space complexity: O(V)
*/

class Solution
{
    private:
        unordered_map<Node*, Node*> originalToCloned;
    
    public:
        Node* cloneGraph(Node* node)
        {
            if(node==nullptr)
            {
                return node;
            }
            
            //Clone the input node
            Node* firstCloned=new Node(node->val);
            
            //Map the original node to the cloned node
            originalToCloned[node]=firstCloned;
            
            //Stack for depth-first traversal of the graph
            deque<Node*> stack;
            
            //Add the node to the stack
            stack.emplace_back(node);
            
            //Do depth-first traversal
            while(!stack.empty())
            {
                //Remove the node from the top of the stack
                auto current=stack.back();
                
                //Pop from the stack
                stack.pop_back();
                
                //Iterate through the current node's neighbours
                for(auto & neighbour : current->neighbors)
                {
                    //If the neighbour hasn't already been cloned
                    if(originalToCloned.find(neighbour)==end(originalToCloned))
                    {
                        //Create a clone of the neighbour in our map
                        originalToCloned[neighbour]=new Node(neighbour->val);
                        
                        //Add the neighbour to the stack
                        stack.emplace_back(neighbour);
                    }
                    
                    //Add the cloned neighbour to the list of neighbours for the current cloned node
                    originalToCloned[current]->neighbors.emplace_back(originalToCloned[neighbour]);
                }
            }
            
            //Return the cloned copy of the input node
            return originalToCloned[node];
        }
};

/*
Solution 1: Clone the graph using breadth-first traversal

Time complexity: O(V + E) [where V is the number of vertices and E is the number of edges]
Space complexity: O(V)
*/

class Solution
{
    private:
        unordered_map<Node*, Node*> originalToCloned;
    
    public:
        Node* cloneGraph(Node* node)
        {
            if(node==nullptr)
            {
                return node;
            }
            
            //Clone the input node
            Node* firstCloned=new Node(node->val);
            
            //Map the original node to the cloned node
            originalToCloned[node]=firstCloned;
            
            //Queue for breadth-first traversal of the graph
            deque<Node*> queue;
            
            //Add the node to the queue
            queue.emplace_back(node);
            
            //Do breadth-first traversal
            while(!queue.empty())
            {
                //Remove the node from the front of the queue
                auto current=queue.front();
                
                //Pop from the front of the queue
                queue.pop_front();
                
                //Iterate through the current node's neighbours
                for(auto & neighbour : current->neighbors)
                {
                    //If the neighbour hasn't already been cloned   
                    if(originalToCloned.find(neighbour)==end(originalToCloned))
                    {
                        //Create a clone of the neighbour in our map
                        originalToCloned[neighbour]=new Node(neighbour->val);
                        
                        //Add the neighbour to the queue
                        queue.emplace_back(neighbour);
                    }
                    
                    //Add the cloned neighbour to the list of neighbours for the current cloned node
                    originalToCloned[current]->neighbors.emplace_back(originalToCloned[neighbour]);
                }
            }
            
            //Return cloned copy of the input node
            return originalToCloned[node];
        }
};