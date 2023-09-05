int Solution::maxPathSum(TreeNode* A) {
    if(A == NULL) return 0;
    if(A->left == NULL) return 0;
    if(A->right == NULL) return 0;
    int left = maxPathSum(A->left);
    int right = maxPathSum(A->right);

    return A->data + left + right;

}