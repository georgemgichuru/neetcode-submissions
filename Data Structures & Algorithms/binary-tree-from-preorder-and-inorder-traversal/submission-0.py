from typing import List, Optional

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # 1. Map values to their indices in inorder traversal
        in_map = {val: idx for idx, val in enumerate(inorder)}
        preorder_idx = 0
        
        # 2. Indented inside buildTree so it has access to preorder_idx, preorder, and in_map
        def helper(in_left: int, in_right: int) -> Optional[TreeNode]:
            nonlocal preorder_idx

            if in_left > in_right:
                return None
            
            root_val = preorder[preorder_idx]
            preorder_idx += 1
            root = TreeNode(root_val)

            # Fixed: variable name matched to in_map
            mid = in_map[root_val]

            # Build left then right subtree
            root.left = helper(in_left, mid - 1)
            root.right = helper(mid + 1, in_right)

            return root

        # 3. Indented inside buildTree
        return helper(0, len(inorder) - 1)