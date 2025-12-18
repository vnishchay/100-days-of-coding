class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res_set = []
        target = 0
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:
                continue

            l = i+1
            r = len(nums)-1

            while l < r :
                s = nums[l] + nums[r] + nums[i]
                if target > s:
                    l+=1
                elif target < s:
                    r-=1
                else :
                    res_set.append([nums[i], nums[l], nums[r]])
                    l+=1
                    r-=1
                
                    while l < r and nums[l] == nums[l-1]:
                        l+=1

                    while r > l and nums[r] == nums[r+1]:
                        r-=1

        return res_set
            

        