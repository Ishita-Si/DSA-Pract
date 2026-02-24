1# Definition for a binary tree node.
2# class TreeNode(object):
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    def sumRootToLeaf(self, root):
9        
10        def dfs(node, current):
11            if not node:
12                return 0
13            
14            # Build binary number
15            current = current * 2 + node.val
16            
17            # If leaf node
18            if not node.left and not node.right:
19                return current
20            
21            # Traverse left and right
22            return dfs(node.left, current) + dfs(node.right, current)
23        
24        return dfs(root, 0)
25        