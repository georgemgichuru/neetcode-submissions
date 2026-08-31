# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        # FIX: Initialize to negative infinity so any path sum updates it
        self.max_sum = float('-inf')

        def max_gain(node):
            if not node:
                return 0
            
            # Recursively get the max gain from left and right subtrees
            # Ignore paths with negative sums by taking max with 0
            left = max(max_gain(node.left), 0)
            right = max(max_gain(node.right), 0)

            # Price of the path where the current node is the highest peak
            price_new_path = node.val + left + right
            
            # Update the global maximum path sum found so far
            self.max_sum = max(self.max_sum, price_new_path)

            # For the parent call, a path can only include one child
            return node.val + max(left, right)
        
        max_gain(root)
        return self.max_sum
