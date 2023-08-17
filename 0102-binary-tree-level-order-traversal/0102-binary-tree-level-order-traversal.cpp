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
public:
    int depth(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        return 1+max(depth(root->left),depth(root->right));
    }
    void traverse(TreeNode* root, vector<vector<int>>& vec,int dep)
    {
        if(!root)
            return;
        traverse(root->left,vec,dep+1);
        vec[dep].push_back(root->val);
        traverse(root->right,vec,dep+1);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int d = depth(root);
        vector<vector<int>> vec(d);
        traverse(root,vec,0);
        return vec;
    }
};