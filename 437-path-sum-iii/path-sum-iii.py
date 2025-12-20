# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def pathSum(self, root: Optional[TreeNode], target: int) -> int:
        prefix = {0: 1}  # sum 0 seen once (empty path)
        cnt = 0

        def dfs(node, cur_sum):
            nonlocal cnt
            if not node:
                return

            cur_sum += node.val

            # number of paths ending here with sum == target
            cnt += prefix.get(cur_sum - target, 0)

            # add current prefix sum
            prefix[cur_sum] = prefix.get(cur_sum, 0) + 1

            dfs(node.left, cur_sum)
            dfs(node.right, cur_sum)

            # remove current prefix sum (backtrack)
            prefix[cur_sum] -= 1

        dfs(root, 0)
        return cnt
