class Solution:
    def firstBadVersion(self, n: int) -> int:
        result: int=-1

        low: int=1

        high: int=n

        while low <= high:
            version=(low + (high - low)//2)

            if isBadVersion(version)==True:
                if result==-1 or version < result:
                    result=version
                
                high=version - 1
            else:
                low=version + 1


        return result

class Solution:
    def firstBadVersion(self, n: int) -> int:
        result: int=-1

        low: int=1

        high: int=n

        while low < high:
            version=(low + (high - low)//2)

            if isBadVersion(version)==True:
                result=version
                
                high=version - 1
            else:
                low=version + 1

        if isBadVersion(low)==True:
            result=low


        return result