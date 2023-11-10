class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> mp;
        int prev;
        for(int i=0;i<adjacentPairs.size();i++){
            mp[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            mp[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        for(auto it: mp){
            if(it.second.size() == 1){
                prev = it.first;
                break;
            }
        }
        int pprev; //pprev is element prior to prev
        vector<int> res;
        res.push_back(prev);
        pprev = prev;
        prev = mp[prev][0];
        res.push_back(prev);
        while(mp[prev].size() == 2){
            if(mp[prev][0] == pprev){
                pprev = prev;
                prev = mp[prev][1];
            }
            else{
                pprev = prev;
                prev = mp[prev][0];
            }
            res.push_back(prev);
        }
        return res;
        
    }
};