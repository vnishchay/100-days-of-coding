# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        max_sum = [-10**18]

        def dfs(node):
            if not node:
                return 0
            
            left_down = max(dfs(node.left), 0)
            right_down = max(dfs(node.right), 0)

            current = node.val + left_down + right_down


            max_sum[0] = max(max_sum[0], current)

            return node.val + max(left_down, right_down)
        
        dfs(root)

        return max_sum[0]


        