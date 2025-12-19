# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        ss = []

        def dfs(root, s):

            if not root:
                return  
            
            if not s:
                s = str(root.val)
            else :
                s = s + "->" +  str(root.val) 
            
            if not root.left and not root.right:
                ss.append(s)
                return

            dfs(root.left, s)
            dfs(root.right,s)
        
        dfs(root, "")
        return ss 
            
            
        