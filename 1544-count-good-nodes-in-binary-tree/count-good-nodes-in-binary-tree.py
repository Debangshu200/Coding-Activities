# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:

        def dfs(node, maxVal):
            # if node is empty/not there - then return 0
            if not node:
                return 0
            #if maxval is greater than node value, then increase res value by 1 and update the maxval
            res = 1 if node.val >= maxVal else 0
            maxVal = max(maxVal, node.val)
            
            #recursively call the dfs function and change the res value depending upon the node value
            res += dfs(node.left, maxVal)
            res += dfs(node.right, maxVal)
            #return the res value
            return res
        # pass the parameters root and it's value
        return dfs(root, root.val)
