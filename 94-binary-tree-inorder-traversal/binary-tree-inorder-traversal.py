# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def intr(self, root,lst):
        if root is None:
            return
        self.intr(root.left, lst)
        lst.append(root.val)
        self.intr(root.right, lst)
    
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        lst = []
        self.intr(root,lst)
        return lst


        
        return lst
        