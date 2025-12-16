class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # nums
        # k 

        c = Counter(nums)
        hp = []

        for key, value in c.items():
            print(key, value)
            heapq.heappush(hp, [value, key])

            if len(hp) > k :
                heapq.heappop(hp)
        
        return list([ value for key, value in hp ])

        
        

        

            
        