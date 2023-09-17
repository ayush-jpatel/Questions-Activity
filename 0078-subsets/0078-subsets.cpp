class Solution {
public:
    void func(vector<int>& nums, vector<vector<int>>& res,vector<int> temp,int pos)
    {
        if(pos == nums.size())
        {
            res.push_back(temp);
            return;
        }
        func(nums,res,temp,pos+1);
        temp.push_back(nums[pos]);
        func(nums,res,temp,pos+1);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        func(nums,res,{},0);
        return res;
    }
};