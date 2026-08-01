class Solution {
public:
    int levels(TreeNode* root) {
        if (root == NULL)  return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    void nthLevel(TreeNode* root, int currLevel, int level, vector<int>& ans) {
        if (root == NULL)  return;
        if (currLevel == level) {
            ans.push_back(root->val);
            return;
        }
        nthLevel(root->left, currLevel + 1, level, ans);
        nthLevel(root->right, currLevel + 1, level, ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> fans;
        int n = levels(root);
        if (root == NULL)
            return fans;
        for (int i = 1; i <= n; i++) {
            vector<int> ans;
            nthLevel(root, 1, i, ans);
            fans.push_back(ans);
        }
        return fans;
    }
};