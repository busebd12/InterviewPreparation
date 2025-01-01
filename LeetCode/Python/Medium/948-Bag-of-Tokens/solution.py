class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        result=0

        n=len(tokens)

        if n==0:
            return result

        tokens.sort()
        
        if power < tokens[0]:
            return result

        score=0

        left=0

        right=n - 1

        while left < right:
            if power >= tokens[left]:
                power-=tokens[left]

                score+=1

                left+=1
            elif score > 0:
                power+=tokens[right]

                score-=1

                right-=1

        if power >= tokens[left]:
            score+=1

        return score