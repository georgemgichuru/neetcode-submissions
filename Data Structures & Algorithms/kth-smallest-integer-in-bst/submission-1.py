# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        # the kth smallest element is basically the kth element after an in-order traversal (left, val, right)
        # What we need to do - put the items in a queue and then put the descentants/children 
        # Go counting and increasing a counter for maybe x and when x is equal to k or we go subtracting from k and if k = 0 we have founf our node and  that is what we print out so we go poping out of the stack
        stack = []
        current = root

        while current or stack:
            while current:
                stack.append(current)
                current = current.left
            current = stack.pop()
            k -= 1
            if k == 0:
                return current.val
            current = current.right
        return -1
