class Solution {
public:
    int helper(TreeNode* root , long long target){
        if(root == NULL) return 0;
        int count = 0;
        if(root->val == target) count++;

        count += helper(root->left , target-(root->val));
        count += helper(root->right , target-(root->val));
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
         
         return helper(root,targetSum) 
                + pathSum(root->left , targetSum) + pathSum(root->right , targetSum) ; 
                //visit every node
    }
};