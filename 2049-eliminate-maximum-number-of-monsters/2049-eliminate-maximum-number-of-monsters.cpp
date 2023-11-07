class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> cycles(dist.size());
        for(int i=0;i<cycles.size();i++){
            cycles[i] = dist[i]/speed[i];
            if(dist[i]%speed[i])
                cycles[i]++;
        }
        sort(cycles.begin(),cycles.end());
        for(int i=0;i<cycles.size();i++){
            if(cycles[i]<=i){
                return i;
            }
        }
        return dist.size();
    }
};