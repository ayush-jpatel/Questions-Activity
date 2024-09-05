class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int remsum = (m+n)*mean;
        vector<int> res;
        for(int i=0;i<m;i++){
            remsum -= rolls[i];
        }
        int val = remsum/n;
        int extra = remsum - val*n;
        // cout << extra;
        if(remsum < n || remsum > 6*(n)){
            return res;
        }
        else{
            for(int i=0;i<n;i++){
                res.push_back(val);
                if(extra){
                    res.back()++;
                    extra--;
                }
                // remsum -= res.back();
            }
        }
        // if(remsum){
        //     res.back()++;
        // }
        return res;

    }
};








