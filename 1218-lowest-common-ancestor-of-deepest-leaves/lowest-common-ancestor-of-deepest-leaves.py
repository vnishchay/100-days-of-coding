class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        def dfs(node):
            if not node:
                return (0, None)      # depth, lca

            ld, lca_l = dfs(node.left)
            rd, lca_r = dfs(node.right)

            if ld > rd:
                return (ld + 1, lca_l)
            elif rd > ld:
                return (rd + 1, lca_r)
            else:
                return (ld + 1, node)

        _, lca = dfs(root)
        return lca
