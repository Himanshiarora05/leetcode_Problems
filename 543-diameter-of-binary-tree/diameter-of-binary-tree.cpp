/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxDia = 0;
    int level(TreeNode* root) {
        if (root == NULL) return 0;
        int lh = level(root->left);   //traverse to each node
        int rh = level(root->right);
        int dia = lh + rh;            //maximum height will be sum of level of both LST , RST
        maxDia = max(dia, maxDia);   
        return 1 + max(lh, rh);     //calculate levels
    }
    int diameterOfBinaryTree(TreeNode* root) {
        level(root);
        return maxDia;
    }
};