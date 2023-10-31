class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        int n = edges.size();
        for(int i=0;i<n;i++)
        {
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }
        int maxpos = 0, maxi = 1;
        for(auto it:mp)
        {
            if(it.second > maxi)
            {
                maxi = it.second;
                maxpos = it.first;
            }
        }
        return maxpos;
    }
};