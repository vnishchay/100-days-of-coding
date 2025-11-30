class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        #map
        mp = {}
        for n in nums:
            if n not in mp:
                mp[n]=True
        
        if len(mp) == len(nums):
            return False
        return True