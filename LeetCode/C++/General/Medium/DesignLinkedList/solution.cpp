class LinkedListNode
{
    public:
        int data;

        LinkedListNode* next;

        LinkedListNode(int val)
        {
            data=val;

            next=nullptr;
        }
};

class MyLinkedList
{
    private:
        LinkedListNode* head;

        int size;
    
    public:
        MyLinkedList()
        {
            head=nullptr;

            size=0;
        }
        
        int get(int index)
        {
            if(index < 0 or index >= size)
            {
                return -1;
            }

            LinkedListNode* current=head;

            //Iterate through the linked list until we reach the node at the desired index
            for(int i=0;i<index;i++)
            {
                current=current->next;
            }
            
            return current->data;
        }
        
        void addAtHead(int val)
        {
            addAtIndex(0, val);
        }
        
        void addAtTail(int val)
        {
            addAtIndex(size, val);
        }
        
        void addAtIndex(int index, int val)
        {
            //Check for invalid index
            if(index < 0 or index > size)
            {
                return;
            }

            LinkedListNode* current=head;

            LinkedListNode* toBeAdded=new LinkedListNode(val);

            //If index is zero, then we are adding a node at the beginning of the linked list
            if(index==0)
            {
                toBeAdded->next=current;

                head=toBeAdded;
            }
            //Else, we are adding at any other position
            else
            {
                //Iterate up to index-1 because we want to stop when we have reach the node before the index we are adding the new node at
                for(int i=0;i<index-1;i++)
                {
                    current=current->next;
                }

                //If we have the linked list x->z and we want to add a node y before z,
                //then we want to have toBeAdded's next pointer point to what x's next pointer points to, which is z
                toBeAdded->next=current->next;

                //Continuing with the example above, now that y's next pointer points to z, we need to set x's next pointer to point to y
                current->next=toBeAdded;
            }

            size+=1;
        }
        
        void deleteAtIndex(int index)
        {
            //Check for invalid index
            if(index < 0 or index >= size)
            {
                return;
            }

            //If index equals zero, then we are deleting from the head of the linked list
            if(index==0)
            {
                LinkedListNode* nextNode=head->next;

                //IMPORTANT: DON'T FORGET TO FREE THE ELECTRONS - THE MEMORY USED BY HEAD!!!
                delete head;

                head=nextNode;
            }
            //Else, we are deleting at any other index
            else
            {
                LinkedListNode* current=head;

                ////Iterate up to index-1 because we want to stop when we have reach the node before the index we are deleting at
                for(int i=0;i<index-1;i++)
                {
                    current=current->next;
                }

                LinkedListNode* nodeAfterDeletedNode=current->next->next;

                //IMPORTANT: DON'T FORGET TO FREE THE ELECTRONS - THE MEMORY USED BY CURRENT->NEXT!!!
                delete current->next;

                //Set the next pointer of the node before the deleted node to point to the node after the deleted node
                current->next=nodeAfterDeletedNode;
            }

            size-=1;
        }
};