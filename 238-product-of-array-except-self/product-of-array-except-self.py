class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        pre = [1] * n   # prefix products
        suf = [1] * n   # suffix products
        res = [0] * n

        # build prefix: pre[i] = product of nums[0..i-1]
        for i in range(1, n):
            pre[i] = pre[i-1] * nums[i-1]

        # build suffix: suf[i] = product of nums[i+1..n-1]
        for i in range(n-2, -1, -1):
            suf[i] = suf[i+1] * nums[i+1]

        # result = prefix * suffix
        for i in range(n):
            res[i] = pre[i] * suf[i]

        return res
