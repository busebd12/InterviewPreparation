#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <string>
#include <utility>
using namespace std;

class StrIIRec
{
    public:
        int getNumberOfInversions(string Permutation)
        {
            //cout << "In the getNumberOfInversions function" << endl;
            
            //cout << endl;
            
            int inversions{};
            
            size_t permutationSize=Permutation.size();
            
            for(int i=0;i<permutationSize;++i)
            {
                for(int j=0;j<permutationSize;++j)
                {
                    if(Permutation[i] > Permutation[j])
                    {
                        ++inversions;
                    }
                }
            }
            
            return inversions;
        }
    
        string generateAlphabetString(int N)
        {
            //cout << "In the generateAlphabetString function" << endl;
            
            //cout << endl;
            
            int count{};
            
            string result{};
            
            for(char letter='a';letter<='z';++letter)
            {
                if(count==N)
                {
                    break;
                }
                
                result+=letter;
                
                ++count;
            }
            
            return result;
        }
    
    
        vector<string> getPermutations(string Input)
        {
            //cout << "In the getPermutations function" << endl;
            
            //cout << endl;
            
            vector<string> permutationz;
            
            if(Input.size()==1)
            {
                string permutationOfOne=Input;
                
                permutationz.emplace_back(permutationOfOne);
            }
            else
            {
                for(int index=0;index<Input.size();++index)
                {
                    char firstCharacter=Input[index];
                    
                    int firstCharacterIndex=index;
                    
                    string rest{};
                    
                    for(int innerIndex=0;innerIndex<Input.size();++innerIndex)
                    {
                        if(innerIndex!=index)
                        {
                            rest+=Input[innerIndex];
                        }
                    }
                    
                    vector<string> permutationsWithoutTheFirstCharacter=getPermutations(rest);
                    
                    for(auto & permutation : permutationsWithoutTheFirstCharacter)
                    {
                        permutation.insert(0, 1, firstCharacter);
                        
                        permutationz.emplace_back(permutation);
                    }
                } 
            }
            
            return permutationz;
        }
    
        string recovStr(int N, int MinInv, string MinStr)
        {
            //cout << "In the recovStr function" << endl;
            
            //cout << endl;
            
            vector<string> permutations;
            
            string answer{};
            
            string alphabetString=generateAlphabetString(N);

            if(!is_sorted(begin(alphabetString), end(alphabetString)))
            {
                sort(begin(alphabetString), end(alphabetString));
            }
            
            /*permutations=getPermutations(alphabetString);
            
            for(auto & permutation : permutations)
            {
                //cout << "Permutation: " << permutation << endl;
                
                //cout << endl;
                
                int inversions=getNumberOfInversions(permutation);
                
                if(inversions >= MinInv)
                {
                    if(lexicographical_compare(begin(MinStr), end(MinStr), begin(permutation), end(permutation)))
                    {
                        cout << "Permutation: " << permutation << endl;
                        
                        cout << endl;
                        
                        answer=permutation;
                        
                        break;
                    }
                }
            }
            */

            size_t lexicographicalSize=numeric_limits<int>::max();

            do
            {
                int inversions=getNumberOfInversions(alphabetString);

                if(inversions >= MinInv)
                {
                    if(lexicographical_compare(begin(MinStr), end(MinStr), begin(alphabetString), end(alphabetString)))
                    {
                        cout << "Permutation: " << alphabetString << endl;
                        
                        cout << endl;

                        if(alphabetString.size() < lexicographicalSize)
                        {
                            answer=alphabetString;
                        }
                    }
                }
            }
            while(next_permutation(begin(alphabetString), end(alphabetString)));

            cout << "Answer: " << answer << endl;
            
            cout << endl;
            
            return answer;
        }
};

int main(int argc, char** argv)
{
    StrIIRec S;
    
    /*
    int n=2;
    
    int minInv=1;
    
    string minStr="ab";
    
    //Returns: "ba"
    */
    
    
    /*
    int n=9;
    
    int minInv=1;
    
    string minStr="efcdgab";
    
    //Returns: "efcdgabhi"
    */
    
    
    /*
    int n=11;
    
    int minInv=55;
    
    string minStr="debgikjfc";
    
    //Returns: "kjihgfedcba"
    */
    
    
    int n=15;
    
    int minInv=0;
    
    string minStr="e";
    
    //Returns: "eabcdfghijklmno"
    
    
    /*
    int n=9;
    
    int minInv=20;
    
    string minStr="fcdebiha";
    
    //Returns: "fcdehigba"
    */
    
    cout << S.recovStr(n, minInv, minStr) << endl;
}