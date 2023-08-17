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
    bool checkValid(TreeNode* root, long long left, long long right){
        if(root == nullptr){
            return true;
        }
        if(root->val <= left || root->val >= right){
            return false;
        }
        return checkValid(root->left,left,root->val)&&checkValid(root->right,root->val,right);

    }
    bool isValidBST(TreeNode* root) {
        long long left = 0, right = 0;
        return checkValid(root,LLONG_MIN,LLONG_MAX);
    }
};