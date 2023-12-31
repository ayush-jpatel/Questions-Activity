class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0,r = k-1;
        int n = nums.size();
        deque <int> dq{};
        vector<int> res;
        for(int i=0;i<k;i++)
        {
            while(dq.empty()==0 && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        for(int i = k;i<nums.size();i++)
        {
            while(dq.empty()==0 && dq.front() <= (i-k))
                dq.pop_front();
            while(dq.empty()==0 && nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
            res.push_back(nums[dq.front()]);

        }
        return res;
    }
};