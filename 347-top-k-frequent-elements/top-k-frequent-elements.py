
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # top k frequent elements. 

        mp = {}

        for num in nums:
            if num not in mp:
                mp[num]  = 0 
            mp[num]+=1
        
        
        pq = []
        for key, values in mp.items():
            heapq.heappush(pq, (-values, key))

        res = []
        while k > 0:
            freq, val = heapq.heappop(pq)
            res.append(val)
            k-=1
        
        return res

        