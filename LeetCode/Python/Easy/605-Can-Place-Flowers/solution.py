class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        f: int=len(flowerbed)

        for index in range(0, f):
            if not flowerbed[index]:
                if index==0:
                    if (index + 1 >= f or not flowerbed[index + 1]) and n > 0:
                        flowerbed[index]=1
                        
                        n-=1
                elif index==f-1:
                    if not flowerbed[index - 1] and n > 0:
                        flowerbed[index]=1

                        n-=1
                else:
                    if (not flowerbed[index - 1] and not flowerbed[index + 1]) and n > 0:
                        print(index)

                        flowerbed[index]=1

                        n-=1

        return n==0