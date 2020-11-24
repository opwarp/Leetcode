# 322. Coin Change.py
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        dp = (amount + 1) * [-1]
        for coin in coins:
            if coin <= amount:
                dp[coin] = 1
        for step, coinNum in enumerate(dp):
            if coinNum != -1:
                for coin in coins:
                    if step + coin <= amount and (dp[step + coin] == -1 or coinNum + 1 < dp[step + coin]):
                        dp[step + coin] = coinNum + 1
        return dp[amount]