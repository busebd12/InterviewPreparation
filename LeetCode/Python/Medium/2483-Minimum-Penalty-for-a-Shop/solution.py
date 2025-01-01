class Solution:
    def bestClosingTime(self, customers: str) -> int:
        result: int=0

        n: int=len(customers)

        number_of_yes: List[int]=self.get_number_of_yes(customers, n)

        number_of_no: List[int]=self.get_number_of_no(customers, n)

        min_penalty: int=pow(2, 31) - 1

        for hour in range(0, n + 1):
            penalty: int=number_of_yes[hour] + number_of_no[hour]

            if penalty < min_penalty:
                result=hour

                min_penalty=penalty

        return result

    def get_number_of_yes(self, customers: str, n: int) -> List[int]:
        number_of_yes: List[int]=[0] * (n + 1)

        count: int=0

        for index in range(n-1, -1, -1):
            if customers[index]=='Y':
                number_of_yes[index]=(count + 1)

                count+=1
            else:
                number_of_yes[index]=count
                
        return number_of_yes

    def get_number_of_no(self, customers: str, n: int) -> List[int]:
        number_of_no: List[int]=[0] * (n + 1)

        count: int=0

        for index in range(1, n + 1):
            if customers[index - 1]=='N':
                number_of_no[index]=(count + 1)

                count+=1
            else:
                number_of_no[index]=count

        return number_of_no