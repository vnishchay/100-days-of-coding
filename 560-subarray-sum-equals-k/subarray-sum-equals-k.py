class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        prefix = 0
        mp = defaultdict(int)
        mp[0]=1

        for num in nums:
            prefix += num
            count += mp[prefix - k]
            mp[prefix]+=1
            
        return count
