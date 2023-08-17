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
    bool isSameTree(TreeNode* root, TreeNode* subroot)
    {
        if(root == nullptr && subroot == nullptr)
            return true;
        else if(root == nullptr || subroot == nullptr)
            return false;
        if(root->val != subroot->val)
            return false;
        return isSameTree(root->right,subroot->right)&&isSameTree(root->left,subroot->left);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot==nullptr)
            return true;
        else if(root == nullptr)
            return false;
        
        if(root->val == subRoot->val)
        {
            bool check = isSameTree(root,subRoot);
            if(check)
                return check;
        }
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};