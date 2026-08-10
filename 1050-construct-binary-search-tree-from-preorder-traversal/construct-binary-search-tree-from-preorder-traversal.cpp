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
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root = new TreeNode(pre[0]);
        for(int i = 1;i<pre.size();i++){
            insertIntoBST(root,pre[i]);
        }
        return root;
    }
};