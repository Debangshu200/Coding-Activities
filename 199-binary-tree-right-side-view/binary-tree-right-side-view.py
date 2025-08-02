# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        # empty list
        res = []
        #intializing deque with root node
        q = collections.deque([root])

        while q:
            rightSide = None
            # length of queue based upon the present values in queue
            qLen = len(q)

            for i in range(qLen):
                #assigning the value of queue to node and thus node is initialized
                node = q.popleft()
                if node:
                    rightSide = node
                    q.append(node.left)
                    q.append(node.right)
                #if node which is rightside node is not empty, then we will append value of node
            if rightSide:
                res.append(rightSide.val)
        return res
        