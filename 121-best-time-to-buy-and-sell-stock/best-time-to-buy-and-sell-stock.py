class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mx = 0

        r = len(prices)-1

        gap = 0

        while r >= 0 : 
            mx = max(prices[r], mx)
            if mx > prices[r]:
                gap = max(mx - prices[r] , gap)
            r-=1

        return gap 

        


        