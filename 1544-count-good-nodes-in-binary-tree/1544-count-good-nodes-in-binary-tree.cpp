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
    int traverse(TreeNode* root,stack<int>& st )
    {
        int count = 0;
        if(root == nullptr)
            return 0;
        if(st.empty()==1 || root->val>=st.top())
        {
            st.push(root->val);
            count++;
        }
        int x = count+traverse(root->left,st)+traverse(root->right,st);
        if(count == 1)
            st.pop();
        return x;
    }
    int goodNodes(TreeNode* root) {
        stack<int> st;
        if(!root)
            return 0;
        int res = traverse(root, st);
        return res;
    }
};