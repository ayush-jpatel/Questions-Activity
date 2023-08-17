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
        return 1+max(depth(root->right),depth(root->left));
    }
    void traverse(TreeNode* root, vector<int>& vec, int dep)
    {
        if(root == nullptr)
            return;
        traverse(root->left,vec,dep+1);
        vec[dep] = root->val;
        traverse(root->right,vec,dep+1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        int d = depth(root);
        vector<int> vec(d,0);
        traverse(root,vec,0);
        return vec;
    }
};