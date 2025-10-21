/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, TreeNode*> parent;
    void getParents(TreeNode* root){
        if(root == NULL)return ;
        if(root -> left){
            parent[root -> left] = root;
            getParents(root -> left);
        }
        if(root -> right){
            parent[root -> right] = root;
            getParents(root -> right);
        }
    }
    TreeNode* findNode(TreeNode* root, int start){
        if(root == NULL || root -> val == start)return root;
        TreeNode* left = findNode(root -> left, start);
        if(left != NULL)return left;
        TreeNode* right = findNode(root -> right, start);
        if(right != NULL)return right;
        return NULL;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        getParents(root);
        int ans = 0;
        queue<pair<int, TreeNode*>> q;
        TreeNode* node = findNode(root, start);
        // cout << node -> val;
        q.push({0, node});
        unordered_set<TreeNode*> vis;
        vis.insert(node);
        while(!q.empty()){
            int level = q.front().first;
            ans = max(ans, level);
            TreeNode* temp = q.front().second;
            q.pop();
            if(temp -> left != NULL && vis.find(temp -> left) == vis.end()){
                vis.insert(temp -> left);
                q.push({level + 1, temp -> left});
            }
            if(temp -> right != NULL && vis.find(temp -> right) == vis.end()){
                vis.insert(temp -> right);
                q.push({level + 1, temp -> right});
            }
            if(parent[temp] != NULL && vis.find(parent[temp]) == vis.end()){
                vis.insert(parent[temp]);
                q.push({level + 1, parent[temp]});
            }
        }
        return ans;
    }
};