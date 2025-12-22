class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n = len(text1) 
        m = len(text2)

        memo = {}

        def itr(i1, i2):

            if i1 == n or i2 == m:
                return 0
            key = (i1, i2)
            
            if key in memo:
                return memo[key]

            if text1[i1] == text2[i2]:
                return 1 + itr(i1+1, i2+1)
            
            memo[key] = max(itr(i1, i2+1), itr(i1+1, i2))

            return memo[key]
        
        return itr(0,0)
        