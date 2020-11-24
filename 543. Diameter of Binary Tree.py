# 543. Diameter of Binary Tree.py
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def deepest(self, root):
        if not root:
            return 0
        left, right = 0, 0
        if root.left:
            left = self.deepest(root.left)
        if root.right:
            right = self.deepest(root.right)
        self.result = max(self.result, left+right)
        return max(left, right) + 1
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.result = 0
        _ = self.deepest(root)
        return self.result