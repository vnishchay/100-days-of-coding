class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:

        sum = 0
        
        for num in apple:
            sum += num 
        
        capacity = sorted(capacity)
        capacity = reversed(capacity)

        for index, cap in enumerate(capacity):
            sum -= cap
            if sum <= 0:
                return index+1
            
        return -1 
        