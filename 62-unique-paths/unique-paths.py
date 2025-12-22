class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        memo = {}

        def move(i, j):
            # out of bounds
            if i < 0 or i >= m or j < 0 or j >= n:
                return 0

            if i == m - 1 and j == n - 1:
                return 1

            key = (i, j)
            if key in memo:
                return memo[key]

            right = move(i, j + 1)
            down = move(i + 1, j)

            memo[key] = right + down
            return memo[key]

        return move(0, 0)
