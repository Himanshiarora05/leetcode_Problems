class Solution {
public:
    TreeNode* findNode(TreeNode* root, int start){
        if(root == NULL) return NULL;
        if(root->val == start) return root;
        TreeNode* left = findNode(root->left, start);
        if(left != NULL) return left;
        return findNode(root->right, start);
    }

    void mark(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& mp){
        if(root == NULL) return;
        if(root->left) mp[root->left] = root;
        if(root->right) mp[root->right] = root;
        mark(root->left, mp);
        mark(root->right, mp);
    }

    int amountOfTime(TreeNode* root, int start){
        //step 1 : exactly find where is that node
        TreeNode* first = findNode(root, start);

        //step 2 : make a unordered_map in which find parent and child relation
        unordered_map<TreeNode*,TreeNode*> mp;
        mark(root, mp);

        //step 3 : make a set where we will check we have infected(visited)
        unordered_set<TreeNode*> visited;
        visited.insert(first);

        //step 4 : make a queue which will have pair<Node, level>
        queue<pair<TreeNode*,int>> q;
        q.push({first, 0});

        int time = 0;

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            time = max(time, level);

            if(node->left && visited.find(node->left) == visited.end()){   //not infected
                visited.insert(node->left);
                q.push({node->left, level+1});
            }

            if(node->right && visited.find(node->right) == visited.end()){   //not infected
                visited.insert(node->right);
                q.push({node->right, level+1});
            }

            if(mp.find(node) != mp.end()){
                TreeNode* parent = mp[node];

                if(visited.find(parent) == visited.end()){
                    visited.insert(parent);
                    q.push({parent, level+1});
                }
            }
        }

        return time;
    }
};