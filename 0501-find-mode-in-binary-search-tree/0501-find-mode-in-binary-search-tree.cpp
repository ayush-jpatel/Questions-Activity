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
    unordered_map<int,int> mp;
    void traverse(TreeNode* root){
        if(root == nullptr)
            return;
        mp[root->val]++;
        traverse(root->left);
        traverse(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        int maxi = mp[root->val],maxpos = root->val;
        for(auto it: mp){
            if(it.second>maxi){
                maxpos = it.first;
                maxi = it.second;
            }
        }
        vector<int> vec;
        for(auto it: mp){
            if(it.second==maxi){
                vec.push_back(it.first);
            }
        }
        return vec;
    }
};