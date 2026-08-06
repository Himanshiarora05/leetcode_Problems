class Solution {
public:
    TreeNode* build(vector<int>& post, int postlo, int posthi, vector<int>& in,int inlo, int inhi) {
        if (postlo > posthi)  return NULL;
        TreeNode* root = new TreeNode(post[posthi]);
        if (postlo == posthi) return root;
        int i = inlo;
        while (i <= inhi) {    //finding root in inorder  
            if (in[i] == post[posthi]) break;
            i++;
        }
        int leftCount = i - inlo;  //no.of elements in left of root
        int rightCount = inhi - i;
        root->left = build(post, postlo , postlo + leftCount -1, in, inlo, i - 1);
        root->right = build(post, postlo + leftCount , posthi-1, in, i + 1, inhi);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        return build(postorder, 0, n - 1, inorder, 0, n - 1);
    
    }
};