class Solution {
public:
    void inorder(vector<int>& ans,TreeNode* root){
        if(root == NULL) return;
        inorder(ans,root->left);
        ans.push_back(root->val);
        inorder(ans,root->right);
    }
    TreeNode* build(vector<int>& nums, int lo , int hi){
        if(lo>hi) return NULL;
        int mid = lo+(hi-lo)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums,lo,mid-1);
        root->right = build(nums,mid+1,hi);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(ans,root);
        return build(ans,0,ans.size()-1);
    }
};