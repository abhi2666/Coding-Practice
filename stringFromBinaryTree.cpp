class Solution {
public:

    void generateString(string&res, TreeNode*root)
    {
        if(root == NULL) return;
        res += to_string(root->val);
        // while going left put ( first  
        if(root->left || root->right)
        {
            res += "(";
            generateString(res, root->left);
            res += ")";
        }
        if(root->right)
        {
            res += "(";
            generateString(res, root->right);
            res += ")";
        }
    }
    string tree2str(TreeNode* root) {
        string res;
        generateString(res, root);
        return res;
    }
};