class Solution {
public:
    void recurse(vector<int>& candidates, vector<vector<int>>& res,vector<int> currvec,int target,int pos)
    {
        if(target == 0)
        {
            res.push_back(currvec);
            return;
        }
        if(target < 0 || pos >= candidates.size())
            return;
        currvec.push_back(candidates[pos]);
        recurse(candidates,res,currvec,target-candidates[pos],pos);
        currvec.pop_back();
        recurse(candidates,res,currvec,target,pos+1);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        recurse(candidates,res,{},target,0);
        return res;
    }
};