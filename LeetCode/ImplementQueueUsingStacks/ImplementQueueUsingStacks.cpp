class MyQueue
{
    public:
        stack<int> primary;
        
        stack<int> secondary;
        
        MyQueue()
        {
            
        }
        
        void push(int x)
        {
            if(primary.empty())
            {
                primary.push(x);
            }
            else
            {
                while(!primary.empty())
                {
                    int topElement=primary.top();
                    
                    primary.pop();
                    
                    secondary.push(topElement);
                }
                
                primary.push(x);
                
                while(!secondary.empty())
                {
                    int element=secondary.top();
                    
                    secondary.pop();
                    
                    primary.push(element);
                }
            }
        }
        
        int pop()
        {
            int topElement=primary.top();
            
            primary.pop();
            
            return topElement;
        }
        
        int peek()
        {
            return primary.top();    
        }
        
        bool empty()
        {
            return primary.empty();
        }
};
