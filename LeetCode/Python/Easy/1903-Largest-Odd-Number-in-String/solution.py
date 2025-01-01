class Solution:
    def largestOddNumber(self, num: str) -> str:
      result: str=""

      n: int=len(num)

      last_odd_index: int=-1

      for index in range(n-1, -1, -1):
        if self.is_odd_digit(num[index]):
          last_odd_index=index

          break

      result=num[0 : last_odd_index + 1]

      return result

    def is_odd_digit(self, digit: chr) -> bool:
      return digit=='1' or digit=='3' or digit=='5' or digit=='7' or digit=='9'