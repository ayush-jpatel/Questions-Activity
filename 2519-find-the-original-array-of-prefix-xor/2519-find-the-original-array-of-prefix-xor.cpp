class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        long long int n = pref.size();
        vector<int> res;
        res.push_back(pref[0]);
        for(int i=1;i<n;i++)
        {
            res.push_back(pref[i]^pref[i-1]);
        }
        return res;
    }
};