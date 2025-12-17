class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        counts = Counter(nums)
        return [key for key, value in counts.items() if value > 1 ]
        