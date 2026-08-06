class Solution {
public:
    TreeNode* build(vector<int>& pre, int prelo,int prehi, vector<int>& post , int postlo,int posthi){
        if(prelo> prehi) return NULL;
        TreeNode* root = new TreeNode(pre[prelo]);
        if(prelo == prehi) return root;
        int i = postlo;
        while(post[i] != pre[prelo+1]) i++; //prelo+1 th index element is the root of leftSubtree
        int leftcount = i-postlo+1;   //i hmara last left element pr h
        root->left = build(pre,prelo+1,prelo+leftcount,post,postlo,i);
        root->right = build(pre,prelo+leftcount+1,prehi,post,i+1,posthi-1);
        return root;

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return build(preorder,0,n-1,postorder,0,n-1);
    }
};