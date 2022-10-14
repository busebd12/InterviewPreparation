#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    public:
        int minimumKeypresses(string s)
        {
            int result=0;
            
            int n=s.size();
            
            unordered_map<char, int> frequencies;
            
            for(char letter : s) //O(n)
            {
                if(frequencies.find(letter)==end(frequencies))
                {
                    frequencies.emplace(letter, 0);
                }
                
                frequencies[letter]+=1;
            }
            
            auto customComparator=[] (pair<char, int> & lhs, pair<char, int> & rhs)
            {
                return lhs.second < rhs.second;
            };
            
            priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(customComparator)> maxHeap(customComparator);
            
            for(auto & [letter, frequency] : frequencies) //O(u)
            {
                maxHeap.emplace(letter, frequency); //O(log(u))
            }
            
            vector<vector<char>> buttons(10, vector<char>());
            
            unordered_map<char, int> letterToButtonMap;
            
            while(!maxHeap.empty()) //O(u)
            {
                auto [letter, frequency]=maxHeap.top();
                
                maxHeap.pop(); //O(log(u))
                
                int button=getButton(buttons); //O(9)
                
                buttons[button].push_back(letter);
                
                letterToButtonMap.emplace(letter, button);
            }
            
            for(char & letter : s) //O(n)
            {
                int button=letterToButtonMap[letter];
                
                int presses=getNumberOfPresses(buttons, button, letter); //O(3)
                
                result+=presses;
            }
            
            return result;
        }
    
        int getButton(vector<vector<char>> & buttons)
        {
            int button=numeric_limits<int>::max();
            
            for(int index=1;index<buttons.size();index++)
            {
                if(buttons[index].size() < 3)
                {
                    if(button==numeric_limits<int>::max())
                    {
                        button=index;
                    }
                    else
                    {
                        if(buttons[index].size() < buttons[button].size())
                        {
                            button=index;
                        }
                    }
                }
            }
            
            return button;
        }
    
        int getNumberOfPresses(vector<vector<char>> & buttons, int button, char letter)
        {
            int presses=0;
            
            for(int index=0;index<buttons[button].size();index++)
            {
                if(buttons[button][index]==letter)
                {
                    presses=index + 1;
                    
                    break;
                }
            }
            
            return presses;
        }
};