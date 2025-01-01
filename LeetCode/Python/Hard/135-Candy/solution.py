class Solution:
    def candy(self, ratings: List[int]) -> int:
        result: int=0

        n: int=len(ratings)

        candies: List[int]=[1] * n

        #Iterate through ratings
        for index in range(1, n):
            #If the rating of the child's left neighbour is less than the current child's rating, give the current child one more candy than their neighbour
            if ratings[index] > ratings[index - 1]:
                candies[index]=(candies[index - 1] + 1)
        
        #Iterate through ratings in reverse
        for index in range(n - 2, -1, -1):
            #If the rating of the child's right neighbour is less than the current child's rating, give the current child
            #the maximum between the amount of candies they currently have or one more than their right neighbour has
            if ratings[index] > ratings[index + 1]:
                candies[index]=max(candies[index], candies[index + 1] + 1)

        result=sum(candies)

        return result