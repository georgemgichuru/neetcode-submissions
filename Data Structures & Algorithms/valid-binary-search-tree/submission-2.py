# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        # So here we pass in a range of min and max as we progress so basically in the right side = min is val and in left side = max is val so we need to guarantee this across the entire tree 
        # to do this we need to have a variable min_val and max_val and function validate
        def validate(node, min_val, max_val):
            if not node:
                return True
            if min_val is not None and node.val <= min_val:
                return False
            if max_val is not None and node.val >= max_val:
                return False
            return validate(node.left, min_val, node.val) and validate(node.right, node.val, max_val)
        return validate(root, None, None)