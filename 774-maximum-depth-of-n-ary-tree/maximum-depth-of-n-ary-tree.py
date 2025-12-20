# Definition for a Node.
# class Node:
#     def __init__(self, val: int = None, children: list['Node'] | None = None):
#         self.val = val
#         self.children = children or []   # make sure it's a list
        

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root:
            return 0
        
        # if leaf, depth is 1
        if not root.children:
            return 1
        
        # 1 (for current node) + max depth among all children
        return 1 + max(self.maxDepth(child) for child in root.children)
