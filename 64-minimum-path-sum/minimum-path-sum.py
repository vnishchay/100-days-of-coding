class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:

        m , n = len(grid),  len(grid[0])

        memo = {}

        def move(i, j ):
            
            if i < 0 or i >= m or j < 0 or j >= n:
                return 10**17
            
            val = grid[i][j]

            key = (i, j)

            if  i == m-1 and j == n-1 :
                return val

            if key in memo:
                return memo[key]
            
            if i == m-1 :
                return val + move(i, j+1)
            
            if j == n-1:
                return val + move(i+1, j)

            x = val + move(i, j+1) 
            y = val +  move(i+1, j)

            memo[key] = min(x, y)
            
            return memo[key]
    

        return move(0, 0)

        