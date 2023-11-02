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
    void sumtraverse(TreeNode* root, TreeNode* sum){
        if(root  == nullptr)
            return;
        sum->val = root->val;
        if(root->left != nullptr){
            sum -> left = new TreeNode();
            sumtraverse(root->left,sum->left);
            sum->val += sum->left->val;
        }
        if(root->right != nullptr){
            sum ->right = new TreeNode();
            sumtraverse(root->right,sum->right);
            sum ->val += sum->right->val;
        }
        return;
    }
    void numtraverse(TreeNode* root, TreeNode* num){
        if(root==nullptr)   
            return;
        num->val = 1;
        if(root->left != nullptr){
            num ->left = new TreeNode();
            numtraverse(root->left,num->left);
            num->val = num->val + (num->left->val);
        }
        if(root->right != nullptr){
            num ->right = new TreeNode();
            numtraverse(root->right,num->right);
            num->val = num->val + (num->right->val);
        }
        return;
    }
    int traverse(TreeNode* root,TreeNode* sum, TreeNode* num){
        int res = 0;
        if(root ==  nullptr)
            return res;
        cout << root->val <<' ' << sum ->val << ' '<< num->val<< endl;
        // if(root->val * num->val == sum->val)
        if(sum->val/num->val == root->val)
            res++;
        if(root->left != nullptr){
            res += traverse(root->left, sum->left, num-> left);
        }
        if(root->right != nullptr){
            res += traverse(root->right, sum->right, num->right);
        }
        return res;
    }
    int averageOfSubtree(TreeNode* root) {
        TreeNode* sum = new TreeNode();
        TreeNode* num = new TreeNode();
        sumtraverse(root,sum);
        numtraverse(root,num);
        return traverse(root,sum,num);
    }
};