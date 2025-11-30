class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        for inx, num in enumerate(nums):
            if target - num in mp:
                return [inx, mp[target - num]]
            mp[num]=inx
    

        