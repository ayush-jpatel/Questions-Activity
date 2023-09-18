class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        vector<pair<int,int>> vec;
        if(mat.size() == 0)
            return res;
        for(int i=0;i<mat.size();i++)
        {
            int count = 0;
            for(int j=0;j<mat[0].size() && mat[i][j] != 0;j++)
            {
                count += mat[i][j];
            }
            vec.push_back({count,i});
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<k;i++)
        {
            res.push_back(vec[i].second);
        }
        return res;
    }
};