class Solution {
public:
    void helper(vector<string>& ans, string s, TreeNode* root) {
        if (root == NULL)
            return;
        int x = root->val;
        string a = to_string(x);
        if (root->left == NULL && root->right == NULL) {
            s += a;
            ans.push_back(s);
            return;
        }
        helper(ans, s + a + "->" , root->left);
        helper(ans, s + a + "->" , root->right);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(ans, "", root);
        return ans;
    }
};