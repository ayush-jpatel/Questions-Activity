class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<long long int,long long int> map;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            map[arr[i]] = 1;
        }
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j] == 0 && map.count(arr[i]/arr[j])>0)
                {
                    map[arr[i]] += (map[arr[j]]*(map[arr[i]/arr[j]]));
                }
            }
        }
        long long int res = 0;
        for(int i=0;i<n;i++)
        {
            // cout << map[arr[i]] << ' ';
            res += map[arr[i]];
        }
        return res%(1000000007);
    }
};