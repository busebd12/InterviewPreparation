#include <iterator>
#include <list>
#include <string>
using namespace std;

class BrowserHistory
{
    private:
        list<string> history;
    
        list<string>::iterator itr;
    
    public:
        BrowserHistory(string homepage)
        {
            history.push_back(homepage);
            
            itr=begin(history);
        }

        void visit(string url)
        {
            auto deleteItr=itr;
            
            deleteItr++;
            
            history.erase(deleteItr, end(history));
            
            history.push_back(url);
            
            itr++;
        }

        string back(int steps)
        {
            while(itr!=begin(history) && steps > 0)
            {
                itr--;
                
                steps--;
            }
            
            return *itr;
        }

        string forward(int steps)
        {
            while(itr!=end(history) && steps > 0)
            {
                itr++;
                
                steps--;
            }
            
            if(itr==end(history))
            {
                itr--;
            }
            
            return *itr;
        }
};
