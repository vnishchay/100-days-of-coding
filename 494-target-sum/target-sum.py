from typing import List
from functools import lru_cache

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        @lru_cache(None)
        def backtrack(i: int, total: int) -> int:
            if i == len(nums):
                return 1 if total == target else 0
            # Add current number
            ways = backtrack(i + 1, total + nums[i])
            # Subtract current number
            ways += backtrack(i + 1, total - nums[i])
            return ways
        
        return backtrack(0, 0)
