#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Using a hashtable (unordered_map<char, string>) to map each letter to it's corresponding morse code representation.
 * Then, for each string in vector<string> & words, convert the string to morse code. We use an unordered_set<string>
 * to preserve the uniqueness of the morse code representations.
 *
 * Time complexity: O(n * L) [where n is the length of the words vectors and L is the average length of a word]
 * Space complexity: O(26 letters of the alphabet) ---> O(1)
 *
 *
 * 2) Same logic, just using a vector<int> instead of an unordered_map<char, int> for our hashtable.
 *
 * Time complexity: O(n * L) [where n is the length of the words vectors and L is the average length of a word]
 * Space complexity: O(26) ---> O(1)
 */

int uniqueMorseRepresentations(vector<string> & words)
{
    if(words.empty())
    {
        return 0;
    }

    unordered_map<char, string> letterToMorseCode;

    unordered_set<string> transformations;

    letterToMorseCode['a']=".-";

    letterToMorseCode['b']="-...";

    letterToMorseCode['c']="-.-.";

    letterToMorseCode['d']="-..";

    letterToMorseCode['e']=".";

    letterToMorseCode['f']="..-.";

    letterToMorseCode['g']="--.";

    letterToMorseCode['h']="....";

    letterToMorseCode['i']="..";

    letterToMorseCode['j']=".---";

    letterToMorseCode['k']="-.-";

    letterToMorseCode['l']=".-..";

    letterToMorseCode['m']="--";

    letterToMorseCode['n']="-.";

    letterToMorseCode['o']="---";

    letterToMorseCode['p']=".--.";

    letterToMorseCode['q']="--.-";

    letterToMorseCode['r']=".-.";

    letterToMorseCode['s']="...";

    letterToMorseCode['t']="-";

    letterToMorseCode['u']="..-";

    letterToMorseCode['v']="...-";

    letterToMorseCode['w']=".--";

    letterToMorseCode['x']="-..-";

    letterToMorseCode['y']="-.--";

    letterToMorseCode['z']="--..";

    for(string & word : words)
    {
        string morseCode{};

        for(char & c : word)
        {
            morseCode+=letterToMorseCode[c];
        }

        if(!transformations.count(morseCode))
        {
            transformations.insert(morseCode);
        }
    }

    return static_cast<int>(transformations.size());
}

int uniqueMorseRepresentations(vector<string> & words)
{
    if(words.empty())
    {
        return 0;
    }

    vector<string> letterToMorseCode(123, "");

    unordered_set<string> transformations;

    letterToMorseCode[int('a')]=".-";

    letterToMorseCode[int('b')]="-...";

    letterToMorseCode[int('c')]="-.-.";

    letterToMorseCode[int('d')]="-..";

    letterToMorseCode[int('e')]=".";

    letterToMorseCode[int('f')]="..-.";

    letterToMorseCode[int('g')]="--.";

    letterToMorseCode[int('h')]="....";

    letterToMorseCode[int('i')]="..";

    letterToMorseCode[int('j')]=".---";

    letterToMorseCode[int('k')]="-.-";

    letterToMorseCode[int('l')]=".-..";

    letterToMorseCode[int('m')]="--";

    letterToMorseCode[int('n')]="-.";

    letterToMorseCode[int('o')]="---";

    letterToMorseCode[int('p')]=".--.";

    letterToMorseCode[int('q')]="--.-";

    letterToMorseCode[int('r')]=".-.";

    letterToMorseCode[int('s')]="...";

    letterToMorseCode[int('t')]="-";

    letterToMorseCode[int('u')]="..-";

    letterToMorseCode[int('v')]="...-";

    letterToMorseCode[int('w')]=".--";

    letterToMorseCode[int('x')]="-..-";

    letterToMorseCode[int('y')]="-.--";

    letterToMorseCode[int('z')]="--..";

    for(string & word : words)
    {
        string morseCode{};

        for(char & c : word)
        {
            morseCode+=letterToMorseCode[c];
        }

        if(!transformations.count(morseCode))
        {
            transformations.insert(morseCode);
        }
    }

    return static_cast<int>(transformations.size());
}