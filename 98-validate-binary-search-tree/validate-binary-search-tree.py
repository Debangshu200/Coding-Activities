# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        #It is a helper function
        #Here node represents the parent of the tree(subtree)
        def valid(node, left, right):
            if not node:
                return True
            if not (node.val < right and node.val > left):
                return False
            # we are recursively calling the helper function
            # we are interested that in the, right subtree the values will be greter than root and on left it should be less than root's value
            return (valid(node.left, left, node.val) # node.left is left subtree and left is it left child which we want changes over every child node and right node should be fixed(+inf)  
                    and 
                    valid(node.right, node.val, right)) # node.right is right subtree and left node(node.val) should be fixed(-inf) and right value should be changing 
        return valid(root, float("-inf"), float("inf")) 