class Solution {
public:
    void inorder(vector<int>& ans,TreeNode* root){
        if(root == NULL) return;
        inorder(ans,root->left);
        ans.push_back(root->val);
        inorder(ans,root->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> ans;
        inorder(ans,root);
        int l = 0 , r = 0;
        while(ans[l] != low) l++;
        while(ans[r] != high) r++; 
        int sum = 0;
        for(int i = l;i<=r;i++){
            sum += ans[i];
        }
        return sum;
    }
};