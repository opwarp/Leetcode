# 124. Binary Tree Maximum Path Sum.py 

# dp: O(n) n for node number

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        res = -float('inf')
        def getMaxChild(node):
            if not node:
                return -float('inf')
            nonlocal res
            maxL = getMaxChild(node.left)
            maxR = getMaxChild(node.right)
            res = max(res, node.val, maxL+node.val, maxR+node.val, maxR+maxL+node.val)
            return max(node.val, maxL+node.val, maxR+node.val)
        getMaxChild(root)
        return res