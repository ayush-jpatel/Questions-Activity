class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.length();
        unordered_map<char,int> freq;
        for(auto ch:word){
            freq[ch]++;
        }
        int mindeleted = INT_MAX;
        for(auto it1:freq){
            int deleted = 0, mf = it1.second;
            for(auto it:freq){
                //it1.second is minfreq we decided.
                int f = it.second;
                if(f<mf){
                    deleted += f;
                }
                else if(mf+k < f){
                    deleted += (f - mf - k);
                }
            }
            mindeleted = min(mindeleted, deleted);
        }

        return mindeleted;
    }
};