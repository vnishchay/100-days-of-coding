# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def dfs(node: Optional[TreeNode], val: int) -> int:
            if not node:
                return 0

            # shift left (multiply by 2) and add current bit
            val = (val << 1) | node.val

            # if leaf, return this path's value
            if not node.left and not node.right:
                return val

            # sum from left and right subtrees
            return dfs(node.left, val) + dfs(node.right, val)

        return dfs(root, 0)
