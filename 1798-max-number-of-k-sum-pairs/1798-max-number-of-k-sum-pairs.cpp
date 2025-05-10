class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int l = 0, r = nums.size()-1;
        sort(nums.begin(), nums.end());
        int count = 0;
        while(l<r){
            int temp = nums[l]+nums[r];
            if(temp == k){
                count++;
                l++;
                r--;
            }
            else if(temp<k){
                l++;
            }
            else{
                r--;
            }
        }
        return count;
    }
};