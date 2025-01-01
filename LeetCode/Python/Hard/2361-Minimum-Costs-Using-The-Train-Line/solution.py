class Solution:
    def minimumCosts(self, regular: List[int], express: List[int], expressCost: int) -> List[int]:
        result: List[int]=list()

        n: int=len(regular)

        result=[0] * n

        previous_regular_cost: int=0

        previous_express_cost: int=expressCost

        for index in range(0, n):
            #Arrive at the current station by taking the regular line from the previous station
            stay_on_regular: int=previous_regular_cost + regular[index]

            #Arrive at the current station by taking the regular line after switching from the express line to the regular line at the previous station
            express_to_regular: int=previous_express_cost + regular[index]

            min_regular_cost: int=min(stay_on_regular, express_to_regular)

            #Arrive at the current station by taking the express line from the previous station
            stay_on_express: int=previous_express_cost + express[index]

            #Arrive at the current station by taking the express line after switching from the regular line to the express line at the previous station
            regular_to_express: int=previous_regular_cost + express[index] + expressCost

            min_express_cost: int=min(stay_on_express, regular_to_express)

            result[index]=min(min_regular_cost, min_express_cost)

            previous_regular_cost=min_regular_cost

            previous_express_cost=min_express_cost

        return result