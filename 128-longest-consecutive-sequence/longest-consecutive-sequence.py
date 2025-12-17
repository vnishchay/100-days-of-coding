class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        arr = set(nums)
        best = 0

        for num in arr:
            if num-1 not in arr:
                x = num 
                streak = 1

                while x +1 in arr:
                    streak+=1 
                    x +=1
                
                best = max(best, streak)
        
        return best


            

        