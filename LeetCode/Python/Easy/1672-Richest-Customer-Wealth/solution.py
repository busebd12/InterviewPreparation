class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        result: int=0

        for account in accounts:
            wealth=sum(account)

            result=max(result, wealth)

        return result