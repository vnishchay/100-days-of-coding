class Solution:
    def maxArea(self, h: List[int]) -> int:
        
        l = 0
        r = len(h)-1

        mx = 0

        while l < r :
            
            
            mx = max(min(h[l], h[r])*(r - l) , mx)   
            if h[l]  < h[r]:
                l+=1
            else :
                r -=1 
        return mx 
                

        