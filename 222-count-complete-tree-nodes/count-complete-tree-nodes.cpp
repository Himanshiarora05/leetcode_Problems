class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int left = 0, right = 0;
        TreeNode* l = root;
        TreeNode* r = root;
        while (l) {
            left++;
            l = l->left;
        }
        while (r) {
            right++;
            r = r->right;
        }
        // Perfect binary tree
        if (left == right)
            return (1 << left) - 1;
        // Not perfect
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};