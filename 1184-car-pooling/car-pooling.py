class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        # empty seats.
        # num , from , to 
        arr = []
        for val in trips:
            nump, fr, to = val[0], val[1], val[2]
            arr.append([fr, nump])
            arr.append([to, -nump])


        arr.sort()

        total = 0

        for val in arr:
            a, b = val[0], val[1]
            total += b
            if total > capacity:
                return False
        
        return True 
             

        