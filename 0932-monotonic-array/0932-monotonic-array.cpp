class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool inc = true;
        if(n == 1)
            return true;
        int pos = 1;
        while(pos<n && nums[pos]==nums[pos-1])
            pos++;
        if(pos == n)
            return true;
        else
        {
            inc = nums[pos-1]<nums[pos];
        }
        if(inc)
        {
            for(int i=1;i<n;i++)
            {
                if(nums[i-1]>nums[i])
                    return false;
            }
            return true;
        }
        else
        {
            for(int i=1;i<n;i++)
            {
                if(nums[i-1]<nums[i])
                    return false;
            }
            return true;
        }
    }
};