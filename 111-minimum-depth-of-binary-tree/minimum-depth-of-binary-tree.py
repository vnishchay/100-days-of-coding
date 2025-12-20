# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        # Empty tree
        if not root:
            return 0

        # Leaf node
        if not root.left and not root.right:
            return 1

        # If one child is missing, ignore it and go down the existing child
        if not root.left:
            return 1 + self.minDepth(root.right)
        if not root.right:
            return 1 + self.minDepth(root.left)

        # Both children exist: take min of both sides
        return 1 + min(self.minDepth(root.left), self.minDepth(root.right))
