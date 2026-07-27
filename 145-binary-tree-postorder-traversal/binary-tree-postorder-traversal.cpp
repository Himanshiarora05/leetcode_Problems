class Solution {
public:
    void helper(vector<int>& ans, TreeNode* root) {
        if(root == NULL) return ;
        helper(ans, root->left);
        helper(ans, root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(ans, root);
        return ans;
    }
};