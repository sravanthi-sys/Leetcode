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
    int height(TreeNode* root,set<int> st){
        if(root==NULL)return 0;
        int lh=height(root->left,st);
        int rh=height(root->right,st);
        if(st.find(lh-rh)==st.end() || lh==-1 || rh==-1)return -1;
        return 1+max(rh,lh);
    }
public:
    bool isBalanced(TreeNode* root) {
        set<int>st={0,1,-1};
        int ans=height(root,st);
        if(ans==-1)return false;
        return true;
    }
};