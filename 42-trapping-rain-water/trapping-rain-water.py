class Solution:
    def trap(self, h: List[int]) -> int:
        l = 0
        r = len(h)-1

        lm =0
        rm = 0
        total = 0

        while l < r:
            hl = h[l]
            hr = h[r]
            if h[l] <= h[r]:
                lm = max(lm, hl)
                total += lm - hl
                l+=1
            else :
                rm = max(rm, hr)
                total+= rm - hr 
                r-=1
        return total 

            

            





        