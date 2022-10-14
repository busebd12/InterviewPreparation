#include <vector>
using namespace std;


class Vector2D
{
    private:
        vector<int> elements;
        int index;
    
    public:
        Vector2D(vector<vector<int>>& vec)
        {
            for(vector<int> & v : vec)
            {
                for(int element : v)
                {
                    elements.push_back(element);
                }
            }
            
            index=0;
        }

        int next()
        {
            int value=elements[index];
            
            index+=1;
            
            return value;
        }

        bool hasNext()
        {
            return index < elements.size();
        }
};

class Vector2D
{
    private:
        vector<vector<int>> & data;
        int i;
        int j;
    
    public:
        Vector2D(vector<vector<int>> & vec): data(vec)
        {
            i=0;
            
            j=0;
            
            update();
        }

        int next()
        {
            int value=data[i][j];
            
            j+=1;
            
            update();
            
            return value;
        }

        bool hasNext()
        {
            return i < data.size();
        }
    
        void update()
        {
            while(i < data.size() and j==data[i].size())
            {
                i+=1;
                
                j=0;
            }
        }
};
