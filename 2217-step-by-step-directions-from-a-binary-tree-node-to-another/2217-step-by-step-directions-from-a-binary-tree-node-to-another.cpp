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
    string path(TreeNode* root, int d, string &str){
        if(root == nullptr) return "";
        if(root->val == d)  return str;
        // str += 'L';
        str.push_back('L');
        string a = path(root->left,d,str);
        str.pop_back();
        str.push_back('R');
        string b = path(root->right,d,str);
        str.pop_back();
        if(a!= ""){
            return a;
        }   
        if(b!= ""){
            return b;
        }
        return "";
        
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // string str = path(root,startValue,destValue);
        string s = "";
        string a = path(root,startValue,s);
        string b = path(root,destValue,s);

        int ptr = 0;
        // cout << a << ' ' << b << endl;
        int x = a.length(), y = b.length();
        for(ptr=0;ptr<min(x,y);ptr++){
            // ptr = i;
            if(a[ptr]!=b[ptr]){
                break;
            }
        }
        string str = "";
        for(int i=0;i<(x-ptr);i++){
            str += 'U';
            // str.append('U');
        }
        // cout << x << ' ' << y << ' ' << ptr << endl;
        str = str + b.substr(ptr,(y-ptr));
        return str;
    }

};