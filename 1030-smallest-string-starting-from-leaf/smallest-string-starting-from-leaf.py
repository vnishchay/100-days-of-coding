class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        self.ans = ""
        self.dfs(root, "")
        return self.ans

    def dfs(self, root, current_string):
        # If the current node is none, return
        if not root:
            return

        current_string = chr(root.val + ord('a')) + current_string

        # leaf node
        if not root.left and not root.right:
            if not self.ans or self.ans > current_string:
                self.ans = current_string
        
        self.dfs(root.left, current_string)
        self.dfs(root.right, current_string)