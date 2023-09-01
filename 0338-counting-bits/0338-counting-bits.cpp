class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int i=0;i<n+1;i++)
        {
            int sum = 0;
            int temp = i;
            while(temp > 0)
            {
                if(temp%2 == 1)
                {
                    sum++;
                }
                temp/=2;
            }
            res[i] = sum;
        }
        return res;
    }
};