class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.count(target-nums[i])>0)
            {
                vector<int> vec;
                vec.push_back(mp[target-nums[i]]);
                vec.push_back(i);
                return vec;
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};