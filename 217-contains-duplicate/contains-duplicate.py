class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        #map
        mp = {}
        for n in nums:
            if n not in mp:
                mp[n]=True
            else:
                return True
        return False