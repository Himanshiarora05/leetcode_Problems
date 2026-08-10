class Solution {
public:
// applying reverse INorder
    int sum = 0;
    void Rinorder(TreeNode* root){
        if(root == NULL) return;
        Rinorder(root->right);
        root->val += sum;
        sum = root->val;
        Rinorder(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        Rinorder(root);
        return root;
    }
};