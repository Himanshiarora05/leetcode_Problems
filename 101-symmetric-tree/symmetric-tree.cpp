class Solution {
public:
    bool helper(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;

        if(p->val != q->val) return false;

        return helper(p->left, q->right) && helper(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return helper(root->left, root->right);
    }
};