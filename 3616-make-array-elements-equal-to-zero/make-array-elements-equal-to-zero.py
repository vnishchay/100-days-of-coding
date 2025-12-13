class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        # Calculate total sum of all elements
        total_sum = sum(nums)
        valid = 0
        left = 0
        
        # For each position where nums[i] == 0
        for i in range(len(nums)):
            if nums[i] != 0:
                left += nums[i]
                continue
            
            # Calculate right sum for this position
            right = total_sum - left
            
            # Check if left == right (balanced, can go either direction)
            if left == right:
                valid += 2
            # Check if difference is exactly 1 (can go in one direction)
            elif abs(left - right) == 1:
                valid += 1
            
            # Note: Don't add left here since we're only checking zeros
        
        return valid