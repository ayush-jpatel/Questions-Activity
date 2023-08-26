class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
        int count = 0;
        int prev = INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            if(pairs[i][1] < prev)
            {
                count++;
                prev = pairs[i][0];
            }
        }
        return count;
    }
};