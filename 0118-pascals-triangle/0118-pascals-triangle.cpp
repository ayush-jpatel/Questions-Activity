class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> vec(numRows);
        int n = numRows;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
                vec[i].push_back(1);
        }
        for(int i=2;i<n;i++)
        {
            for(int j=1;j<vec[i].size()-1;j++)
            {
                vec[i][j] = vec[i-1][j-1] + vec[i-1][j];
            }
        }
        return vec;
    }
};