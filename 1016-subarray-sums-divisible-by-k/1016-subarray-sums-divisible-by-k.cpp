class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        int ctr = 0;
        for(int i=0;i<n;i++){
            ctr+=((nums[i]%k)+k);
            ctr%=k;
            if(mp[ctr]>0){
                count+=mp[ctr];
                mp[ctr]++;
            }
            else{
                mp[ctr] = 1;
            }
        }
        return count;











        for(int i=0;i<n;i++){
            if(mp[(nums[i]+k)%k]>0){
                count+= mp[nums[i]];
                mp[(nums[i]+k)%k]++;
            }
            else{
                mp[(nums[i]+k)%k] = 1;
            }
            cout << (nums[i]+k)%k << ' ';
        }
        return count;
    }
};