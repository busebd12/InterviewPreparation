class Solution:
    def reverseWords(self, s: str) -> str:
        result: str=""
            
        words: List[str]=s.split(' ')
            
        w: int=len(words)
            
        for index in range(0, w):
            reversed_word: str=words[index][::-1]
                
            result+=reversed_word
            
            if index < w - 1:
                result+=" "
                
        return result