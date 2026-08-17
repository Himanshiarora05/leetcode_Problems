// class Solution {
// public:
// //putting values in vector of preorder and then making connection 
//     void preorder(TreeNode* root , vector<TreeNode*>& ans){
//         if(root == NULL) return;
//         ans.push_back(root);
//         preorder(root->left,ans);
//         preorder(root->right,ans);

//     }
//     void flatten(TreeNode* root) {
//         vector<TreeNode*> ans; 
//         preorder(root,ans);
//         int n = ans.size();
//         for(int i = 0;i<n-1;i++){
//             ans[i]->right = ans[i+1];
//             ans[i]->left = NULL;
//         }
//     }
// };


class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        root->left = NULL;
        root->right = NULL;
        flatten(l);
        flatten(r);
        root->right = l;
        TreeNode* temp = root;
        while(temp->right) temp = temp->right;
        temp->right = r;
    }
};