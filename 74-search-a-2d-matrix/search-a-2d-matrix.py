class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:

        # it is ever increasing. 

        # len(m * n)
        # m // n , m % n 

        l = 0 
        m= len(matrix)
        n = len(matrix[0])
        r = len(matrix) * len(matrix[0]) -1

        while l <= r : 
            mid = (l + r ) // 2 
            x = int(mid // n) 
            y = int(mid % n) 
            val  = matrix[x][y]
            if  val > target :
                r = mid -1 
            elif val < target : 
                l = mid + 1
            else :
                return True
        
        return False
        