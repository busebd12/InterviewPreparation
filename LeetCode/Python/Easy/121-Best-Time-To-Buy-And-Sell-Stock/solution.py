class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        result: int=0

        n: int=len(prices)

        min_buy_price: int=prices[0]

        for index in range(0, n):
            sell_price: int=prices[index]
            
            if sell_price < min_buy_price:
                min_buy_price=sell_price
            
            elif sell_price > min_buy_price:
                profit: int=sell_price - min_buy_price
                
                result=max(result, profit)

        return result