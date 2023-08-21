// find minimum depth of a binary tree
// approach --> a simple traversal to left and right 

class Solution {
public:
    int depth(TreeNode* root)
    {
        if(root == NULL) return INT_MAX;
        if(root->left == NULL && root->right == NULL) return 1;

        int left = depth(root->left);
        int right = depth(root->right);

        return min(left, right) + 1;
    }
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return depth(root);
    }
};