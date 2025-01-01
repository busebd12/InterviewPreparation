class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        result: int=0

        n: int=len(answerKey)

        target: chr='T'

        max_consecutive_true: int=self.get_max_consecutive(answerKey, n, k, target)

        target='F'

        max_consecutive_false: int=self.get_max_consecutive(answerKey, n, k, target)

        result=max(max_consecutive_true, max_consecutive_false)

        return result

    def get_max_consecutive(self, answerKey: str, n: int, k: int, target: chr) -> int:
        consecutive: int=0

        length: int=0

        left: int=0

        right: int=0

        opposite: int=0

        while right < n:
            if answerKey[right]!=target:
                opposite+=1

            while opposite > k:
                if answerKey[left]!=target:
                    opposite-=1

                left+=1
                
            length: int=(right - left) + 1

            consecutive=max(consecutive, length)

            right+=1

        return consecutive