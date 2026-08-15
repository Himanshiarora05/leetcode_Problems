class Solution {
public:
    TreeNode* ios(TreeNode* root){
        TreeNode* succ = root->right;
        while(succ->left != NULL) succ = succ->left;
        return succ;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            //Case 1 : Leaf node
            if(root->left == NULL && root->right == NULL) return NULL;

            //Case2 : Node with one child
            if(root->left == NULL || root->right == NULL){
                if(root->left == NULL) return root->right;
                else return root->left;
            }

            //Case 3 : Node with Two child
        if(root->left != NULL && root->right != NULL){
            //replace the root with its inorder pred/succ
            //after replacing delete the pred/succ
                TreeNode* suc = ios(root);
                root->val = suc->val;
                root->right = deleteNode(root->right , suc->val);
            }

        }
        else if(root->val > key){
            root->left = deleteNode(root->left , key);
        }
        else{ //root->val < key
            root->right = deleteNode(root->right , key);
        }
        return root;
    }
};