class Solution:
    def climbStairs(self, n: int) -> int:

        self.dp = {}

        def recur(n):
            if n <= 0:
                return 1
            
            if n in self.dp:
                return self.dp[n]

            if n ==1 : 
                return recur(n-1)

            self.dp[n] = recur(n-1) + recur(n-2)

            return self.dp[n]
        
        return recur(n)
        