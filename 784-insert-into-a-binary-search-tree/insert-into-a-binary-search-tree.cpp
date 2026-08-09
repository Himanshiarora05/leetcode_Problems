class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        else if(root->val < val){
          root->right = insertIntoBST(root->right , val);
        }
        else root->left = insertIntoBST(root->left , val);   //attaching new node to the left
        return root;
    }
};