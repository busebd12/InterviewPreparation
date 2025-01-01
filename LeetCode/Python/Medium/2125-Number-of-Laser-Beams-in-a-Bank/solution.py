class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        result=0

        ones_in_previous_row=0

        for row in bank:
            ones=row.count('1')

            if ones==0:
                continue

            product=ones_in_previous_row * ones

            result+=product

            ones_in_previous_row=ones

        return result