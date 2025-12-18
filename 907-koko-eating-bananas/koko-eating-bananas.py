class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # ith pile has pile[i]
        # koko decies 

        l , r = 1, max(piles)

        res = 0 

        while l <= r :

            eat = (l + r) // 2 
            
            tt = 0

            for i in piles:
                tt +=  math.ceil(i/eat)
            
            if tt <= h:
                res = eat
                r = eat - 1
            elif tt > h:
                l = eat+1
        
        return res 

                