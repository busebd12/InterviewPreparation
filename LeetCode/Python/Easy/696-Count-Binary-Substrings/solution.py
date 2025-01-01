class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        result: int=0

        n: int=len(s)

        if n==1:
            return result

        left: int=0

        right: int=1

        while right < n:
            if (s[left]=='0' and s[right]=='1') or (s[left]=='1' and s[right]=='0'):
                result+=self.helper(s, n, left, right)
            
            left+=1

            right+=1

        return result

    def helper(self, s: str, n: int, left: int, right: int) -> int:
        count: int=0

        if s[left]=='0' and s[right]=='1':
            while left >= 0 and right < n and s[left]=='0' and s[right]=='1':
                count+=1

                left-=1

                right+=1
        else:
            while left >= 0 and right < n and s[left]=='1' and s[right]=='0':
                count+=1

                left-=1

                right+=1

        return count

class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        result: int=0

        n: int=len(s)

        if n==1:
            return result

        previous_consecutive_count: int=0

        current_consecutive_count: int=1

        for index in range(1, n):
            if s[index]==s[index - 1]:
                current_consecutive_count+=1
            else:
                result+=min(current_consecutive_count, previous_consecutive_count)

                previous_consecutive_count=current_consecutive_count

                current_consecutive_count=1

        result+=min(previous_consecutive_count, current_consecutive_count)

        return result