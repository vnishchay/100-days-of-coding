# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        ans = 0

        def dfs(node, cur_min, cur_max):
            nonlocal ans
            if not node:
                return

            # update answer using current node vs path min/max
            ans = max(
                ans,
                abs(node.val - cur_min),
                abs(node.val - cur_max)
            )

            # update path min/max and go deeper
            cur_min = min(cur_min, node.val)
            cur_max = max(cur_max, node.val)

            dfs(node.left, cur_min, cur_max)
            dfs(node.right, cur_min, cur_max)

        dfs(root, root.val, root.val)
        return ans
