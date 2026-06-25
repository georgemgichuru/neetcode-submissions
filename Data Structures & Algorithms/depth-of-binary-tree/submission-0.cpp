class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        // Find the max depth of the left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // Return 1 plus the maximum of the two depths
        return 1 + max(leftDepth, rightDepth);
    }
};