class Solution {
public:
    // coordinates
    int countPairs(vector<vector<int>>& coord, int k) {
        int n = coord.size();
        map<pair<int,int>,int> mp;
        // unordered_map<pair<int,int>,int> mp;
        int count  = 0;
        for(int i=0;i<n;i++)
        {
            int x1 = coord[i][0];
            int y1 = coord[i][1];
            for(int j=0;j<=k;j++)
            {
                int x2 = x1^j;
                int y2 = y1^(k-j);
                count+= (mp[{x2,y2}]);
            }
            mp[{coord[i][0],coord[i][1]}]++;
        }
        return count;
    }
};