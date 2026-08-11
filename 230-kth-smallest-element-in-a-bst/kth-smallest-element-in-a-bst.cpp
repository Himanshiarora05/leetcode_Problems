class Solution {
public:
    void inorder(vector<int>& ans,TreeNode* root){
        if(root == NULL) return;
        inorder(ans,root->left);
        ans.push_back(root->val);
        inorder(ans,root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;
        vector<int> ans;
        inorder(ans,root);
        return ans[k-1];
    }
};