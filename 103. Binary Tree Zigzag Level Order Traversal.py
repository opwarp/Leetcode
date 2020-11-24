103. Binary Tree Zigzag Level Order Traversal.py
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.res=[]
    def scanTree(self, root,n):
        if root == None:
            return
        else:
            while len(self.res)-1 < n:
                self.res.append([])
            if n % 2 ==0:
                self.res[n].append(root.val)
            else:
                self.res[n].insert(0, root.val)
            self.scanTree(root.left, n+1)
            self.scanTree(root.right, n+1)
            
    def zigzagLevelOrder(self, root):
        
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        self.scanTree(root, 0)
        return self.res