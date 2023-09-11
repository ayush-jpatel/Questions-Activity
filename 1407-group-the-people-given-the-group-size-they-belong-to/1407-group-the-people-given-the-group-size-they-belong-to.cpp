class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<groupSizes.size();i++)
        {
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for(auto it:mp)
        {
            int num = it.second.size()/it.first;
            int pos = 0;
            for(int i=0;i<num;i++)
            {
                vector<int> vec = {};
                for(int j=0;j<it.first;j++)
                {
                    vec.push_back(it.second[pos]);
                    pos++;
                }
                res.push_back(vec);
            }
        }
        return res;
        
    }
};