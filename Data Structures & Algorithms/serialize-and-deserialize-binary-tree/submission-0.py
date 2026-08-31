# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Codec:
    
    # Encodes a tree to a single string.
    def serialize(self, root: Optional[TreeNode]) -> str:
        def helper(node):
            if not node:
                vals.append('N')
                return
            vals.append(str(node.val))
            helper(node.left)
            helper(node.right)
        
        vals = []
        helper(root)
        return ','.join(vals)
            # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:
        vals = iter(data.split(','))

        def helper():
            val = next(vals)
            if val == 'N':
                return None
            node = TreeNode(int(val))
            node.left = helper()
            node.right = helper()

            return node

        return helper()