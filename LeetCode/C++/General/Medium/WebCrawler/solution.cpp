#include <deque>
#include <string>
#include <unordered_set>
#include <vector>

/*
Solution 1: Breadth-first search.
*/

class Solution
{
    public:
        bool validHostname(string hostname)
        {
            if(hostname.empty())
            {
                return false;
            }
            
            size_t h=hostname.size();
            
            if(h > 63)
            {
                return false;
            }
            
            if(hostname.front()=='-' || hostname.back()=='-')
            {
                return false;
            }
            
            unordered_set<char> allowedCharacters;
            
            for(char letter='a';letter<='z';letter++)
            {
                allowedCharacters.insert(letter);
            }
            
            for(int digit=0;digit<10;digit++)
            {
                allowedCharacters.emplace(digit + '0');
            }
            
            allowedCharacters.emplace('.');
            
            allowedCharacters.emplace('-');
            
            for(char letter : hostname)
            {
                if(allowedCharacters.find(letter)==end(allowedCharacters))
                {
                    return false;
                }
            }
            
            return true;
        }
    
        string getHostname(string url)
        {
            size_t doubleSlashIndex=url.find("//");
            
            size_t substringStart=doubleSlashIndex + 2;
            
            size_t index=substringStart;
            
            while(index < url.size() && url[index]!='/')
            {
                index+=1;
            }
            
            string hostname=url.substr(substringStart, index - substringStart);
            
            return hostname;
        }
    
        vector<string> crawl(string startUrl, HtmlParser htmlParser)
        {
            vector<string> result;
            
            unordered_set<string> visited;
            
            visited.insert(startUrl);
            
            deque<string> queue;
            
            queue.push_back(startUrl);
            
            while(!queue.empty())
            {
                size_t qSize=queue.size();
                
                for(size_t count=0;count<qSize;count++)
                {
                    string url=queue.front();
                    
                    queue.pop_front();
                    
                    result.push_back(url);
                    
                    string hostname=getHostname(url);
                    
                    vector<string> nextUrls=htmlParser.getUrls(url);
                    
                    for(string nextUrl : nextUrls)
                    {
                        string nextHostname=getHostname(nextUrl);
                        
                        if(validHostname(nextHostname)==true && visited.find(nextUrl)==end(visited) && nextHostname==hostname)
                        {
                            visited.insert(nextUrl);
                            
                            queue.push_back(nextUrl);
                        }
                    }
                }
            }
            
            return result;
        }
};


/*
Solution 2: Depth-first search.
*/

class Solution
{
    public:
        bool validHostname(string hostname)
        {
            if(hostname.empty())
            {
                return false;
            }
            
            size_t h=hostname.size();
            
            if(h > 63)
            {
                return false;
            }
            
            if(hostname.front()=='-' || hostname.back()=='-')
            {
                return false;
            }
            
            unordered_set<char> allowedCharacters;
            
            for(char letter='a';letter<='z';letter++)
            {
                allowedCharacters.insert(letter);
            }
            
            for(int digit=0;digit<10;digit++)
            {
                allowedCharacters.emplace(digit + '0');
            }
            
            allowedCharacters.emplace('.');
            
            allowedCharacters.emplace('-');
            
            for(char letter : hostname)
            {
                if(allowedCharacters.find(letter)==end(allowedCharacters))
                {
                    return false;
                }
            }
            
            return true;
        }
    
        string getHostname(string url)
        {
            size_t doubleSlashIndex=url.find("//");
            
            size_t substringStart=doubleSlashIndex + 2;
            
            size_t index=substringStart;
            
            while(index < url.size() && url[index]!='/')
            {
                index+=1;
            }
            
            string hostname=url.substr(substringStart, index - substringStart);
            
            return hostname;
        }
    
        vector<string> crawl(string startUrl, HtmlParser htmlParser)
        {
            vector<string> result;
            
            unordered_set<string> visited;
            
            visited.insert(startUrl);
            
            deque<string> stack;
            
            stack.push_back(startUrl);
            
            while(!stack.empty())
            {
                string url=stack.back();
                    
                stack.pop_back();

                result.push_back(url);

                string hostname=getHostname(url);

                vector<string> nextUrls=htmlParser.getUrls(url);

                for(string nextUrl : nextUrls)
                {
                    string nextHostname=getHostname(nextUrl);

                    if(validHostname(nextHostname)==true && visited.find(nextUrl)==end(visited) && nextHostname==hostname)
                    {
                        visited.insert(nextUrl);

                        stack.push_back(nextUrl);
                    }
                }
            }
            
            return result;
        }
};