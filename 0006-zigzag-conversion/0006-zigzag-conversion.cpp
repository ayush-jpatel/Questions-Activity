class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> vec(numRows);
        int n = numRows;
        int pos = 0;
        int sign = 1;
        if(n == 1)
            return s;
        for(int i=0;i<s.length();i++)
        {
            vec[pos].push_back(s[i]);
            pos += sign;
            if(pos >= n)
            {
                sign = -1;
                pos = n - 2;
            }
            else if(pos <= -1)
            {
                sign  = 1;
                pos = 1;
            }
        }
        string res = "";
        for(int i=0;i<vec.size();i++)
        {
            for(int j=0;j<vec[i].size();j++)
            {
                res.push_back(vec[i][j]);
            }
        }
        return res;
    }
};