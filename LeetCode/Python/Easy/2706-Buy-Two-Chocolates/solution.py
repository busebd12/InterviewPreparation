class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        prices.sort()

        sum_of_two_cheapest=prices[0] + prices[1]

        return money - sum_of_two_cheapest if money >= sum_of_two_cheapest else money

class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        total=0

        p=len(prices)

        limit=(10**2) + 1

        buckets=[0 for _ in range(0, limit)]

        for price in prices:
            buckets[price]+=1

        smallest=-1

        second_smallest=-1

        for price in range(0, limit):
            if buckets[price]:
                if buckets[price]==1:
                    if smallest==-1 and second_smallest==-1:
                        smallest=price
                    elif smallest!=-1 and second_smallest==-1:
                        second_smallest=price
                    else:
                        break
                else:
                    if smallest==-1 and second_smallest==-1:
                        smallest=price

                        second_smallest=price
                    elif smallest!=-1 and second_smallest==-1:
                        second_smallest=price
                    else:
                        break

        total=smallest + second_smallest

        return money - total if money >= total else money