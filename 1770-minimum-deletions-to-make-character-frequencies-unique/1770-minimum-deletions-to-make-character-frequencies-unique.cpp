class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int> mp;
        int sum = 0;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        unordered_map<int,int> freq;
        for(auto it:mp)
        {
            freq[it.second]++;
        }
        for(auto it:freq)
        {
            //first has value of size, second has frequency of size
            while(it.first>0 && it.second > 1)
            {
                int low = it.first-1;
                while(low>0 && freq[low]!= 0)
                {
                    low--;
                }
                freq[low]++;
                it.second--;
                sum += (it.first - low);
            }
        }
        return sum;

    }
};