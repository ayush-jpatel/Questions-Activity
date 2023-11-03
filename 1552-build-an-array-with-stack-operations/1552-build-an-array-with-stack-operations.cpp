class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int count = 1;
        for(int i=0;i<target.size();i++){
            res.push_back("Push");
            if(target[i] != count){
                res.push_back("Pop");
                i--;
            }
            count++;
        }
        return res;
    }
};